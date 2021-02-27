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