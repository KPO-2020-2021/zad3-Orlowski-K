#pragma once

#include "size.hh"
#include "matrix.hh"
#include <iostream>


/*********************************************************************
 |  Klasa modeluje pojecie prostokata jako zbioru czterech           |
 |  wierzcholkow przedstawionych jako wektory 2D. Dane sa            |
 |  przechowywane w tablicy typu Wektor2D, wiec klasa korzysta       |
 |  bezposrednio z innej klasy.                                      |
 |                                                                   |
 |  Przeciazenia operatorow pozwalaja na dostep i modyfikacje        |
 |  danych. Zdefiniowane metody pozwalaja na translacje o            |
 |  zadany wektor, obrot wzgledem macierzy obrotu i obliczenie       |
 |  dlugosci bokow.                                                  |
 */
class Rectangle {
  private:

    Vector value[4];

  public:

    Rectangle(Vector [4]);

    Rectangle();

    const Vector &operator [] (int index) const;

    Vector &operator [] (int index);

    void Translate (const Vector &tmp);

    void Rotate (double angle, unsigned int times, Matrix &r_Matrix);

    double len_a() const;

    double len_b() const;   
};

std::ostream& operator << ( std::ostream &out, const Rectangle &tmp );





