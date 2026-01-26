#ifndef _DICCIONARIOCUACS_
#define _DICCIONARIOCUACS_

#include "TablaHash.h"
#include "Arbol.h"
#include "Cuac.h"



#include <string>

class DiccionarioCuacs{

    private:
        TablaHash tabla;
        Arbol arbol;
    public:
        DiccionarioCuacs ();
        void insertar (Cuac nuevo){
            Cuac* ref = tabla.insertar(nuevo);
            arbol.insertar(ref);
        }
        void follow (string nombre){
            tabla.consultar(nombre);
        }
        void last (int N){
            arbol.last(N); 
        }
       void date (Fecha f1, Fecha f2){
            arbol.date(f1, f2); 
        }
        int numElem (){
           return tabla.numElem();
        }
};

#endif
