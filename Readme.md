# GPIO Driver Project

This project contains a GPIO driver library (`gpio.c`) and a tester program (`gpio_tester.c`). The library provides GPIO-related functionality, while the tester demonstrates its usage. The project supports cross-compilation for embedded systems, particularly with a Yocto-generated toolchain.

---

## Requirements

- CMake (Version 2.6 or later)
- A Yocto-based toolchain (e.g., `poky-linux-gnueabi` for ARM)
- Cross-compilation environment setup script (`environment-setup-cortexa7t2hf-neon-vfpv4-poky-linux-gnueabi`)

---

## Building and Installing

### 1. Set Cross-Compiling Path
Navigate to the project directory and create a build folder. Then, run the following `cmake` command to configure the project:

```bash
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX:PATH="/tmp/libgpio_install"
```
### 2. Set Up the Cross-Compilation Environment
Before building , source the Yocto cross-compilation setup script
```bash
. /opt/poky/5.0.5/environment-setup-cortexa7t2hf-neon-vfpv4-poky-linux-gnueabi

```
Your cross compilation setup script can be different
This ensures that the correct cross-compilers and paths are used during the build process.

### 3. Go to the location of the installation and build the project

```bash
make
```

### 4. Install the project
```bash
make install
```
### 5. Copy your folders to their corresponding folders in the destination device storage
```vbnet
/tmp/libgpio_install/
├── bin/
│   └── gpio_tester
├── lib/
│   └── libgpio_lib.a (or libgpio_lib.so for shared builds)
└── include/
    └── gpio.h

```
