#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"

#include "vector2D.hh"
#include "matrix2D.hh"
#include "rectangle.hh"
#include <sstream>
#include "size.hh"

TEST_CASE("Test funktora wektora"){
    Vector2D a({2,3.00});

    CHECK( (a[0] == 2.00 && a[1] == 3.00 ) );
}


TEST_CASE("Test funktora wektora"){
    Vector2D  a({2,3.00}),result;

    a[0] = 5.00;
    CHECK( (a[0] == 5.00 && a[1] == 3.00) );
}


TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector2D  a;
    
    CHECK_THROWS( a[SIZE_CO] = 2.00 );
}

TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector2D  a;
    
    CHECK_THROWS( a[-SIZE_CO] = 3.00 );
}


TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector2D  a;
    

    CHECK_THROWS( std::cout << a[SIZE_CO] );
}

TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector2D  a;
    

    CHECK_THROWS( std::cout <<  a[-SIZE_CO] );
}


TEST_CASE("Konstruktor wektora bez argumentu"){
    Vector2D tmpV;
    double test = 0;

    
    for(int i = 0; i < SIZE_CO ; i++){
        if(tmpV[i] != 0 )
          test = -1;
    }
    
    CHECK( !test );
}


TEST_CASE("Konstruktor wektora z argumentem"){
    Vector2D  tmpV({1.00,-3.15});

    CHECK( (tmpV[0] == 1.00 && tmpV[1] == -3.15) );
}




TEST_CASE("Dodawanie dwoch wektorow"){
    Vector2D  a({1.00,2.00}),b({5.00,6.00}),result;

    result = a + b;

    CHECK(  ( result[0] - 6.00 <= 1e-5  && result[1] - 8.00 <=1e-5 )  );
}

TEST_CASE("Dodawanie dwoch wektorow ( bledne )"){
    Vector2D  a({1.00,2.00}),b({5.00,6.00}),result;

    result = a + b;

    CHECK(  !( result[0] - 5.00 <= 1e-5  && result[1] - 7.00 <=1e-5 )  );
}


TEST_CASE("Dodawanie dwoch wektorow"){
    Vector2D  a({-1.31,3.12}),b({5.42,-6.26}),result;

    result = a + b;

    CHECK(  ( result[0] - 4.11 <= 1e-5  && result[1] + 3.14 <= 1e-5 )  );
}


TEST_CASE("Odejmowanie dwoch wektorow"){
    Vector2D  a({2,4.00}),b({0,3.00}),result;

    result = a - b;

    CHECK(  ( result[0] - 2.00 <= 1e-5  && result[1] - 1.00 <= 1e-5 )  );
}


TEST_CASE("Odejmowanie dwoch wektorow (bledne) "){
    Vector2D a({2,3.00}),b({1.00,3.00}),result;

    result = a - b;

    CHECK(  !( result[0] - 1.00 <= 1e-5  && result[1] + 1.00 <= 1e-5 )  );
}


TEST_CASE("Mnozenie wektora przez liczbe "){
    Vector2D  a({2,3.00}),result;

    result = a * 3.2;

    CHECK(  ( result[0] - 6.4 <= 1e-5  && result[1] - 9.60 <= 1e-5 )  );
}


TEST_CASE("Dzielenie wektora przez liczbe "){
    Vector2D  a({2,3.00}),result;

    result = a / 2;

    CHECK(  ( result[0] - 1 <= 1e-5  && result[1] - 1.50 <= 1e-5 )  );
}


TEST_CASE("Dzielenie wektora przez liczbe - wykrwywanie dzielenia przez 0 "){
    Vector2D a({2,3.00}),result;

    CHECK_THROWS( result = a / 0 );
}

TEST_CASE("Obliczanie dlugosci wektora "){
    Vector2D  a({3.00,4.00});
    double result;
    result = a.lenght();

    CHECK( result - 5.00 <= 1e-5 );
}



TEST_CASE("Test przeciazenia << dla wektora"){
    Vector2D  a({10.00,20.000});

    std::ostringstream out;

    out << a;
    std::cout << out.str() << std::endl;
    CHECK( out.str() == "   10.0000000000	   20.0000000000	" );
}



TEST_CASE("Test przeciazenia >> dla wektora"){
    Vector2D  a;
    
    std::istringstream in("10.0 20.0");
    in >> a;
    std::ostringstream out;
    out << a;
    std::cout << out.str() << std::endl;
    
    CHECK( out.str() == "   10.0000000000	   20.0000000000	" );
}



TEST_CASE("Test przeciazenia == dla wektora"){
    Vector2D  a,b;

    double arg1[]={2.1234567890,-12.0987654321};

    a[0] = arg1[0];
    a[1] = arg1[1];
    b[0] = arg1[0];
    b[1] = arg1[1];

    CHECK( a == b );
}


TEST_CASE("Test przeciazenia == dla wektora"){
    Vector2D  a,b;

    double arg1[]={2.1234567890,-12.0987654321};
    double arg2[]={2.1234567892,-12.0987654322};
    
    a[0] = arg1[0];
    a[1] = arg1[1];
    b[0] = arg2[0];
    b[1] = arg2[1];


    CHECK( !(a == b) );
}



TEST_CASE("Test funktora dla macierzy const"){
    Matrix2D  M;

    CHECK( M(0,0) == 1.0 );
}


TEST_CASE("Test funktora dla macierzy"){
    Matrix2D  M;

    M(0,0) = 12.2;

    CHECK(  M(0,0)==12.2  );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres const "){
    Matrix2D  M;

    CHECK_THROWS( std::cout << M(12,1) );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres const"){
    Matrix2D  M;

    CHECK_THROWS( std::cout << M(0,-1) );
}



TEST_CASE("Test funktora dla macierzy wyjscie poza zakres "){
    Matrix2D  M;

    CHECK_THROWS(  M(0,-1) = 2.0 );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres "){
    Matrix2D  M;

    CHECK_THROWS(  M(10,0) = -2.0 );
}

TEST_CASE("Test konstruktora bezparametrycznego dla macierzy"){
    Matrix2D  M;
    int err = 0;

    for(int i = 0; i < SIZE_CO; ++i){
        for(int j = 0; j < SIZE_CO; ++j){
            if(  M(i,j) != 0  ){
                if( i == j && M(i,j) != 1.00 )
                    err++;
            }
        }
    }

    CHECK(!err);
}



TEST_CASE("Test konstruktora parametrycznego dla macierzy"){
    Matrix2D  M;
    double argumentsM[][SIZE_CO] = {{1.0, 2.0},{-3.0, 4.0}};

    M = Matrix2D (argumentsM);
    CHECK( ( M(0,0)==1.0 && M(0,1) == 2.0 && M(1,0) == -3.0 && M(1,1) == 4.0 ) );
}



TEST_CASE("Test mnozenia macierzy przez wektor"){
    Vector2D  a({2.0,3.0}),b,c({8.0,6.0});
    Matrix2D  M;

    double argumentsM[][SIZE_CO] = {{1.0, 2.0},{-3.0, 4.0}};

    M = Matrix2D (argumentsM);
    b = M * a;

    CHECK( c == b );
}



TEST_CASE("Test mnozenia macierzy przez wektor"){
    Vector2D  a({2.0,3.0}),b,c({2.0,3.0});
    Matrix2D  M;

    b = M * a;

    CHECK( b == a );
}

TEST_CASE("Test dodawania macierzy"){
    Matrix2D  M,M0;
    double argumentsM[][SIZE_CO] = {{1.0, 2.0},{-3.0, 4.0}};
    M0 = Matrix2D (argumentsM);

    M = M + M0;

    CHECK( ( M(0,0)==2.0 && M(0,1) == 2.0 && M(1,0) == -3.0 && M(1,1) == 5.0 ) );
}




TEST_CASE("Test przeciazenia >> dla macierzy"){
    Matrix2D  M;
    
    std::istringstream in("10.0 20.0 20.0 -50.0");
    in >> M;
   
    
    CHECK( ( M(0,0)==10.0 && M(0,1) == 20.0 && M(1,0) == 20.0 && M(1,1) == -50.0 )  );
}


TEST_CASE("Test tworzenia macierzy obrotu"){
    Matrix2D  M;

    M.create_rotation( M_PI / 2);

    CHECK( ( M(0,0) < 1e-11 && M(0,1) == -1.00 && M(1,0) == 1.00 && M(1,1) < 1e-11 ) );
}




TEST_CASE("Test funktora dla prostokata const"){
    Rectangle tmpR;
    Vector2D  V;
    CHECK(  tmpR[0] == V );
}


TEST_CASE("Test funktora dla prostokata const"){
    Rectangle tmpR;

    CHECK_THROWS( std::cout << tmpR[15] );
}



TEST_CASE("Test funktora dla prostokata const"){
    Rectangle tmpR;

    CHECK_THROWS( std::cout << tmpR[-15] );
}

TEST_CASE("Test funktora dla prostokata"){
    Rectangle tmpR;
    Vector2D  V,R;
    V[0] = 1;
    V[1] = 2;
    tmpR[0] = V;
    R[0] = 1;
    R[1] = 2;
    CHECK(  tmpR[0] == R  );
}


TEST_CASE("Test funktora dla prostokata"){
    Rectangle tmpR;
    Vector2D  V;
    
    CHECK_THROWS(  tmpR[-1] == V  );
}



TEST_CASE("Test funktora dla prostokata"){
    Rectangle tmpR;
    Vector2D  V;
    
    CHECK_THROWS(  tmpR[14] == V  );
}



TEST_CASE("Test konstruktora bezparametrycznego dla prostokata"){
    Rectangle tmpR;
    Vector2D  V;
    int err = 0;

    for(int i = 0; i < 4; ++i){
        if(tmpR[i] == V)
            err++;
    }
    
    CHECK(  err >=4  );
}



TEST_CASE("Test konstruktora parametrycznego dla prostokata"){
    Rectangle tmpR;
    Vector2D  V1({1,2}),V2({2,1});
    Vector2D  arg[] = {V1,V2,V1,V2};

    tmpR = Rectangle(arg);
    
    CHECK(  (tmpR[0] == V1 && tmpR[1] == V2 && tmpR[2] == V1 && tmpR[3] == V2)  );
}



TEST_CASE("Translacja prostokąta o wektor"){
    Rectangle tmpR;
    Vector2D  trans({ 50.0, 25.0});
    unsigned int times;
    
    Vector2D V1({100.0, 200.0}), V2({500.0, 200.0}), V3({500.0, 600.0}), V4({100.0, 600.0});
    Vector2D  argumentsR[] = {V1,V2,V3,V4};

    tmpR = Rectangle(argumentsR);

    times = 4;

    tmpR.Translate(trans,times);
    Vector2D  R1({300.0, 300.0}), R2({700.0, 300.0}), R3({700.0, 700.0}), R4({300.0, 700.0});

    CHECK(( tmpR[0] == R1 && tmpR[1] == R2 && tmpR[2] == R3 && tmpR[3] == R4) );
}



TEST_CASE("Rotacja prostokata kat dodatni kilka razy"){
    Rectangle tmpR;
    Vector2D  trans;
    unsigned int times;
    Matrix2D  rotation;
    
    Vector2D V1({100.0, 200.0}), V2({500.0, 200.0}), V3({500.0, 600.0}), V4({100.0, 600.0});
    Vector2D  argumentsR[] = {V1,V2,V3,V4};

    tmpR = Rectangle(argumentsR);
    times = 3;

    tmpR.Rotate(90, times, rotation);

    Vector2D R1({200.0, -100.0}), R2({200.0, -500.0}), R3({600.0, -500.0}), R4({600.0, -100.0});

    CHECK(( tmpR[0] == R1 && tmpR[1] == R2 && tmpR[2] == R3 && tmpR[3] == R4) );
}



TEST_CASE("Rotacja prostokata kat ujemny"){
    Rectangle tmpR;
    Vector2D  trans;
    unsigned int times;
    Matrix2D  rotation;
    
    Vector2D V1({100.0, 200.0}), V2({500.0, 200.0}), V3({500.0, 600.0}), V4({100.0, 600.0});
    Vector2D  argumentsR[] = {V1,V2,V3,V4};

    tmpR = Rectangle(argumentsR);
    times = 1;

    tmpR.Rotate(-270, times, rotation);
    Vector2D R1({-200.0, 100.0}), R2({-200.0, 500.0}), R3({-600.0, 500.0}), R4({-600.0, 100.0});

    CHECK(( tmpR[0] == R1 && tmpR[1] == R2 && tmpR[2] == R3 && tmpR[3] == R4) );
}





TEST_CASE("Rotacja prostokata - brak zmiany"){
    Rectangle tmpR;
    Vector2D  trans;
    unsigned int times;
    Matrix2D  rotation;
    
    Vector2D V1({100.0, 200.0}), V2({500.0, 200.0}), V3({500.0, 600.0}), V4({100.0, 600.0});
    Vector2D  argumentsR[] = {V1,V2,V3,V4};

    tmpR = Rectangle(argumentsR);
    times = 5;

    tmpR.Rotate(360, times, rotation);

    Vector2D R1({100.0, 200.0}), R2({500.0, 200.0}), R3({500.0, 600.0}), R4({100.0, 600.0});

    CHECK(( tmpR[0] == R1 && tmpR[1] == R2 && tmpR[2] == R3 && tmpR[3] == R4) );
}






TEST_CASE("Zapis do strumienia zewnetrznego"){
    Vector2D  V1({10.0, 20.0}), V2({50.0, 20.0}), V3({50.0, 60.0}), V4({10.0, 60.0});
    Vector2D  argumentsR[] = {V1,V2,V3,V4};
    Rectangle tmpR(argumentsR);

    std::ostringstream out;

    out << tmpR;
    std::cout << out.str() << std::endl;
    CHECK( out.str() == "   10.0000000000	   20.0000000000	\n   50.0000000000	   20.0000000000	\n   50.0000000000	   60.0000000000	\n   10.0000000000	   60.0000000000	\n");

}



TEST_CASE("Porownanie pierwszych bokow"){
    Vector2D  V1({1,1}), V2({11,1}), V3({11,6}), V4({1,6});
    Vector2D argumentsR[] = {V1,V2,V3,V4};

    Rectangle tmpR = Rectangle(argumentsR);

    CHECK( tmpR.compare_len_a() );
}


TEST_CASE("Porownanie drugich bokow"){
    Vector2D  V1({1,1}), V2({11,1}), V3({11,6}), V4({1,6});
    Vector2D  argumentsR[] = {V1,V2,V3,V4};

    Rectangle tmpR = Rectangle(argumentsR);

    CHECK( tmpR.compare_len_b() );
}


TEST_CASE("Porownanie pierwszych bokow"){
    Vector2D  V1({1,1}), V2({11,1}), V3({11,7}), V4({1,6});
    Vector2D  argumentsR[] = {V1,V2,V3,V4};

    Rectangle tmpR = Rectangle(argumentsR);

    CHECK( !tmpR.compare_len_a() );
}


TEST_CASE("Porownanie pierwszych bokow"){
    Vector2D  V1({1,1}), V2({11,1}), V3({11,7}), V4({1,6});
    Vector2D  argumentsR[] = {V1,V2,V3,V4};

    Rectangle tmpR = Rectangle(argumentsR);

    CHECK( !tmpR.compare_len_b() );
}

