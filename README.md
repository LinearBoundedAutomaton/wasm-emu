# wasm-emu
x86 emulator compiled targeting wasm

This project is organized as a monorepository.

## Building
### Requirements
1. Emscripten ( https://emscripten.org/index.html )
2. Make
Windows user are recommended to look at MinGW ( https://osdn.net/projects/mingw/ ) or Cygwin ( https://www.cygwin.com/ ) as sources of make

### Compiling
To compile the core project:

Pull the repo
> git pull https://github.com/LinearBoundedAutomaton/wasm-emu.git
> cd ./wasm-emu/core

Compile
> make


To compile a version of the project that comes packaged with a ui, run:
> make mainui

If python is installed, you can use:
> make serve

to serve the contents of the build folder. This is provided for convenience.