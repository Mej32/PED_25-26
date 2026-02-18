#ifndef __TLISTACOMPLEJO__H__
#define __TLISTACOMPLEJO__H__
#include "tcomplejo.h"

class TListaNodo{
    private:
        TComplejo e;
        TListaNodo *anterior;
        TListaNodo *siguiente;

    public:
        //Forma canónica
        TListaNodo();
        TListaNodo(const TListaNodo &tln);
        ~TListaNodo();
        TListaNodo& operator=(const TListaNodo &tln);

    friend class TListaPos;
    friend class TListaCom;   
};

class TListaPos{
    private:
        TListaNodo *pos;
    public:
        //Forma canónica
        TListaPos();
        TListaPos(const TListaPos &tlp);
        ~TListaPos();
        TListaPos& operator=(const TListaPos &tlp);

        //Métodos
        bool operator==(const TListaPos &tlp) const;
        bool operator!=(const TListaPos &tlp) const;
        TListaPos Anterior() const;
        TListaPos Siguiente() const;
        bool EsVacia() const;

    friend class TListaNodo;
    friend class TListaCom;  
};

class TListaCom{
    private:
    TListaNodo *primero; 
    TListaNodo *ultimo; 

    public:
    //Forma canónica
    TListaCom (); 
    TListaCom (const TListaCom &tlc); 
    ~TListaCom (); 
    TListaCom & operator=(const TListaCom &tlc); 

    //Métodos
    bool operator==(const TListaCom &tlc) const; 
    bool operator!=(const TListaCom &tlc) const; 
    TListaCom operator+(const TListaCom &tlc) const; 
    TListaCom operator-(const TListaCom &tlc) const;  
    bool EsVacia() const; 
    bool InsCabeza(const TComplejo &tc);  
    bool InsertarI(const TComplejo &tc, const TListaPos &tlp); 
    bool InsertarD(const TComplejo &tc, const TListaPos &tlp); 
    bool Borrar(const TComplejo &tc); 
    bool BorrarTodos(const TComplejo &tc); 
    bool Borrar(const TListaPos &tlp); 
    TComplejo Obtener(const TListaPos &tlp) const; 
    bool Buscar(const TComplejo &tc) const; 
    int Longitud() const; 
    TListaPos Primera() const; 
    TListaPos Ultima() const;

    friend ostream & operator<<(ostream &os, TListaCom &tlc);
    
    friend class TListaPos; 
    friend class TListaNodo; 

};

#endif
