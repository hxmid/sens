all:
	mkdir -p bin
	g++ sens.cpp -o bin/sens -O3 -static -static-libgcc -static-libstdc++
