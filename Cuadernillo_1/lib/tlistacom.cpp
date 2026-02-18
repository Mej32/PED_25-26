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

//========================================================================================================================================
//                                                               Forma canónica
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

TListaCom::~TListaCom(){

}

//========================================================================================================================================
//                                                                  Métodos
//========================================================================================================================================

bool TListaCom::operator==(const TListaCom &tlc) const{
    if(this->Longitud() != tlc.Longitud())
        return false;
    TListaNodo *nodoA = this->primero;
    TListaNodo *nodoB = tlc.primero;
    
    while(nodoA != NULL){
        if(nodoA->e != nodoB->e)
            return false;
        nodoA = nodoA->siguiente;
        nodoB = nodoB->siguiente;
    }
    return true;
}

bool TListaCom::operator!=(const TListaCom &tlc) const{
    return !(*this == tlc);
}

TListaCom TListaCom::operator+(const TListaCom &tlc) const{
    TListaCom nuevalista = TListaCom();
    if(this->primero == NULL){
        nuevalista = tlc;
    }else if(tlc.primero == NULL){
        nuevalista = *this;
    }else {
        nuevalista = *this;
        TListaNodo *nodoaux = tlc.primero;
        while(nodoaux != NULL){
            nuevalista.InsertarD(nodoaux->e,nuevalista.Ultima());
            nodoaux = nodoaux->siguiente;
        }
    }
    return nuevalista;
}

TListaCom TListaCom::operator-(const TListaCom &tlc) const{
    TListaCom nuevalista = TListaCom();
    if(this->primero == NULL){

    }else if(tlc.primero == NULL){
        nuevalista = *this;
    }else {

    }
    return nuevalista;
}

bool TListaCom::EsVacia() const{
    return false;
}

bool TListaCom::InsCabeza(const TComplejo &tc){
    return false;
}

bool TListaCom::InsertarI(const TComplejo &tc, const TListaPos &tlp){
    return false;
}

bool TListaCom::InsertarD(const TComplejo &tc, const TListaPos &tlp){
    if(tlp.pos == NULL){return false;}
    TListaNodo *nuevo = new TListaNodo();
    nuevo->e = tc;
    nuevo->anterior = tlp.pos;
    nuevo->siguiente = tlp.pos->siguiente;

    if(tlp.pos->siguiente != NULL)
        tlp.pos->siguiente->anterior = nuevo; // caso medio
    else
        this->ultimo = nuevo;     // era el último

    tlp.pos->siguiente = nuevo;
    return true;
}

bool TListaCom::Borrar(const TComplejo &tc){
    return false;
}

bool TListaCom::BorrarTodos(const TComplejo &tc){

    return false;
}

bool TListaCom::Borrar(const TListaPos &tlp){
    return false;
}

TComplejo TListaCom::Obtener(const TListaPos &tlp) const{
    return TComplejo();
}

bool TListaCom::Buscar(const TComplejo &tc) const{
    return false;
}

int TListaCom::Longitud() const{
    int longi = 0;
    TListaNodo *nodo = this->primero;
    while(nodo != NULL){
        longi++;
        nodo = nodo->siguiente;
    }
    return longi;
}

TListaPos TListaCom::Primera() const{
    return TListaPos();
}

TListaPos TListaCom::Ultima() const{
    return TListaPos();
}

ostream &operator<<(ostream &os, TListaCom &tlc){
    // TODO: insert return statement here
}
