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
        TComplejo(const double re = 0.0, const double im = 0.0);
        TComplejo(const TComplejo &tcomp);
        ~TComplejo();
        TComplejo& operator=(const TComplejo &tcomp);

        // Métodos
        // Sobrecarga de operadores ariméticos;
        TComplejo operator-(const TComplejo &tcomp) const;
        TComplejo operator*(const TComplejo &tcomp) const;
        TComplejo operator+(const TComplejo &tcomp) const;
        TComplejo operator+(const double num) const;
        TComplejo operator-(const double num) const;
        TComplejo operator*(const double num) const;
        

        // Otros operadores
        bool operator==(const TComplejo &tcomp) const;
        bool operator!=(const TComplejo &tcomp) const; 
        double Re() const; //Getters
        double Im() const;
        void Re(const double real); //Setters
        void Im(const double imag); 
        double Arg() const; // Calcula el Argumento (en Radianes)
        double Mod() const; // Calcula el Módulo
        

        // Funciones amigas
        friend ostream& operator<<(ostream &os, const TComplejo &tcomp);
        
        friend TComplejo operator+ (const double num, const TComplejo &tcomp);
        friend TComplejo operator- (const double num, const TComplejo &tcomp);
        friend TComplejo operator* (const double num, const TComplejo &tcomp);

};
#endif