#ifndef __TLISTACOMPLEJO__H__
#define __TLISTACOMPLEJO__H__
#include "tcomplejo.h"


class TListaCom{
    private:

    public:

    friend class TListaPos; 
    friend class TListaNodo; 
};

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
    friend class TListaComplejo;   
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
    friend class TListaComplejo;  
};

#endif
