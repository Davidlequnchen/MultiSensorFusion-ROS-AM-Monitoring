# linllt

## What is linllt?

The linllt libraries (libmescan and libllt) are aravis-based libraries for operating scanCONTROL sensors from MICRO-EPSILON. libmescan is a C library for sensor control and data aquisition. linllt is a C++ wrapper.

## Building the linllt libraries

For pain-free usage, the libraries can be built with the [Meson](http://mesonbuild.com) build system. Meson checks for the required dependencies, like aravis, and does all necessary steps to prepare compiling and installing the code on the currently used platform. For compiling and installing [Ninja](https://ninja-build.org) is used.

If Meson is not installed on the host PC, it can be retrieved via the distribuitions package manager, e.g.

```bash
sudo apt install meson
```

or from [source](https://github.com/mesonbuild/meson/releases). Meson dependencies are [Python](http://python.org) (>=3.4) and [Ninja](https://ninja-build.org) (>=1.5).

Before continuing please have a look at the dependencies to guarantee successful compilation.

For each library in the root folder (libmescan/ & libllt/), the following commands have to be executed to fully compile and install linllt. libmescan has to be compiled and installed first.

```bash
meson builddir
cd builddir
ninja
sudo ninja install
```

It might be necessary to call `sudo ldconfig` afterwards, to reload the linker cache.

To use the libraries with Python (>=3.4), the module pymescan (located in the python_bindings folder) has to be copied to the site-packages of the desired python installation. The module assumes the library in /usr/local/lib.

## Dependencies

Aravis has to be compiled from source via the GNU build system:

- [Aravis](https://github.com/AravisProject/aravis/releases) (version 0.5.8 or newer)

To compile the basic GNU build toolchain and the autotools are necessary. Further aravis dependencies are:

- [libxml2](https://github.com/GNOME/libxml2/releases)
- [glib2](https://github.com/GNOME/glib/releases)

These and the toolchain packages are usually available via the package manager, e.g.

```bash
sudo apt install build-essential autotools-dev automake intltool libtool gtk-doc-tools libxml2-dev libglib2.0-dev
```

Make sure to update and upgrade your repos beforehand. Further information can be found on the [aravis Github page](https://github.com/AravisProject/aravis).

## Using the examples

The C/C++ examples can also be built by meson. For image output support in the C++ container mode example (ContainerMode) [libpng](https://sourceforge.net/projects/libpng/files) (>=1.5) has to be installed.

The Python examples need a working installation of matplotlib and scipy.

## Cross compile

To cross compile with the meson build system, different specific cross files can be used. Of course the different cross compilers have to be installed, e.g. for aarch64. The aarch64 environment is set up on the Ubuntu 17.10 distro and can be triggered with:

```bash
meson build --cross-file cross-compilation/aarch64-host.txt
```

At the moment for arm32 compilation a Raspberry Pi is used, thus no cross compilation environment is set up. For this c\_std=c99 (default options in project) and c_args:'-D_POSIX_C_SOURCE=199309L' (shared_library) might be needed in meson.build.

## License

As of version 0.2.x the library is released under LGPLv3. The examples are licensed under MIT license.