# The Cadex OS

Cadex OS is a Unix-like based operating system targeting x86 systems. This project is based on the [basekernel](https://github.com/dthain/basekernel) project

Cadex OS is a free and open-source project. You can fork this project and make your own OS from this.
Cadex OS is always Unix-compatible, except that Cadex OS doesn't support VFS (Virtual filesystem) and some Unix libraries are also missing.

Cadex OS can boot an Intel PC-compatible virtual machine in 32-bit protected
mode, with support for VESA framebuffer graphics, ATA hard disks, ATAPI optical
devices, process management, memory protection, small graphics, a standard libc, c++ language support and basic filesystem (DFS).
You can write programs for CadexOS by using the SDK for Windows or cloning the source and adding another application.

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

To learn more, see the **[Cadex OS Wiki](http://cadex-os-wiki.rf.gd).**

# Notable components

- **_kshell_**: A small but efficient shell implemented on the kernel space
- **_DiM_**: A very small text editor
- **_pam_**: A package manager for Cadex OS (not implemented)
- **_CaSh_**: A small bash-like shell implemented on the userspace

# Project structure

- **_apps_**: Sources for C++ apps
- **_basefs_**: Base filesystem folder that goes into the ISO image
- **_bin_**: Sources for standard system binaries (i.e, `/bin` folder)
- **_docs_**: Documentation about used drivers and APIs
- **_include_**: Header files for libc and libcxx libraries
- **_kernel_**: The core kernel source
- **_libc_**: Source files for libc and libcxx (This includes the standard system libraries)
- **_scripts_**: Scripts for generating ramfs image and other purposes
- **_usr_**: Programs that go into `/usr/bin` folder

# Building
First, do the steps mentioned in [docs/Building.md](docs/Building.md)
After you've built CadexOS, run `make run` and you should see Cadex OS QEMU.

<img src=docs/img/screenshot.png align=center>

After some initial boot messages, you will see the kshell prompt.
This allows you to take some simple actions before running the first
user-level program. For example, read the boot messages to see
which atapi unit the cdrom is mounted on. Then, use the `mount` command
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

# Discord

We have a Discord server! Everyone is welcome to the server! Join the server from this

# Cross-Compiling Instructions

If you are building on any other type of machine (i.e, on WSL or any non-linux machine),
you will probably need to build a cross-compiler
using `./scripts/build-toolchain.sh` and then edit
`Makefile.config` to use the cross compiler binaries,
then execute `make` to create `cadex.iso`

# Contributing

See [CONTRIBUTING.md](docs/CONTRIBUTING.md)
