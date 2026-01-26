#include<iostream>

#include"Fecha.h"

using namespace std;

Fecha::Fecha (){
    dia = 1;
    mes = 1;
    ano = 1;
    hora = 0;
    minuto = 0;
    segundo = 0;
 }
bool Fecha::leer(){
    char c1,c2,esp,c3,c4;
    cin >> dia >> c1 >> mes >> c2 >> ano; //Ver formato fecha

    if(c1 != '/' || c2 != '/'){
        return false;
    }
    if(!cin.get(esp)){
        return false;
    }
    if(esp != ' '){
        return false;
    }
    cin >> hora >> c3 >> minuto >> c4 >> segundo; // Vemos la hora
    if(c3 != ':' || c4 != ':'){
        return false;
    }

    if (dia < 1 || dia > 31 || mes < 1 || mes  > 12 || ano < 1){
        return false;
    }
    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59 || segundo < 0 || segundo > 59){
        return false;
    }

    return true;
}
void Fecha::escribir(){
    cout<<dia<<"/"<<mes<<"/"<<ano<<" "; //Imprimos la fecha

    cout<<(hora < 10 ? "0" : "")<< hora << ":" << (minuto < 10? "0": "") << minuto << ":" << (segundo < 10 ? "0" : "") << segundo;
}
bool Fecha::es_menor(const Fecha &otra){
    if(ano != otra.ano) return ano < otra.ano;
    if(mes != otra.mes) return mes < otra.mes;
    if(dia != otra.dia) return dia < otra.dia;
    if(hora != otra.hora) return hora < otra.hora;
    if(minuto != otra.minuto) return minuto < otra.minuto;
    if(segundo != otra.segundo) return segundo < otra.segundo;
    return false;
}
bool Fecha::es_igual(const Fecha &otra){
    return dia == otra.dia &&
        mes == otra.mes &&
        ano == otra.ano &&
        hora == otra.hora &&
        minuto == otra.minuto &&
        segundo == otra.segundo;
}
