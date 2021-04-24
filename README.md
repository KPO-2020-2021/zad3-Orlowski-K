## Overlook

!!!UWAGA!!!

Program pokazuje nakladanie sie bledu wynikajacego ze skonczonej reprezentacji,
ale blad ten rosnie wolniej niz w opisie zadania.

Im wieksza ilosc powtorzen, tym blad bedzie bardziej widoczny, ale program bedzie
sie wykonywal odpowiednio dlugo. Przy obrocie o 1 stopien 360 000 000 blad jest
bardziej widoczny, ale wykonywanie trwa ok 1min.

W przypadku, gdy za  1 razem nie wyswietli sie cala dlugosc jednego z bokow 
nalezy wyswietlic wierzcholki za pomoca w.

!!!!!


Program obsluguje obrot i translacje prostokata w 2D.
W bazowej wersji prostokat jest predefiniowany. Mozliwa jest opcja wpisywania recznego.
Nalezy wtedy usunac odpoiwednie komentarze w pliku main.cpp i zakomentowac definiowanie
automatyczne. Wpisywanie absurdalnie wielkich liczb moze spowodowac nieoczekiwane rezultaty.

Wyliczanie wyznacznika i skalowalnosc programu jest przedstawiona na koncu programu.
Aby sprawdzic skalowalnosc nalezy zmienic wartosc SIZE w pliku size.hh
Po zmianie wyznacznik bedzie zle liczony, poniewaz macierz bedzie osobliwa. 


## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

``` bash
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```


