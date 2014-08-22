all: nttgen

nttgen: main.o Graph.o Surballe.o Dijkstra.o
	g++ main.o Graph.o Suurballe.o Dijkstra.o -o nttgen

main.o: main.cpp
	g++ -c main.cpp

Graph.o: Graph.cpp
	g++ -c Graph.cpp

Suurballe.o: Suurballe.cpp
	g++ -c Suurballe.cpp

Dijkstra.o: Dijkstra.cpp
	g++ -c Dijkstra.cpp

clean:
	rm -rf *o nttgen
