#ifndef _FECHA_
#define _FECHA_

class Fecha{
    private:
		int dia, mes, ano;
		int hora, minuto, segundo;
	public:
		Fecha();
		bool leer();
		void escribir();
		bool es_menor(const Fecha &otra);	//Ponemos const ahora porque nos daba error en la rotacion del arbol
		bool es_igual(const Fecha &otra);
};

#endif
