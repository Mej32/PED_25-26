#include "../include/tlistacom.h"
#include "tlistacom.h"

//========================================================================================================================================
//                                                       
//                                                                 TListaNodo
//
//========================================================================================================================================

TListaNodo::TListaNodo(){
    this->e = TComplejo();
    this->anterior = NULL;
    this->siguiente = NULL;    
}
TListaNodo::TListaNodo(const TListaNodo &tln){
    this->e = tln.e;
    this->anterior = tln.anterior;
    this->siguiente = tln.siguiente;
}
TListaNodo::~TListaNodo(){
    this->anterior = NULL;
    this->siguiente = NULL; 
}

TListaNodo &TListaNodo::operator=(const TListaNodo &tln){
    if(this->e != tln.e || this->anterior != tln.anterior || this->siguiente != tln.siguiente){
        this->e = tln.e;
        this->anterior = tln.anterior;
        this->siguiente = tln.siguiente;
    }
    return *this;
}

//========================================================================================================================================
//                                                       
//                                                                 TListaPos
//
//========================================================================================================================================

//========================================================================================================================================
//                                                               Forma canónica
//========================================================================================================================================


TListaPos::TListaPos(){this->pos = NULL;}
TListaPos::TListaPos(const TListaPos &tlp){this->pos = tlp.pos;}
TListaPos &TListaPos::operator=(const TListaPos &tlp){
    if(this->pos != tlp.pos)
        this->pos = tlp.pos;
    return *this;
}
TListaPos::~TListaPos(){this->pos = NULL;}

//========================================================================================================================================
//                                                                  Métodos
//========================================================================================================================================

bool TListaPos::operator==(const TListaPos &tlp) const{
    bool iguales;
    this->pos == tlp.pos ? iguales = true : iguales = false;
    return iguales;
}

bool TListaPos::operator!=(const TListaPos &tlp) const{
    return !(*this == tlp);
}

TListaPos TListaPos::Anterior() const{
    TListaPos posicion = TListaPos();
    if(this->pos != NULL && this->pos->anterior != NULL){
        posicion.pos = this->pos->anterior;
    }
    return posicion;
}

TListaPos TListaPos::Siguiente() const{
    TListaPos posicion = TListaPos();
    if(this->pos != NULL && this->pos->siguiente != NULL){
        posicion.pos = this->pos->siguiente;
    }
    return posicion;
}

bool TListaPos::EsVacia() const{
    return this->pos == NULL;
}

//========================================================================================================================================
//                                                       
//                                                                 TListaCom
//
//========================================================================================================================================

TListaCom::TListaCom(){this->primero = this->ultimo = NULL;}
TListaCom::TListaCom(const TListaCom &tlc){
    *this = tlc;
}

TListaCom &TListaCom::operator=(const TListaCom &tlc){
    if(this != &tlc && *this != tlc){
    //    this->primero = NULL;
    //    this->ultimo = NULL;
    //    TListaNodo *pos = tlc.primero;
//
    //    while(pos != NULL){
    //        TListaNodo *nuevo = new TListaNodo();
    //        *nuevo = *pos;
    //        delete pos;
    //        pos = nuevo->siguiente;
    //    }
    }
    return *this;
}