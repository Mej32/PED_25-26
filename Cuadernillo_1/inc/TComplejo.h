#ifndef TCOMPLEJO_H
#define TCOMPLEJO_H

#include <iostream>

using namespace std;

class TComplejo{
    private:
        double re;
        double im;
    
    public:
        // Forma canónica
        TComplejo();
        TComplejo(const double re);
        TComplejo(const double re, const double im);
        TComplejo(const TComplejo &tcomp);
        ~TComplejo();
        TComplejo& operator=(const TComplejo &tcomp);

        // Métodos
        // Sobrecarga de operadores ariméticos;
        TComplejo operator- (const TComplejo &tcomp);
        TComplejo operator* (const TComplejo &tcomp);
        TComplejo operator+ (const TComplejo &tcomp);
        TComplejo operator+ (const double num);
        TComplejo operator- (const double num);
        TComplejo operator* (const double num);
        

        // Otros operadores
        bool operator== (const TComplejo &tcomp);
        bool operator!= (const TComplejo &tcomp); 
        double Re(); //Getters
        double Im();
        void Re(const double real); //Setters
        void Im(const double imag); 
        double Arg(); // Calcula el Argumento (en Radianes)
        double Mod(); // Calcula el Módulo
        

        // Funciones amigas
        friend ostream& operator<<(ostream &os, const TComplejo &tcomp);
        
        friend TComplejo operator+ (const double num, const TComplejo &tcomp);
        friend TComplejo operator- (const double num, const TComplejo &tcomp);
        friend TComplejo operator* (const double num, const TComplejo &tcomp);

};
#endif