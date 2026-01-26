#ifndef _NODO_
#define _NODO_

#include "Fecha.h"
#include <list>
#include "Cuac.h"

class Nodo{
    private:
        Fecha fecha;                //La fecha para cada nodo, para ordenar los cuacs
        std::list<Cuac*> cuacs;     //Cada nodo tiene una lista a una lista de punteros
        Nodo *izq, *der;            //Punteros a los hijos
        int altura;                 //Altura del AVL

    public:
        Nodo(Fecha f);              //Constructor
        ~Nodo();                    //Destructor

        //Getters y setters
        Fecha getFecha();
        list<Cuac*>& getCuacs();
        Nodo* getIzq();
        Nodo* getDer();
        void setIzq(Nodo *nuevo);
        void setDer(Nodo* nuevo);
        void addCuac(Cuac *c); 	   //Función para añadir a la lista de punteros

        //Balanceo
        int getAltura();
        void setAltura(int nuevaAltura);		
        int obtenerBalance();
	
};
#endif
