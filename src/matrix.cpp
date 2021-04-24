#include "matrix.hh"





/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if( i == j)
                value[i][j] = 1;
            else
                value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}

/******************************************************************************
 |  Realizuje mnozenie dwoch macierzy                                         |
 |  Argumenty:                                                                |
 |      this - macierz z lewej strony                                         |
 |      tmp - macierz z prawej strony                                         |
 |  Zwraca:                                                                   |
 |      Nowa macierz kwadratowa                                               |
 */
Matrix Matrix::operator * (Matrix tmp){
    Matrix Result;
    double sum;

    for( int i = 0; i < SIZE; ++i){

        for( int j = 0; j < SIZE ; ++j){
            sum = 0;
            for( int k = 0; k < SIZE; ++k){
                sum += value[i][k] * tmp(k,j);
            }
            Result(i,j) = sum;
        }
    }

    return Result;
}




/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      tmp - wektor, czyli drugi skladnik mnozenia.                          |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        throw("Error: Macierz jest poza zasiegiem"); 
    }

    if (column >= SIZE) {
        throw("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        throw("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}





/******************************************************************************
 |  Realizuje tworzenie macierzy rotacji.                                     |
 |  Argumenty:                                                                |
 |      this - macierz zerowa                                                 |
 |      angle - kat obrotu                                                    |
 |  Zwraca:                                                                   |
 |      Macierz z wartosciami odpowiednich funkcji trygonometrycznych         |
 */
void Matrix::create_rotation (double angle){
    value[0][0] = cos(angle);
    value[0][1] = -sin(angle);
    value[1][0] = sin(angle);
    value[1][1] = cos(angle);
}



/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            out << std::setw(16) << std::fixed << std::setprecision(10) << "| " << mat(i, j) << " | ";
        }
        std::cout << std::endl;
    }
    return out;
}






/******************************************************************************
 |  Wyznacznik macierzy                                                       |
 |  Argumenty:                                                                |
 |      this - macierz, ktorej wyznacznik obliczamy                           |
 |  Wynik:                                                                    |
 |       Wyliczenie wyznacznika macierzy metoda eliminacji Gaussa             |
 */
double Matrix::det() const{
    Matrix tmp;
    tmp = *this;
    double ratio, result = 1;
    
    for(int i = 0; i < SIZE -1; ++i){
        if(tmp(i,i) == 0){
            std::cerr << "Macierz osobliwa " << std::endl;
            return 0;
        }
            
        for(int j = i + 1; j < SIZE; ++j){
            ratio = tmp(j,i)/tmp(i,i);
            for( int k = 0; k < SIZE; ++k){
                tmp(j,k) = tmp(j,k) - ratio * tmp(i,k);
            }
        }
    }

    for(int i = 0; i < SIZE; ++i){
        result *= tmp(i,i);
    }

    return result;
}

