
#include "Nodo.h"


using namespace std;

Nodo::Nodo(Fecha f) : fecha(f), izq(nullptr), der(nullptr), altura(1) {}        //Construimos el arbol con altura 1 y sin hijos


Nodo::~Nodo(){
    delete izq;
    delete der;
}

Fecha Nodo:: getFecha() {
    return fecha;
}

list<Cuac*>& Nodo::getCuacs(){
    return cuacs;
}
Nodo* Nodo::getIzq() {
    return izq;
}

Nodo* Nodo::getDer() {
    return der;
}

void Nodo::setIzq(Nodo* nuevo){
    izq = nuevo;
}

void Nodo::setDer(Nodo* nuevo){
    der = nuevo;
}

void Nodo::addCuac(Cuac* c) {
    list<Cuac*>::iterator it = cuacs.begin();

    while (it != cuacs.end() && !c->es_anterior(**it)) {	//Con el es.anterior miramos donde insertar ese cuac dentro de la lista.
        it++;							//Usamos ** porque it es un iterador a un puntero asi que *it es el puntero y **it es el objeto Cuac.
    }

    cuacs.insert(it, c); 
}



int Nodo::getAltura(){
    return altura;
}

void Nodo::setAltura(int nuevaAltura){
    altura = nuevaAltura;
}

int Nodo::obtenerBalance(){
    return izq->getAltura() - der->getAltura();
}


