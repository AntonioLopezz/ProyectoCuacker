#include <iostream>
#include <string>


#include "Fecha.h"
#include "Cuac.h"
#include "DiccionarioCuacs.h"

using namespace std;
const string a[30] = {
    "Afirmativo.",
    "Negativo.",
    "Estoy de viaje en el extranjero.",
    "Muchas gracias a todos mis seguidores por vuestro apoyo.",
    "Enhorabuena, campeones!",
    "Ver las novedades en mi pagina web.",
    "Estad atentos a la gran exclusiva del siglo.",
    "La inteligencia me persigue pero yo soy mas rapido.",
    "Si no puedes convencerlos, confundelos.",
    "La politica es el arte de crear problemas.",
    "Donde estan las llaves, matarile, rile, rile...",
    "Si no te gustan mis principios, puedo cambiarlos por otros.",
    "Un dia lei que fumar era malo y deje de fumar.",
    "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.",
    "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.",
    "Mi vida no es tan glamurosa como mi pagina web aparenta.",
    "Todo tiempo pasado fue anterior.",
    "El azucar no engorda... engorda el que se la toma.",
    "Solo los genios somos modestos.",
    "Nadie sabe escribir tambien como yo.",
    "Si le molesta el mas alla, pongase mas aca.",
    "Me gustaria ser valiente. Mi dentista asegura que no lo soy.",
    "Si el dinero pudiera hablar, me diria adios.",
    "Hoy me ha pasado una cosa tan increible que es mentira.",
    "Si no tienes nada que hacer, por favor no lo hagas en clase.",
    "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.",
    "Me despido hasta la proxima. Buen viaje!",
    "Cualquiera se puede equivocar, inclusivo yo.",
    "Estoy en Egipto. Nunca habia visto las piramides tan solas.",
    "El que quiera saber mas, que se vaya a Salamanca."
};
string numAtexto(int n){
    return a[n-1];
}



int textoAnum(string entrada) {
    for (int i = 0; i < 30; i++) {
        if (entrada == a[i])
            return i + 1;  // El número asociado es la posición + 1
    }
  return -1; // No encontrado
}

DiccionarioCuacs dic;

void procesar_pcuac(){

    Cuac nuevo;
    nuevo.leer_pcuac();
    dic.insertar(nuevo);

    cout << dic.numElem() << " cuac\n";
}

void procesar_mcuac(){

    Cuac nuevo;
    nuevo.leer_mcuac();
    dic.insertar(nuevo);

    cout<<dic.numElem()<<" cuac\n";

}

void procesar_last(){

    int N = 0;
    cin>>N;
    cout<<"last "<<N<<endl;
    dic.last(N);
}

void procesar_follow(){
    string usuario;
    cin>>usuario;
    cout<<"follow "<<usuario<<endl;
    dic.follow(usuario);
}

void procesar_date(){
    Fecha minima;
    Fecha maxima;
	
    minima.leer();
    maxima.leer();	

    cout<<"date ";
    minima.escribir();
    cout<<" ";
    maxima.escribir();
    cout<<endl;
    dic.date(minima,maxima);
}


void Interprete (string comando)
{
   if (comando=="pcuac") procesar_pcuac();
   else if (comando=="mcuac") procesar_mcuac();
   else if (comando=="last") procesar_last();
   else if (comando=="follow") procesar_follow();
   else if (comando=="date") procesar_date();


}


int main(void){

    string comando;
    while (cin >> comando && comando!="exit"){
        Interprete(comando);
    }
    return 0;
}
