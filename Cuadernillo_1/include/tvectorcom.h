#ifndef __TVECTORCOMPLEJO__H__
#define __TVECTORCOMPLEJO__H__
#include "tcomplejo.h"

class TVectorCom{
    private:
        TComplejo *c;
        int tamano;
        TComplejo err;
    public:
        // Forma canónica
        TVectorCom();
        TVectorCom(const int tam);
        TVectorCom(const TVectorCom &tvc);

        ~TVectorCom();

        TVectorCom& operator=(const TVectorCom &tvc);

        //Métodos
        bool operator==(const TVectorCom &tvc) const;
        bool operator!=(const TVectorCom &tvc) const;
        TComplejo& operator[](const int pos);
        const TComplejo& operator[](const int pos) const; //Parte derecha 
        
        int Tamano() const;
        int Ocupadas() const;
        bool ExisteCom(const TComplejo &tc) const;
        void MostrarComplejos(const double arg) const;
        bool Redimensionar(const int ntam);

        //Funciones amigas amigas
        friend ostream& operator<<(ostream &os, TVectorCom &tvc);
};

#endif