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

    void Rotate (Matrix tmp);

    double len_short() const;

    double len_long() const;   
};

std::ostream& operator << ( std::ostream &out, const Rectangle &tmp );



/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Rectangle::Rectangle() {
    for (int i = 0; i < 4 ; i++) {
        value[i] = Vector();
    }
}



/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu Vector                              |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie                  |
 */ 
Rectangle::Rectangle(Vector tmp[4]) {
    for (int i = 0; i < 4 ; i++) {
        value[i] = tmp[i];
    }
}


/******************************************************************************
 |  Funktor prostokata.                                                       |
 |  Argumenty:                                                                |
 |      index - index wierzcholka.                                            |
 |  Zwraca:                                                                   |
 |      Wartosc wierzcholka w danym miejscu tablicy jako wektor staly.        |
 */
const Vector &Rectangle::operator [] (int index) const {
    if (index < 0 || index >= 4) {
        std::cerr << "Error: Wierzholek jest poza zasiegiem!" << std::endl;
    }
    return value[index];
}



/******************************************************************************
 |  Funktor prostokata.                                                       |
 |  Argumenty:                                                                |
 |      index - index wierzcholka.                                            |
 |  Zwraca:                                                                   |
 |      Wartosc wierzcholka w danym miejscu tablicy jako wektor staly.               |
 */
 Vector &Rectangle::operator [] (int index) {
    if (index < 0 || index >= 4) {
        std::cerr << "Error: Wierzholek jest poza zasiegiem!" << std::endl;
    }
    return value[index];
}



/********************************************************************
 | Realizuje translacje o podany wektor                             |
 | Argumenty:                                                       |
 |    Zadany prostokat;                                             |
 |    W_trans  - wektor translacji;                                 |
 |  Wynik dzialania:                                                |
 |    Dodanie do kazdego wektora prostokata wektora translacji.     |
 |    W ten sposob prostokat jest przesuwany.                       |
 */
void Rectangle::Translate (const Vector &tmp){
    for(int i = 0; i < 4; i ++){
        value[i] = value[i] + tmp;
    }
}



/************************************************************************
 * Realizuje translacje o podana macierz obrotu                         |         
 * Argumenty:                                                           |
 *    Zadany prostokat;                                                 |
 *    M_obr  - macierz obrotu;                                          |
 *  Wynik dzialania:                                                    |
 *    Mnozenie wektorow opisujacych wierzcholki z macierza obrotu       |
 *    W ten sposob prostokat jest obracany.                             |
 */
void Rectangle::Rotate (Matrix tmp){
    for(int i = 0; i < 4; i ++){
        value[i] = tmp * value[i];
    }
}




/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wyjsciowy,                                             |
 |      tmp - prostokat.                                                      |
 */
std::ostream& operator << ( std::ostream &out, const Rectangle &tmp ){
    for(int i = 0; i < 4 ; i++){
        out << tmp[i] << std::endl;
    }
    return out;
}


