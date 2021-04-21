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
        throw( "Error: Wierzholek jest poza zasiegiem!" );
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
        throw ("Error: Wierzholek jest poza zasiegiem!");
    }
    return value[index];
}



/********************************************************************
 | Realizuje translacje o podany wektor                             |
 | Argumenty:                                                       |
 |    Zadany prostokat;                                             |
 |    tmp  - wektor translacji;                                     |
 |    times - ilosc powtorzen                                       |
 |  Wynik dzialania:                                                |
 |    Dodanie do kazdego wektora prostokata wektora translacji.     |
 |    W ten sposob prostokat jest przesuwany.                       |
 */
void Rectangle::Translate (Vector &tmp,  unsigned int times){
    tmp = tmp * times;
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
   
    period = angle * times / 360;
    angle = angle*times - period*360;
    r_Matrix.create_rotation(angle * M_PI / 180);

    for(int i = 0; i < 4; ++i){
        value[i] = r_Matrix * value[i];
    }
    
}

bool  Rectangle::compare_len_a() const{
    Vector a,b;
    double len1,len2;
    
    a = value[1] - value[0];
    b = value[2] - value[3];
    len1 = a.lenght();
    len2 = b.lenght();
    std::cout << std::endl;
    if(fabs(len1 - len2 ) <= 1e-11){
        std::cout << "Pierwsze przeciwlegle boki sa rowne." << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "  Dlugosc drugiego boku: " << len2 << std::endl << std::endl;
        
    }
    else{
        std::cout << "Pierwsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << "  Dlugosc drugiego boku: " << len2 << std::endl << std::endl;
        return false;
    }
    
    return true;
}


bool  Rectangle::compare_len_b() const{
    Vector a,b;
    double len1,len2;
    a = value[3] - value[0];
    len1 = a.lenght();
    b = value[2] - value[1];
    len2 = b.lenght();
    
    if(fabs(len1 - len2 ) <= 1e-11){
        std::cout << "Drugie przeciwlegle boki sa rowne." << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) << "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<"  Dlugosc drugiego boku: " << len2 << std::endl << std::endl;
        
    }
    else{
        std::cout << "Drugie przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "Dlugosc pierwszego boku: " << len1 << std::endl;
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) <<  "  Dlugosc drugiego boku: " << len2 << std::endl << std::endl;
        return false;
    }
    
    return true;
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



std::ofstream& operator << ( std::ofstream &outfile, const Rectangle &tmp ){
    
    outfile.open(FILENAME);
    if (!outfile.is_open())  {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << FILENAME << "\"" << std::endl
	    << ":(  nie powiodla sie." << std::endl;
        exit(0);
    }


    for(int i = 0; i < 4 ; i++){
        outfile << tmp[i] << std::endl;
    }

    outfile << tmp[0];
    outfile.close();


    return outfile;

}






std::istream& operator >> (std::istream &in, Rectangle &tmp ){
    for(int i = 0; i < 4; ++i){
        in >> tmp[i];
    }

    return in;
}
