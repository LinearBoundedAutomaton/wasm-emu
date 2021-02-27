
main: ./src/main.c
	mkdir -p ./build
	emcc ./src/main.c -o ./build/main.js

mainui: ./src/main.c
	mkdir -p ./build
	emcc ./src/main.c -o ./build/index.html

serve:
	cd ./build; python -m SimpleHTTPServer 4321