
main: ./src/main.c
	mkdir -p ./build
	emcc ./src/main.c -o ./build/main.js

mainui: ./src/main.c
	mkdir -p ./build
	emcc -c -fPIC ./src/cpu/cpu.c -o ./build/cpu.o
	emcc -c -fPIC ./src/cpu/memory.c -o ./build/memory.o 
	emcc -c -fPIC ./src/cpu/instruction.c -o ./build/instruction.o
	emcc -shared -fPIC ./build/cpu.o ./build/memory.o ./build/instruction.o -o ./build/libemu.so
	emcc -L./build -lemu ./src/main.c -o ./build/index.html

serve:
	cd ./build; python -m SimpleHTTPServer 4321