#include <iostream>
#include "Arbol.h"


using namespace std;

Arbol::Arbol() : raiz(nullptr){}


Arbol::~Arbol() {   // Liberar la memoria del árbol

    delete raiz;
    raiz = nullptr;
}

int Arbol::altura(Nodo* nodo){
    if(nodo == nullptr) return 0;
    return nodo->getAltura();
}

int Arbol::factorEquilibrio(Nodo* nodo){
    return altura(nodo->getIzq()) - altura(nodo->getDer());
}

Nodo* Arbol::rotarIzquierda(Nodo* nodo) {
    Nodo* nuevaRaiz = nodo->getDer();
    nodo->setDer(nuevaRaiz->getIzq());
    nuevaRaiz->setIzq(nodo);
    nodo->setAltura(1 + max(altura(nodo->getIzq()), altura(nodo->getDer())));
    nuevaRaiz->setAltura(1 + max(altura(nuevaRaiz->getIzq()), altura(nuevaRaiz->getDer())));
    return nuevaRaiz;
}

Nodo* Arbol::rotarDerecha(Nodo* nodo) {
    Nodo* nuevaRaiz = nodo->getIzq();
    nodo->setIzq(nuevaRaiz->getDer());
    nuevaRaiz->setDer(nodo);
    nodo->setAltura(1 + max(altura(nodo->getIzq()), altura(nodo->getDer())));
    nuevaRaiz->setAltura(1 + max(altura(nuevaRaiz->getIzq()), altura(nuevaRaiz->getDer())));
    return nuevaRaiz;
}

Nodo* Arbol::insertar(Nodo* nodo, Fecha f, Cuac* c) {
    if (nodo == nullptr) {
        Nodo* nuevo = new Nodo(f);
        nuevo->addCuac(c); 			// Añadimos el primero a la lista
        return nuevo;
    }

    if (f.es_menor(nodo->getFecha())) {
        nodo->setIzq(insertar(nodo->getIzq(), f, c));
    }
    else if (nodo->getFecha().es_menor(f)) { 		
        nodo->setDer(insertar(nodo->getDer(), f, c));
    }
    else {
        					//Si las fechas son iguales añadimos a la lista existente
        nodo->addCuac(c);
    }

    // Actualizamos la altura del nodo actual
    nodo->setAltura(1 + max(altura(nodo->getIzq()), altura(nodo->getDer())));

    // Calculamos el factor de equilibrio
    int equilibrio = factorEquilibrio(nodo);

    // Si el nodo se desequilibra a la izquierda
    if (equilibrio > 1 && f.es_menor(nodo->getIzq()->getFecha())) {
        return rotarDerecha(nodo);  // Rotación simple a la derecha
    }

    // Si el nodo se desequilibra a la derecha
    if (equilibrio < -1 && !f.es_menor(nodo->getDer()->getFecha())) {
        return rotarIzquierda(nodo);  // Rotación simple a la izquierda
    }

    //Nodo desequilibrado a la izquierda-derecha(RDI)
    if (equilibrio > 1 && !f.es_menor(nodo->getIzq()->getFecha())) {
        nodo->setIzq(rotarIzquierda(nodo->getIzq()));
        return rotarDerecha(nodo);
    }

    //Nodo desequilibrado a la derecha-izquierda(RDD)
    if (equilibrio < -1 && f.es_menor(nodo->getDer()->getFecha())) {
        nodo->setDer(rotarDerecha(nodo->getDer()));
        return rotarIzquierda(nodo);
    }

    return nodo;  // El nodo equilibrado
}

void Arbol::insertar(Cuac* cuac) {
    raiz = insertar(raiz,cuac->getFecha(), cuac);
}

void Arbol::last(int N) {
    int contador = 0;
    last_recursivo(raiz, N, contador);
    cout << "Total: " << contador << " cuac" << endl;
}

void Arbol::last_recursivo(Nodo* nodo, int N, int &contador) {
    if (nodo == nullptr || contador >= N) return;

    
    last_recursivo(nodo->getDer(), N, contador);		//Primero miramos a la derecha donde estan los mas recientes


    if (contador < N) {					//Miramos la lista del nodo actual
        for (Cuac* c : nodo->getCuacs()) {
            if (contador >= N) break;
            cout << contador + 1 << ". ";
            c->escribirCuac();
            contador++;
        }
    }
    
    if (contador < N) {
        last_recursivo(nodo->getIzq(), N, contador);
    }
}
    
void Arbol::date(Fecha f1, Fecha f2){
	int contador = 0;
	
	date_recursivo(raiz,f1,f2,contador);
	cout<<"Total: "<< contador << " cuac" <<endl;
	
}
    
void Arbol::date_recursivo(Nodo* nodo, Fecha f1, Fecha f2, int &contador){
	if(nodo == nullptr) return;
	
	if (nodo->getFecha().es_menor(f2)){
		date_recursivo(nodo->getDer(), f1, f2, contador);	//Miramos primero en la derecha que son los mas recientes. Solo vamos a la derecha si el nodo actual es menor que la fecha maxima.
	}
	
	bool antiguo = nodo->getFecha().es_menor(f1);	//Si es menor el nodo actual que la f1, fecha mas antigua,sera que es mas antiguo por lo que se sale del rango.
	bool nuevo = f2.es_menor(nodo->getFecha());		//Aqui es el caso contrario, si es mayor que f2, sera muy nuevo y estara fuera de rango
	
	if(!antiguo && !nuevo){					//Con esto podemos ver que esta en el rango de fechas
		for(Cuac* c: nodo->getCuacs()){
			cout<<contador + 1 << ". ";
			c->escribirCuac();
			contador++;
		}
	}
	
	if(f1.es_menor(nodo->getFecha())){			//En este caso miramos la izquerda, despues de mirar la derecha y el nodo actual.
		date_recursivo(nodo->getIzq(), f1, f2, contador);
	}
}

