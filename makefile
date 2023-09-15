all:
	mkdir -p build
	gcc -o build/txe src/main.c

install:
	sudo make all
	sudo cp build/txe /usr/bin/txe

mr:
	make all
	clear
	./build/txe

ir:
	sudo make install
	clear
	txe