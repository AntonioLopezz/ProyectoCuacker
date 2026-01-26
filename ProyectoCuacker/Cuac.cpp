#include<iostream>
#include<string>
#include"Cuac.h"
#include"Fecha.h"

using namespace std;

extern string numAtexto(int n);

bool Cuac :: leer_mcuac(){

    if(!(cin>>usuario)){
        return false;
    }
    cin.ignore();
    if(!fecha.leer()){
        return false;
    }
    cin.ignore();
    if(!getline(cin,texto)){
        return false;
    }

    return true;

}

bool Cuac :: leer_pcuac(){

    int numero;
    if(!(cin>>usuario)){
        return false;
    }
    cin.ignore();
    if(!fecha.leer()){
        return false;
    }
    cin.ignore();
    cin >> numero;

    if(numero < 1 || numero > 30){
        return false;
    }
    texto = numAtexto(numero);
    return true;
}

void Cuac:: escribirCuac(){

    cout << usuario << " ";
    fecha.escribir(); // imprime la fecha
    cout << endl;
    cout << "   " << texto << endl;

}

bool Cuac:: es_anterior(Cuac &otro){
    if(otro.fecha.es_menor(fecha)){
        return true;
    }
    else if(fecha.es_menor(otro.fecha)){
        return false;
    }
    else if(fecha.es_igual(otro.fecha)){
        if(texto != otro.texto){
            return texto < otro.texto;
        }
        else{
            return usuario < otro.usuario;
        }
    }
    return false;
}
