#include "TComplejo.h"
#include <cmath>
//========================================================================================================================================
//                                                       Forma canónica
//========================================================================================================================================
TComplejo::TComplejo(const double re = 0.0, const double im = 0.0){this->re = re; this->im = im;}

TComplejo::TComplejo(const TComplejo &tcomp){
    this->re = tcomp.re;
    this->im = tcomp.im;
}

TComplejo::~TComplejo(){this->re = 0.0; this->im = 0.0;} 

TComplejo& TComplejo::operator=(const TComplejo &tcomp){
    if(this != &tcomp){
        this->re = tcomp.re;
        this->im = tcomp.im;
    }
    return *this;    
}

//========================================================================================================================================
//                                                          Métodos
//========================================================================================================================================
//                                                Sobrecarga de operadores ariméticos
//========================================================================================================================================

TComplejo TComplejo::operator+(const TComplejo &tcomp){
    return TComplejo(this->re + tcomp.re, this->im + tcomp.im);
}

TComplejo TComplejo::operator-(const TComplejo &tcomp){
    return TComplejo(this->re - tcomp.re, this->im - tcomp.im);
}

TComplejo TComplejo::operator*(const TComplejo &tcomp){
    //return TComplejo(this->re * tcomp.re, this->im * tcomp.im);
    return TComplejo(
        (this->re * tcomp.re) - (this->im * tcomp.im) ,
        (this->re * tcomp.im) + (this->im * tcomp.re)
    );
}

TComplejo TComplejo::operator+(const double num){
    return TComplejo(this->re + num, this->im);
}

TComplejo TComplejo::operator-(const double num){
    return TComplejo(this->re - num, this->im);
}

TComplejo TComplejo::operator*(const double num){
    //return TComplejo(this->re * num, this->im);
    return TComplejo(this->re * num, this->im * num);
}

//========================================================================================================================================
//                                                        Otros operadores
//========================================================================================================================================


bool TComplejo::operator==(const TComplejo &tcomp){return (this->re == tcomp.re && this->im == tcomp.im);}
bool TComplejo::operator!=(const TComplejo &tcomp){return !(operator==(tcomp));}
double TComplejo::Re(){return this->re;}
double TComplejo::Im(){return this->im;}
void TComplejo::Re(const double real){this->re = real;}
void TComplejo::Im(const double imag){this->im = im;}
double TComplejo::Arg(){return atan2(this->im, this->re);} //Atan2 devuelve el resultado ya en radianes y en un rango comprendido entre [π, -π]
double TComplejo::Mod(){
    double mod = 0.0;
    mod = sqrt(pow(this->re, 2) + pow(this->im, 2));
    //mod = hypot(this->re,this->im);
    return mod;
}

//========================================================================================================================================
//                                                        Funciones amigas
//========================================================================================================================================

ostream& operator<<(ostream &os, const TComplejo &tcomp){
    os << "(" << tcomp.re << " " << tcomp.im << ")";
    return os;
}

TComplejo operator+(const double num, const TComplejo &tcomp){
    return tcomp + num;
}

TComplejo operator*(const double num, const TComplejo &tcomp){
    return tcomp * num;
}

TComplejo operator-(const double num, const TComplejo &tcomp){
    return TComplejo(num - tcomp.re, -tcomp.im);
}
