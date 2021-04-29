#pragma once

#include "size.hh"
#include "matrix2D.hh"
#include "vector2D.hh"
#include <iostream>
#include <fstream>



/*!
*   \file
*   \brief Opis klasy Rectangle
*/


/*********************************************************************
 * ! \brief Opis klasy                                               |
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

    Vector2D value[4];

  public:

    Rectangle(Vector2D tmp[4]);

    Rectangle();

    const Vector2D &operator [] (int index) const;

    Vector2D &operator [] (int index);

    void Translate (Vector2D &tmp, unsigned int times);

    void Rotate (double angle, unsigned int times, Matrix2D &r_Matrix);

    bool compare_len_a() const;

    bool compare_len_b() const;


};

std::ostream& operator << ( std::ostream &out, const Rectangle &tmp );


std::ofstream& operator << ( std::ofstream &out, const Rectangle &tmp );

std::istream& operator >> (std::istream &in, Rectangle &tmp );



