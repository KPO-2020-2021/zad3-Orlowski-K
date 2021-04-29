#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>


/*!
 * \brief Opis szablonu klasy Matrix<>
 *  
*/

/*!
 *  \brief Opis klasy
 *  Klasa modeluje pojecie macierzy kwadratowej ( w tym przypadku 2x2).
 *  Liczby macierzy sa przechowywane jako tablica dwuwymiarowa typu
 *  double. Przeciazenia operatorow pozwalaja na modyfikacje i 
 *  dostep do danych macierzy.
 * 
 *  Metody pozwalaja na tworzenie macierzy obrotu oraz iloczyn macierzy
 *  z wektorem.
 */
template <typename Templ_Type, unsigned int Templ_Size>
class Matrix {

private:
    Templ_Type value[Templ_Size][Templ_Size];               // Wartosci macierzy

public:
    Matrix(Templ_Type [Templ_Size][Templ_Size]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Matrix operator * (Matrix tmp);

    Vector<Templ_Type,Templ_Size> operator * (Vector<Templ_Type,Templ_Size> tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    void create_rotation (double angle);

    Templ_Type  &operator () (unsigned int row, unsigned int column);
    
    const Templ_Type &operator () (unsigned int row, unsigned int column) const;

    double det() const;
};


/******************************************************************************
 * ! \brief Konstruktor klasy Matrix.                                         |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <typename Templ_Type, unsigned int Templ_Size>
Matrix<Templ_Type,Templ_Size>::Matrix() {
    for (unsigned int i = 0; i < Templ_Size; i++) {
        for (unsigned int j = 0; j < Templ_Size; j++) {
            if( i == j)
                value[i][j] = 1;
            else
                value[i][j] = 0;
        }
    }
}



/******************************************************************************
 * ! \brief Konstruktor parametryczny klasy Matrix.                           |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <typename Templ_Type, unsigned int Templ_Size>
Matrix<Templ_Type,Templ_Size>::Matrix(Templ_Type tmp[Templ_Size][Templ_Size]) {
    for (unsigned int i = 0; i < Templ_Size; i++) {
        for (unsigned int j = 0; j < Templ_Size; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 * ! \brief Realizuje mnozenie macierzy przez wektor.                         |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      tmp - wektor, czyli drugi skladnik mnozenia.                          |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <typename Templ_Type, unsigned int Templ_Size>
Vector<Templ_Type,Templ_Size> Matrix<Templ_Type,Templ_Size>::operator * (Vector<Templ_Type,Templ_Size> tmp) {
    Vector<Templ_Type,Templ_Size> result;


    for (unsigned int i = 0; i < Templ_Size; i++) {
        for (unsigned int j = 0; j < Templ_Size; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}



/******************************************************************************
 * ! \brief Funktor macierzy                                                  |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <typename Templ_Type, unsigned int Templ_Size>
Templ_Type &Matrix<Templ_Type,Templ_Size>::operator()(unsigned int row, unsigned int column) {

    if (row >= Templ_Size) {
        throw("Error: Macierz jest poza zasiegiem"); 
    }

    if (column >= Templ_Size) {
        throw("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


/******************************************************************************
 * ! \brief Funktor macierzy                                                  |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <typename Templ_Type, unsigned int Templ_Size>
const Templ_Type &Matrix<Templ_Type,Templ_Size>::operator () (unsigned int row, unsigned int column) const {

    if (row >= Templ_Size) {
        throw("Error: Macierz jest poza zasiegiem");
    }

    if (column >= Templ_Size) {
        throw("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}

/******************************************************************************
 * ! \brief Przeciążenie dodawania macierzy                                   |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
template <typename Templ_Type, unsigned int Templ_Size>
Matrix<Templ_Type,Templ_Size> Matrix<Templ_Type,Templ_Size>::operator + (Matrix<Templ_Type,Templ_Size> tmp) {
    Matrix<Templ_Type,Templ_Size> result;
    for (unsigned int i = 0; i < Templ_Size; i++) {
        for (unsigned int j = 0; j < Templ_Size; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}


/******************************************************************************
 * ! \brief Realizuje tworzenie macierzy rotacji.                             |
 |  Argumenty:                                                                |
 |      this - macierz zerowa                                                 |
 |      angle - kat obrotu                                                    |
 |  Zwraca:                                                                   |
 |      Macierz z wartosciami odpowiednich funkcji trygonometrycznych         |
 */
template <typename Templ_Type, unsigned int Templ_Size>
void Matrix<Templ_Type,Templ_Size>::create_rotation (double angle){
    value[0][0] = cos(angle);
    value[0][1] = -sin(angle);
    value[1][0] = sin(angle);
    value[1][1] = cos(angle);
}



/******************************************************************************
 * ! \brief Realizuje mnozenie dwoch macierzy                                 |
 |  Argumenty:                                                                |
 |      this - macierz z lewej strony                                         |
 |      tmp - macierz z prawej strony                                         |
 |  Zwraca:                                                                   |
 |      Nowa macierz kwadratowa                                               |
 */
template <typename Templ_Type, unsigned int Templ_Size>
Matrix<Templ_Type,Templ_Size> Matrix<Templ_Type,Templ_Size>::operator * (Matrix<Templ_Type,Templ_Size> tmp){
    Matrix Result;
    double sum;

    for(unsigned int i = 0; i < Templ_Size; ++i){

        for(unsigned int j = 0; j < Templ_Size ; ++j){
            sum = 0;
            for(unsigned int k = 0; k < Templ_Size; ++k){
                sum += value[i][k] * tmp(k,j);
            }
            Result(i,j) = sum;
        }
    }

    return Result;
}


/******************************************************************************
 * ! \brief Przeciazenie operatora >>                                         |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                        |
 */
template <typename Templ_Type, unsigned int Templ_Size>
std::istream &operator>>(std::istream &in, Matrix<Templ_Type,Templ_Size> &mat) {
    for (unsigned int i = 0; i < Templ_Size; i++) {
        for (unsigned int j = 0; j < Templ_Size; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}

/******************************************************************************
 * ! \brief Przeciazenie operatora <<                                         |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template <typename Templ_Type, unsigned int Templ_Size>
std::ostream &operator<<(std::ostream &out, const Matrix<Templ_Type,Templ_Size> &mat) {
    for (unsigned int i = 0; i < Templ_Size; i++) {
        for (unsigned int j = 0; j < Templ_Size; j++) {
            out << std::setw(16) << std::fixed << std::setprecision(10) << "| " << mat(i, j) << " | ";
        }
        std::cout << std::endl;
    }
    return out;
}


/******************************************************************************
 * ! \brief Wyznacznik macierzy                                               |
 |  Argumenty:                                                                |
 |      this - macierz, ktorej wyznacznik obliczamy                           |
 |  Wynik:                                                                    |
 |       Wyliczenie wyznacznika macierzy metoda eliminacji Gaussa             |
 */
template <typename Templ_Type, unsigned int Templ_Size>
double Matrix<Templ_Type,Templ_Size>::det() const{
    Matrix<Templ_Type,Templ_Size> tmp;
    tmp = *this;
    double ratio, result = 1;
    
    for(unsigned int i = 0; i < Templ_Size -1; ++i){
        if(tmp(i,i) == 0){
            std::cerr << "Macierz osobliwa " << std::endl;
            return 0;
        }
            
        for(unsigned int j = i + 1; j < Templ_Size; ++j){
            ratio = tmp(j,i)/tmp(i,i);
            for(unsigned int k = 0; k < Templ_Size; ++k){
                tmp(j,k) = tmp(j,k) - ratio * tmp(i,k);
            }
        }
    }

    for(unsigned int i = 0; i < Templ_Size; ++i){
        result *= tmp(i,i);
    }

    return result;
}
