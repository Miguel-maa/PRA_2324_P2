test_DyV: test_DyV.cpp DyV.h
	mkdir -p bin
	g++ -o bin/test_DyV test_DyV.cpp DyV.h

clean:
	rm -r *.o *.gch bin

monedas: monedas.cpp
	mkdir -p bin
	g++ -o bin/monedas monedas.cpp

mochila: mochila.cpp
	mkdir -p bin
	g++ -o bin/mochila mochila.cpp
