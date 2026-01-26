#ifndef _CUAC_
#define _CUAC_

#include "Fecha.h"
#include<string>
using namespace std;

class Cuac {
    private:
        Fecha fecha;
        string usuario;
        string texto;

    public:
        bool leer_mcuac();
        bool leer_pcuac();
        void escribirCuac();
        bool es_anterior(Cuac &otro);
                
        string getUsuario() const{
            return usuario;
        }

        Fecha getFecha() const{
            return fecha;
        }
};

#endif
