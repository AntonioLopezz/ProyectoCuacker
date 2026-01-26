#include "TablaHash.h"
#include <iostream>

using namespace std;

TablaHash:: TablaHash(){
    nElem = 0;
    T = new list<Cuac>[M];       //Construimos la tabla con el tamaño de M y inicializada a 0.
}

TablaHash::~TablaHash(){
    delete[] T;                 //Destructor de la tabla
}

int TablaHash::h(const string &nombre) const {
    unsigned long n = 0;        //con unsigned nos evitamos que sea negativo, al igual que char c.
    const int B = 131;

    for(unsigned char c:nombre){
        n = (n*B + c) % M;          //n es lo que llevamos de cadena, se multiplica por B y le sumamos el caracter UTF-8
                                    //es un hash polinomico, (c0*B + c1)*B + c2)*B...) mod M, coge un caracter le multiplica B y le
    }                                //suma el siguiente,mod M para que esté en el rango
    
    return n;       //indice de la cubeta entre 0 y M-1
}

Cuac* TablaHash:: insertar(Cuac nuevo){  //Como en el .h cambiamos a Cuac*
    int pos = h(nuevo.getUsuario()); //Vemos en que cubeta va el usuario con la funcion de dispersion

    list<Cuac> &cubeta = T[pos];      //Con T[pos] accedemos a la lista de esa cubeta, usamos & para referenciar la lista
                                      //para que cualquier cambio que hagamos sobre cubeta afecte a T[pos] tambien.   

    list<Cuac>::iterator it = cubeta.begin();
    while(it != cubeta.end() && !nuevo.es_anterior(*it)){
        ++it;                         //Con esto buscamos la posicion correcta dentro de la tabla(del ejercicio anterior)
    }
    list<Cuac>:: iterator it_res= cubeta.insert(it,nuevo); //Insertamos nuevo delante de it y guardamos el iterador al nuevo elemento


    nElem++;                          //Por ultimo aumentamos el numero total de elementos en la tabla(de cuacs).  
    
    return &(*it_res);	//devolvemos la direccion de memoria dentro de la lista, el puntero
}

void TablaHash::consultar(string nombre) {
    
    int pos = h(nombre);
    list<Cuac> &cubeta = T[pos];      //Como en la funcion de arriba insertar, vemos en que cubeta va el usuario.

    int indice = 1;
    int total = 0;

    list<Cuac>::iterator it;
    for(it = cubeta.begin(); it != cubeta.end();it++){      //Recorremos la lista de la cubeta

        if(it->getUsuario() == nombre){                     //Dentro de la lista de la cubeta vemos cual es el usuario que nos han pasado como
            cout<< indice<< ". ";                           //parametro para ver sus cuacs e imprimirlos con cout.
            it->escribirCuac();
            indice++;
            total++;
        }

    }

    cout<< "Total: "<< total << " cuac" <<endl;
}




