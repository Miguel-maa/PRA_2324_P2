test_DyV: test_DyV.cpp DyV.h
	mkdir -p
	g++ -o test_DyV test_DyV.cpp DyV.h

clean:
	rm -r *.o *.gch

monedas: monedas.cpp
	mkdir -p
	g++ -o monedas monedas.cpp

mochila: mochila.cpp
	mkdir -p
	g++ -o mochila mochila.cpp
