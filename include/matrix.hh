#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>




/*!
 *  Klasa modeluje pojecie macierzy kwadratowej ( w tym przypadku 2x2).
 *  Liczby macierzy sa przechowywane jako tablica dwuwymiarowa typu
 *  double. Przeciazenia operatorow pozwalaja na modyfikacje i 
 *  dostep do danych macierzy.
 * 
 *  Metody pozwalaja na tworzenie macierzy obrotu oraz iloczyn macierzy
 *  z wektorem.
 */
class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector operator * (Vector tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    void create_rotation (double angle);

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;
};

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);



