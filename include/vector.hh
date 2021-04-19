#pragma once

#include "size.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>




/*!
 *  Klasa opisujaca wektor w przestrzeni ( w tym przypadku w 2 wymiarach ).
 *  Za jego pomoca opisywane sa wierzcholki dowolnej figury jako wektory
 *  o poczatku w poczatku ukladu wspolrzednych. Wektory skladaja sie z 
 *  tablicy typu double, w ktorej przechowywane sa kolejne skladowe.
 * 
 *  Dla klasy zdefiniowano podstawowe przeciazenia operatorow pozwalajace
 *  na korzystanie z danych, ich modyfikacje oraz podstawowa arytmetyke 
 *  wektorowa.
 */
class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    Vector operator + (const Vector &v);

    Vector operator - (const Vector &v) const;

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    bool   operator == (const Vector &V2) const;

    const double &operator [] (int index) const;

    double &operator [] (int index);

    double lenght() const;

};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);


