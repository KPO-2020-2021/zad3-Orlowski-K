// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia( std::ostream&     StrmWy, 
                                              double       Przesuniecie
                                            )
{
   //---------------------------------------------------------------
   // To tylko przyklad !!!
   // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych 
   // zmiennych do reprezentowania wspolrzednych!
   //
  double  x1, y1, x2, y2, x3, y3, x4, y4; 

  x1 = y1 = 10;
  x2 = x1 + DL_DLUGI_BOK;  y2 = y1;
  x3 = x2;  y3 = y2 + DL_KROTKI_BOK;
  x4 = x3 - DL_DLUGI_BOK; y4 = y3;


  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x1+Przesuniecie 
         << std::setw(16) << std::fixed << std::setprecision(10) << y1+Przesuniecie << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x2+Przesuniecie 
         << std::setw(16) << std::fixed << std::setprecision(10) << y2+Przesuniecie << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x3+Przesuniecie 
         << std::setw(16) << std::fixed << std::setprecision(10) << y3+Przesuniecie << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x4+Przesuniecie 
         << std::setw(16) << std::fixed << std::setprecision(10) << y4+Przesuniecie << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x1+Przesuniecie 
         << std::setw(16) << std::fixed << std::setprecision(10) << y1+Przesuniecie << std::endl; 
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         double       Przesuniecie
                                       )
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, Przesuniecie);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

/* Funkcja wyswietlajaca MENU */
void  MENU(){
   std::cout << " o - obrot prostokata o zadany kat" <<std::endl;
   std::cout << " p - przesuniecie prostokata o zadany wektor" <<std::endl;
   std::cout << " w - wyswietlenie wspolrzednych wierzcholkow" <<std::endl;
   std::cout << " m - wyswietl menu" <<std::endl;
   std::cout << " k - koniec dzialania programu\n" <<std::endl;
}







int main() {
  std::cout << "Project 2D Rotation based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl <<std::endl;

    Rectangle object;
    Vector translator;
    Matrix rotator;
    char option[1] ,repeat[1];
    double angle;
    unsigned int times;
    std::ofstream File;
    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

    std::cout << "Prosze podac prostokat jako 4 wektory od lewego dolnego\nprzeciwnie do wskazowek zegara\ntzn. 4 pary liczb x i y " << std::endl;
    std::cin >> object;
    
    while( !(object.compare_len_a() && object.compare_len_b()) ){
       std::cerr << "To raczej nie jest prostokat!!" << std::endl;
       std::cout << "Czy chcesz sprobowac ponownie? [T/N] : ";
       std::cin >> repeat;
       if(repeat[0] != 'T')
          exit(1);
       std::cin >> object; 
    }
    std::cin.ignore(100000,'\n');
    std::cin.clear();
    


    Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);

    Lacze.ZmienTrybRys(PzG::TR_2D);
    File << object;
    Lacze.Rysuj();
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000,'\n');


    MENU();
    
    while( option[0] != 'k'){
      std::cout << "Twoj wybor? (m - menu) >  ";
      std::cin >> option;
      switch(option[0]){
       
          case 'o' :
              std::cout << "Podaj wartosc kata obrotu w stopniach: ";
              std::cin >> angle;
              std::cout << "Ile razy nalezy powtorzyc operacje? ";
              std::cin >> times;
              object.Rotate(angle,times,rotator);
              Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
              Lacze.ZmienTrybRys(PzG::TR_2D);
              File << object;
              Lacze.Rysuj();
              std::cin.ignore(100000,'\n');
              object.compare_len_a();
              object.compare_len_b();
              break;
          case 'm' :
              MENU();
              break;
          case 'p' :
              std::cout << std::endl;
              std::cout << "Podaj wspolrzedne wektora translacji w postaci dwoch liczb\ntzn. wspolrzednej x oraz wspolrzednej y\n";
              std::cin >> translator;
              std::cout << "Ile razy przesunac?  ";
              std::cin >> times;
              object.Translate(translator,times);
              break;
          case 'w':
              std::cout << object;
              object.compare_len_a();
              object.compare_len_b();
              break;;
          default :
              exit(1);
      }
    }
}
