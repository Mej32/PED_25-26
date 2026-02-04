#include "../include/tvectorcom.h"
#include "../include/tcomplejo.h"
#include <cmath>
#include "tvectorcom.h"
//========================================================================================================================================
//                                                       Forma canónica
//========================================================================================================================================
TVectorCom::TVectorCom(){this->c = NULL; this->tamano = 0;this->err = TComplejo();}
TVectorCom::TVectorCom(int tam){
    tam == 0 ? this->c = NULL : this->c = new TComplejo[tam];
    this->tamano = tam;
    this->err = TComplejo();
}

TVectorCom::TVectorCom(const TVectorCom &tvc){
    this->tamano = tvc.tamano;
    this->err = TComplejo();
    tvc.tamano == 0? this->c = NULL : this->c = new TComplejo[this->tamano];
    for(int i = 0; i < tamano; i++){
        this->c[i] = tvc.c[i];
    }
}

TVectorCom::~TVectorCom(){delete [] this->c; this->tamano = 0;}

TVectorCom &TVectorCom::operator=(const TVectorCom &tvc){
    if(this != &tvc){
        if (this->c != NULL){delete [] this->c;}
        this->tamano = tvc.tamano;
        this->c = new TComplejo[this->tamano];
        for(int i = 0; i < tamano; i++){
            this->c[i] = tvc.c[i];
        }
    }
    return *this;
}

//========================================================================================================================================
//                                                             Métodos
//========================================================================================================================================

bool TVectorCom::operator==(const TVectorCom &tvc) const{
    if(this->tamano != tvc.tamano){return false;}
    for(int i = 0; i < this->tamano; i++){
        if(this->c[i] != tvc.c[i]){return false;}
    }
    return true;
}

bool TVectorCom::operator!=(const TVectorCom &tvc) const{
    return !(this->operator==(tvc));
}

TComplejo& TVectorCom::operator[](const int pos){
    if(pos > this->tamano || pos < 1){return this->err;}
    return this->c[pos - 1];
}

const TComplejo& TVectorCom::operator[](const int pos) const{
    if(pos > this->tamano || pos < 1){return this->err;}
    return this->c[pos - 1];
}

int TVectorCom::Tamano() const{
    return this->tamano;
}

int TVectorCom::Ocupadas() const{
    int ocupadas = tamano;
    for(int i = 0; i < tamano; i++){
        if(this->c[i].Re() == 0.0 && this->c[i].Im() == 0.0){ocupadas--;}
    }
    return ocupadas;
}
//========================================================================================================================================
//                                                        Funciones amigas
//========================================================================================================================================
