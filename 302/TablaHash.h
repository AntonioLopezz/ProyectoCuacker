#ifndef _TablaHash_
#define _TablaHash_

#include <list>
#include<string>
#include "Cuac.h"


class TablaHash{
    
    private:
        int M=200003;              //Aqui tenemos el tamaño de la tabla, asignamos uno fijo
        list<Cuac> *T;      //array de memoria dinámica de listas de Cuac, dispersion abierta
        int nElem;          //n total de cuacs

        int h(const string &nombre) const;  //Declaramos la función de redispersion, que recibe el nombre del usuario

    public:
        TablaHash();        //Constructor
        ~TablaHash();       //Destructor
        
        Cuac* insertar(Cuac nuevo);	//Cambiamos void por Cuac* porque si no el arbol se queda apuntando a basura
        void consultar(string nombre);
        int numElem (void){ return nElem;}

};

#endif
