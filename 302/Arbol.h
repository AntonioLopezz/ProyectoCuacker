#ifndef _ARBOL_
#define _ARBOL_

#include "Nodo.h"

class Arbol {
    private:
        Nodo *raiz;         //Raiz del arbol
        int altura(Nodo* nodo);                          // Calcula la altura de un nodo
        int factorEquilibrio(Nodo* nodo);                // Calcula el factor de equilibrio de un nodo
        Nodo* insertar(Nodo* nodo, Fecha f, Cuac* c);    // Inserta un nuevo cuac en el árbol
        void last_recursivo(Nodo *nodo,int N, int &contador);
        
        void date_recursivo(Nodo *nodo, Fecha f1, Fecha f2, int &contador);


    public:
        Arbol();            //Constructor
        ~Arbol();           //Destructor

        void insertar(Cuac* cuac);      //Insertar cuac en el arbol
        void last(int N);               //Obtener cuacs mas recientes
        
        void date(Fecha f1, Fecha f2);
        //Las ponemos publicas porque nos daba error
        Nodo* rotarIzquierda(Nodo* nodo);                // Rotación a la izquierda
        Nodo* rotarDerecha(Nodo* nodo);                  // Rotación a la derecha    
};
#endif
