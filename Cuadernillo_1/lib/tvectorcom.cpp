#include "../include/tvectorcom.h"
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

TVectorCom::~TVectorCom(){delete [] this->c; this->c = NULL; this->tamano = 0;}

TVectorCom &TVectorCom::operator=(const TVectorCom &tvc){
    if(this != &tvc){
        if (this->c != NULL){delete [] this->c;}
        this->tamano = tvc.tamano;
        tvc.tamano == 0 ? this->c = NULL : this->c = new TComplejo[this->tamano];
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


bool TVectorCom::ExisteCom(const TComplejo &tc) const{
    bool existe = false;
    for(int i = 0; i < this->tamano; i++){
        if(this->c[i] == tc) existe = true; break;
    }

    return existe;
}

void TVectorCom::MostrarComplejos(const double arg) const{
    cout << "[";
    bool primerel = true;
    for(int i = 0; i < this->tamano; i++){
        if(this->c[i].Arg() >= arg) {
            if(!primerel) cout << ",";
            cout << this->c[i];
            primerel = false;
        }
    }
    cout << "]";
}

bool TVectorCom::Redimensionar(const int ntam){
    if(ntam <= 0 || ntam == this->tamano) return false;
    TVectorCom nv = TVectorCom(ntam);
    for(int i = 0; i < ntam; i++){ //No es necesario distinguier entre los dos casos, se inicializa todo a cero y luego se copian según el nuevo tamaño
        if(i < tamano){
            nv.c[i] = this->c[i];
        }
    }
    *this = nv;
    return true;
}

//========================================================================================================================================
//                                                        Funciones amigas
//========================================================================================================================================

ostream &operator<<(ostream &os, TVectorCom &tvc){
    bool primero = true;
    os << "[";
    for(int i = 0; i < tvc.tamano; i++){
        if(!primero) os << ", ";
        os << "(" << i+1 << ")" << " " << tvc.c[i];
        primero = false;
    }
    os << "]";
    
    return os;
}
