#include "rectangle.hh"




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
 |      Wartosc wierzcholka w danym miejscu tablicy jako wektor staly.        |
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
void Rectangle::Rotate (double angle, unsigned int times, Matrix &r_Matrix){
    int period;
    period = angle / 360;
    angle -= period*360;
    period = angle * times / 360;
    angle -= period * 360;

    r_Matrix.create_rotation(angle * M_PI / 180);

    for(int i = 0; i < 4; ++i){
        value[i] = r_Matrix * value[i];
    }
    
}

double  Rectangle::len_a() const{
    double result;
    Vector tmp;

    tmp = value[1] - value[0];
    result = tmp.lenght();
    return result;
}


double  Rectangle::len_b() const{
    double result;
    Vector tmp;

    tmp = value[3] - value[0];
    result = tmp.lenght();
    return result;
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
