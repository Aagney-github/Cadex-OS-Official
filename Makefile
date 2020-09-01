# Cadex OS Build Makefile for i386 architecture.
include Makefile.config

LIBRARY_SOURCES=$(wildcard library/*.c)
LIBRARY_HEADERS=$(wildcard library/*.h)
USER_SOURCES=$(wildcard usr/*.c)
SYSTEM_BIN_SOURCES=$(wildcard bin/*.c)
USER_PROGRAMS=$(USER_SOURCES:c=exe)
SYSTEM_BIN_FILES=$(SYSTEM_BIN_SOURCES:c=exe)
KERNEL_SOURCES=$(wildcard kernel/*.[chS])

all: clear clean cadex.iso success # run # Uncomment this run command to run the OS after you've built the OS

run: cadex.iso
					# See https://github.com/opencreeck/Cadex-OS-Official/wiki/WSLCompat
	qemu-system-i386.exe -cdrom cadex.iso -m size=500M -drive 'file=disk.img,format=qcow2' -device isa-debug-exit,iobase=0xf4,iosize=0x04 || qemu-system-i386 -cdrom cadex.iso -m size=500M -drive 'file=disk.img,format=raw' -hda disk.img -device isa-debug-exit,iobase=0xf4,iosize=0x04

debug: cadex.iso hddimg
					# See https://github.com/opencreeck/Cadex-OS-Official/wiki/WSLCompat
	qemu-system-i386.exe -cdrom cadex.iso -hda disk.img -s -S -device isa-debug-exit,iobase=0xf4,iosize=0x04 & || qemu-system-i386 -cdrom cadex.iso -hda disk.img -s -S  &

hddimg:
	qemu-img create -f qcow2 disk.img 1G

library/baselib.a: $(LIBRARY_SOURCES) $(LIBRARY_HEADERS)
	@cd library && make

$(USER_PROGRAMS): $(USER_SOURCES) library/baselib.a $(LIBRARY_HEADERS)
	@cd usr && make

$(SYSTEM_BIN_FILES): $(SYSTEM_BIN_SOURCES) library/baselib.a $(LIBRARY_HEADERS)
	@cd bin && make

kernel/cadex.img: $(KERNEL_SOURCES) $(LIBRARY_HEADERS)
	@cd kernel && make

image: kernel/cadex.img $(USER_PROGRAMS) $(SYSTEM_BIN_FILES)
	@rm -rf image
	@mkdir image image/boot image/usr image/data image/usr/bin image/bin image/sys image/usr/share image/etc image/var image/tmp
	@cp kernel/cadex.img image/boot
	@cd basefs && make
	@cp $(USER_PROGRAMS) image/usr/bin
	@cp $(SYSTEM_BIN_FILES) image/bin
	@head -2000 /usr/share/dict/words > image/data/words

cadex.iso: image
	@${ISOGEN} -input-charset utf-8 -iso-level 2 -J -R -o $@ -b boot/cadex.img image
	@echo "[BUILD] Building ISO image..."
success:
	@echo "----------------------------------------------------"
	@echo "Successfully compiled kernel. Type 'make run' to run"
	@echo "----------------------------------------------------"
clean:
	@rm -rf cadex.iso image
	@cd kernel && make clean
	@cd library && make clean
	@cd usr && make clean
	@cd bin && make clean

clear:
	@clear
