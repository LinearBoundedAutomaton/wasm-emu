
main: ./src/main.c
	mkdir -p ./build
	emcc ./src/main.c -o ./build/main.js

mainui: ./src/main.c
	mkdir -p ./build
	emcc -c -fPIC ./src/cpu/cpu.c -o ./build/cpu.o
	emcc -c -fPIC ./src/cpu/memory.c -o ./build/memory.o 
	emcc -c -fPIC ./src/cpu/instruction.c -o ./build/instruction.o
	emcc -c -fPIC ./src/cpu/registers.c -o ./build/registers.o
	emcc -shared -fPIC ./build/cpu.o ./build/memory.o ./build/instruction.o ./build/registers.o -o ./build/libemu.so
	emcc -L./build -lemu ./src/main.c -o ./build/index.html

serve:
	cd ./build; python -m SimpleHTTPServer 4321