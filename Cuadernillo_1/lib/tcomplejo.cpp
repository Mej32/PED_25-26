#include "../include/tcomplejo.h"
#include <cmath>
//========================================================================================================================================
//                                                       Forma canónica
//========================================================================================================================================
TComplejo::TComplejo(const double re, const double im){this->re = re; this->im = im;}

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

TComplejo TComplejo::operator+(const TComplejo &tcomp)const{
    return TComplejo(this->re + tcomp.re, this->im + tcomp.im);
}

TComplejo TComplejo::operator-(const TComplejo &tcomp)const{
    return TComplejo(this->re - tcomp.re, this->im - tcomp.im);
}

TComplejo TComplejo::operator*(const TComplejo &tcomp)const{
    //return TComplejo(this->re * tcomp.re, this->im * tcomp.im);
    return TComplejo(
        (this->re * tcomp.re) - (this->im * tcomp.im) ,
        (this->re * tcomp.im) + (this->im * tcomp.re)
    );
}

TComplejo TComplejo::operator+(const double num)const{
    return TComplejo(this->re + num, this->im);
}

TComplejo TComplejo::operator-(const double num)const{
    return TComplejo(this->re - num, this->im);
}

TComplejo TComplejo::operator*(const double num)const{
    //return TComplejo(this->re * num, this->im);
    return TComplejo(this->re * num, this->im * num);
}

//========================================================================================================================================
//                                                        Otros operadores
//========================================================================================================================================


bool TComplejo::operator==(const TComplejo &tcomp)const{return (this->re == tcomp.re && this->im == tcomp.im);}
bool TComplejo::operator!=(const TComplejo &tcomp)const{return !(operator==(tcomp));}
double TComplejo::Re()const{return this->re;}
double TComplejo::Im()const{return this->im;}
void TComplejo::Re(const double real){this->re = real;}
void TComplejo::Im(const double imag){this->im = imag;}
double TComplejo::Arg()const{return atan2(this->im, this->re);} //Atan2 devuelve el resultado ya en radianes y en un rango comprendido entre [π, -π]
double TComplejo::Mod()const{
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
