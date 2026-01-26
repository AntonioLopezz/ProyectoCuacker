# === Makefile para el proyecto CUACKER (práctica 200) ===

a.out: Fecha.o Cuac.o DiccionarioCuacs.o TablaHash.o Nodo.o Arbol.o 302.o 
	g++ Fecha.o Cuac.o DiccionarioCuacs.o TablaHash.o Nodo.o Arbol.o 302.o -o a.out

Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp

Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp
	
DiccionarioCuacs.o: DiccionarioCuacs.cpp DiccionarioCuacs.h Cuac.h Fecha.h
	g++ -c DiccionarioCuacs.cpp
	
TablaHash.o: TablaHash.cpp TablaHash.h Cuac.h Fecha.h
	g++ -c TablaHash.cpp
	
Nodo.o: Nodo.cpp Nodo.h Nodo.h DiccionarioCuacs.h TablaHash.h
	g++ -c Nodo.cpp

Arbol.o: Arbol.cpp Arbol.h
	g++ -c Arbol.cpp

302.o: 302.cpp Fecha.h Cuac.h DiccionarioCuacs.h TablaHash.h Nodo.h Arbol.h
	g++ -c 302.cpp

