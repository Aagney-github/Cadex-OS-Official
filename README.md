# The Cadex OS

Cadex OS is a Unix-like based operating system targeting x86 systems. This project is based on the [basekernel](https://github.com/dthain/basekernel) project

If you want to build apps for something _**different**_ than Windows, Linux, or MacOS,
Cadex OS may be a good place to try out your new ideas. Cadex OS has all the libraries and APIs to create your own app.

Cadex OS can boot an Intel PC-compatible virtual machine in 32-bit protected
mode, with support for VESA framebuffer graphics, ATA hard disks, ATAPI optical
devices, process management, memory protection, small graphics, a standard libc, c++ language support and basic filesystem (DFS).
From there, it's your job to write user-level programs and expand the system.

## Some useful info about Cadex OS
 - Cadex OS supports a small subset of libc, and more functions and libraries from libc need to be implemented.
 - Cadex OS has a small BASIC interpreter that can be used to write small programs.
 - Cadex OS supports graphical and text-based applications
 - Cadex OS uses ELF as the binary format
 - Cadex OS supports modules, but it is still in development and is not in the Makefile
 - Cadex OS will be useful if you are a beginner in C programming lanhguage and you want to write small programs.
 - Cadex OS has a small graphics library called TrueGL. TrueGL is also a UI library
 - Cadex OS has many useful string functions defined at `library/string.c`
 - Cadex OS uses some code from Musl libc for the libc in Cadex OS. Libraries that are from Musl libc should contain a license header on the top.
 - Cadex OS supports C++ apps and thus it has a C++ library. The C++ library is implemented as a header-only library (Note that the C++ library used in this project is completely written from scratch and thus it may not be complaint to the C++ standards)
 - Cadex OS is targeted on x86 systems and if you want it to run on ARM-based systems, you will need to rewrite the bootloader and some kernel-side code

This repo was made by HyperCreeck and actively maintained by HyperCreeck and contributors.

To learn more, see the __[Cadex OS Wiki](http://cadex-os-wiki.rf.gd).__

# Notable components
 * ***kshell***: A small but efficient shell implemented on the kernel space
 * ***DiM***: A very small text editor
 * ***pam***: A package manager for Cadex OS (not implemented)
 * ***CaSh**: A small bash-like shell implemented on the userspace

# Project structure
 * ***apps***: Sources for C++ apps
 * ***basefs***: Base filesystem folder that goes into the ISO image
 * ***bin***: Sources for standard system binaries (i.e, `/bin` folder)
 * ***docs***: Documentation about used drivers and APIs
 * ***include***: Header files for libc and libcxx libraries
 * ***kernel***: The core kernel source
 * ***libc***: Source files for libc and libcxx (This includes the standard system libraries)
 * ***scripts***: Scripts for generating ramfs image and other purposes
 * ***usr***: Programs that go into `/usr/bin` folder

## Instructions for building Cadex OS

#### Installing the toolchain

For building Cadex OS, you need to install the toolchain. 
Building toolchain from source is recommended, but prebuilt binaries are available.
 - If you are building toolcahin from source, visit [this]http://cadex-os-wiki.rf.gd/Toolchain#Building) site
 - If you don't wish to build the toolchain from source (not recommended), you can download prebuilt binaies for ubuntu from [here](https://hypercreeck.cf/cadex/os/toolchain.php)
 
#### Building the OS

If you are building on a Linux-x86 machine
and have the QEMU installed, run:

```
git clone https://github.com/opencreeck/Cadex-OS-Official
cd Cadex-OS-Official
make
qemu-system-i386 -cdrom cadex.iso
```

And you should see something like this:

<img src=docs/img/screenshot.png align=center>

After some initial boot messages, you will see the kshell prompt.
This allows you to take some simple actions before running the first
user-level program.  For example, read the boot messages to see
which atapi unit the cdrom is mounted on.  Then, use the `mount` command
to mount the cdrom filesystem on that unit:

<pre>
mount atapi <unit> cdromfs
</pre>

Use the `ls` command to examine the root directory:

<pre>
ls /
</pre>

And use the `./` prefix to run a program (For example, a simple screensaver):

<pre>
./usr/bin/saver.exe
</pre>

## Cross-Compiling Instructions

If you are building on any other type of machine (i.e, on WSL or any non-linux machine),
you will probably need to build a cross-compiler
using `./scripts/crosscompiler.sh` and then edit
`Makefile.config` to use the cross compiler binaries,
then execute `make` to create `cadex.iso`

