#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"

#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
#include <sstream>

TEST_CASE("Test funktora wektora"){
    Vector a,result;
    double arg1[] = {2,3.00};

    a = Vector(arg1);

    CHECK( (a[0] == 2.00 && a[1] == 3.00 ) );
}


TEST_CASE("Test funktora wektora"){
    Vector a,result;
    double arg1[] = {2,3.00};

    a = Vector(arg1);
    a[0] = 5.00;

    CHECK( (a[0] == 5.00 && a[1] == 3.00) );
}


TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector a;
    
    CHECK_THROWS( a[SIZE] = 2.00 );
}

TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector a;
    
    CHECK_THROWS( a[-SIZE] = 3.00 );
}


TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector a;
    

    CHECK_THROWS( std::cout << a[SIZE] );
}

TEST_CASE("Test funktora wektora - wyjscie poza zakres"){
    Vector a;
    

    CHECK_THROWS( std::cout <<  a[-SIZE] );
}


TEST_CASE("Konstruktor wektora bez argumentu"){
    Vector tmpV;
    double test = 0;

    
    for(int i = 0; i < SIZE ; i++){
        if(tmpV[i] != 0 )
          test = -1;
    }
    
    CHECK( !test );
}


TEST_CASE("Konstruktor wektora z argumentem"){
    Vector tmpV;

    double arguments[] = {1.00,-3.15};

    tmpV = Vector(arguments);
    
    CHECK( (tmpV[0] == 1.00 && tmpV[1] == -3.15) );
}




TEST_CASE("Dodawanie dwoch wektorow"){
    Vector a,b,result;
    double arg1[] = {1.00,2.00}, arg2[] = {5.00,6.00};

    a = Vector(arg1);
    b = Vector(arg2);

    result = a + b;

    CHECK(  ( result[0] - 6.00 <= 1e-5  && result[1] - 8.00 <=1e-5 )  );
}

TEST_CASE("Dodawanie dwoch wektorow ( bledne )"){
    Vector a,b,result;
    double arg1[] = {1.00,2.00}, arg2[] = {5.00,6.00};

    a = Vector(arg1);
    b = Vector(arg2);

    result = a + b;

    CHECK(  !( result[0] - 5.00 <= 1e-5  && result[1] - 7.00 <=1e-5 )  );
}


TEST_CASE("Dodawanie dwoch wektorow"){
    Vector a,b,result;
    double arg1[] = {-1.31,3.12}, arg2[] = {5.42,-6.26};

    a = Vector(arg1);
    b = Vector(arg2);

    result = a + b;

    CHECK(  ( result[0] - 4.11 <= 1e-5  && result[1] + 3.14 <= 1e-5 )  );
}


TEST_CASE("Odejmowanie dwoch wektorow"){
    Vector a,b,result;
    double arg1[] = {2,4.00}, arg2[] = {0,3.00};

    a = Vector(arg1);
    b = Vector(arg2);

    result = a - b;

    CHECK(  ( result[0] - 2.00 <= 1e-5  && result[1] - 1.00 <= 1e-5 )  );
}


TEST_CASE("Odejmowanie dwoch wektorow (bledne) "){
    Vector a,b,result;
    double arg1[] = {2,3.00}, arg2[] = {1.00,3.00};

    a = Vector(arg1);
    b = Vector(arg2);

    result = a - b;

    CHECK(  !( result[0] - 1.00 <= 1e-5  && result[1] + 1.00 <= 1e-5 )  );
}


TEST_CASE("Mnozenie wektora przez liczbe "){
    Vector a,result;
    double arg1[] = {2,3.00};

    a = Vector(arg1);

    result = a * 3.2;

    CHECK(  ( result[0] - 6.4 <= 1e-5  && result[1] - 9.60 <= 1e-5 )  );
}


TEST_CASE("Dzielenie wektora przez liczbe "){
    Vector a,result;
    double arg1[] = {2,3.00};

    a = Vector(arg1);

    result = a / 2;

    CHECK(  ( result[0] - 1 <= 1e-5  && result[1] - 1.50 <= 1e-5 )  );
}


TEST_CASE("Dzielenie wektora przez liczbe - wykrwywanie dzielenia przez 0 "){
    Vector a,result;
    double arg1[] = {2,3.00};

    a = Vector(arg1);

    CHECK_THROWS( result = a / 0 );
}

TEST_CASE("Obliczanie dlugosci wektora "){
    Vector a;
    double arg1[] = {3.00,4.00}, result;

    a = Vector(arg1);
    result = a.lenght();

    CHECK( result - 5.00 <= 1e-5 );
}



TEST_CASE("Test przeciazenia << dla wektora"){
    Vector a;
    double arg1[] = {10.00,20.000};

    a = Vector(arg1);

    std::ostringstream out;

    out << a;
    std::cout << out.str() << std::endl;
    CHECK( out.str() == "   10.0000000000	   20.0000000000	" );
}



TEST_CASE("Test przeciazenia >> dla wektora"){
    Vector a;
    
    std::istringstream in("10.0 20.0");
    in >> a;
    std::ostringstream out;
    out << a;
    std::cout << out.str() << std::endl;
    
    CHECK( out.str() == "   10.0000000000	   20.0000000000	" );
}



TEST_CASE("Test przeciazenia == dla wektora"){
    Vector a,b;

    double arg1[]={2.1234567890,-12.0987654321};

    a[0] = arg1[0];
    a[1] = arg1[1];
    b[0] = arg1[0];
    b[1] = arg1[1];

    CHECK( a == b );
}


TEST_CASE("Test przeciazenia == dla wektora"){
    Vector a,b;

    double arg1[]={2.1234567890,-12.0987654321};
    double arg2[]={2.1234567892,-12.0987654322};
    
    a[0] = arg1[0];
    a[1] = arg1[1];
    b[0] = arg2[0];
    b[1] = arg2[1];


    CHECK( !(a == b) );
}



TEST_CASE("Test funktora dla macierzy const"){
    Matrix M;

    CHECK( M(0,0) == 1.0 );
}


TEST_CASE("Test funktora dla macierzy"){
    Matrix M;

    M(0,0) = 12.2;

    CHECK(  M(0,0)==12.2  );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres const "){
    Matrix M;

    CHECK_THROWS( std::cout << M(12,1) );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres const"){
    Matrix M;

    CHECK_THROWS( std::cout << M(0,-1) );
}



TEST_CASE("Test funktora dla macierzy wyjscie poza zakres "){
    Matrix M;

    CHECK_THROWS(  M(0,-1) = 2.0 );
}


TEST_CASE("Test funktora dla macierzy wyjscie poza zakres "){
    Matrix M;

    CHECK_THROWS(  M(10,0) = -2.0 );
}

TEST_CASE("Test konstruktora bezparametrycznego dla macierzy"){
    Matrix M;
    int err = 0;

    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            if(  M(i,j) != 0  ){
                if( i == j && M(i,j) != 1.00 )
                    err++;
            }
        }
    }

    CHECK(!err);
}



TEST_CASE("Test konstruktora parametrycznego dla macierzy"){
    Matrix M;
    double argumentsM[][SIZE] = {{1.0, 2.0},{-3.0, 4.0}};

    M = Matrix(argumentsM);
    CHECK( ( M(0,0)==1.0 && M(0,1) == 2.0 && M(1,0) == -3.0 && M(1,1) == 4.0 ) );
}



TEST_CASE("Test mnozenia macierzy przez wektor"){
    Vector a,b,c;
    Matrix M;

    double argumentsM[][SIZE] = {{1.0, 2.0},{-3.0, 4.0}};
    double argumentsV[] = {2.0,3.0};
    double results[] = {8.0,6.0};

    M = Matrix(argumentsM);
    a = Vector(argumentsV);
    c = Vector(results);
    b = M * a;

    CHECK( c == b );
}



TEST_CASE("Test mnozenia macierzy przez wektor"){
    Vector a,b,c;
    Matrix M;

    double argumentsV[] = {2.0,3.0};
    double results[] = {2.0,3.0};

    a = Vector(argumentsV);
    c = Vector(results);
    b = M * a;

    CHECK( b == a );
}

TEST_CASE("Test dodawania macierzy"){
    Matrix M,M0;
    double argumentsM[][SIZE] = {{1.0, 2.0},{-3.0, 4.0}};
    M0 = Matrix(argumentsM);

    M = M + M0;

    CHECK( ( M(0,0)==2.0 && M(0,1) == 2.0 && M(1,0) == -3.0 && M(1,1) == 5.0 ) );
}




TEST_CASE("Test przeciazenia >> dla macierzy"){
    Matrix M;
    
    std::istringstream in("10.0 20.0 20.0 -50.0");
    in >> M;
   
    
    CHECK( ( M(0,0)==10.0 && M(0,1) == 20.0 && M(1,0) == 20.0 && M(1,1) == -50.0 )  );
}


TEST_CASE("Test tworzenia macierzy obrotu"){
    Matrix M;

    M.create_rotation( M_PI / 2);

    CHECK( ( M(0,0) < 1e-11 && M(0,1) == -1.00 && M(1,0) == 1.00 && M(1,1) < 1e-11 ) );
}




TEST_CASE("Test funktora dla prostokata const"){
    Rectangle tmpR;
    Vector V;
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
    Vector V,R;
    V[0] = 1;
    V[1] = 2;
    tmpR[0] = V;
    R[0] = 1;
    R[1] = 2;
    CHECK(  tmpR[0] == R  );
}


TEST_CASE("Test funktora dla prostokata"){
    Rectangle tmpR;
    Vector V;
    
    CHECK_THROWS(  tmpR[-1] == V  );
}



TEST_CASE("Test funktora dla prostokata"){
    Rectangle tmpR;
    Vector V;
    
    CHECK_THROWS(  tmpR[14] == V  );
}



TEST_CASE("Test konstruktora bezparametrycznego dla prostokata"){
    Rectangle tmpR;
    Vector V;
    int err = 0;

    for(int i = 0; i < 4; ++i){
        if(tmpR[i] == V)
            err++;
    }
    
    CHECK(  err >=4  );
}



TEST_CASE("Test konstruktora parametrycznego dla prostokata"){
    Rectangle tmpR;
    Vector V1,V2;
    double argV1[] = {1,2}, argV2[] = {2,1};
    V1 = Vector(argV1);
    V2 = Vector(argV2);
    Vector arg[] = {V1,V2,V1,V2};

    tmpR = Rectangle(arg);
    
    CHECK(  (tmpR[0] == V1 && tmpR[1] == V2 && tmpR[2] == V1 && tmpR[3] == V2)  );
}



TEST_CASE("Translacja prostokąta o wektor"){
    Rectangle tmpR;
    Vector trans;
    unsigned int times;
    


    double arg1[] = {100.0, 200.0};
    double arg2[] = {500.0, 200.0};
    double arg3[] = {500.0, 600.0};
    double arg4[] = {100.0, 600.0};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};
    double arg[] = { 50.0, 25.0};

    tmpR = Rectangle(argumentsR);
    trans = Vector(arg);
    times = 4;

    tmpR.Translate(trans,times);

    double res1[] = {300.0, 300.0};
    double res2[] = {700.0, 300.0};
    double res3[] = {700.0, 700.0};
    double res4[] = {300.0, 700.0};
    Vector R1 = Vector(res1), R2 = Vector(res2), R3 = Vector(res3), R4 = Vector(res4);

    CHECK(( tmpR[0] == R1 && tmpR[1] == R2 && tmpR[2] == R3 && tmpR[3] == R4) );
}



TEST_CASE("Rotacja prostokata kat dodatni kilka razy"){
    Rectangle tmpR;
    Vector trans;
    unsigned int times;
    Matrix rotation;
    


    double arg1[] = {100.0, 200.0};
    double arg2[] = {500.0, 200.0};
    double arg3[] = {500.0, 600.0};
    double arg4[] = {100.0, 600.0};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};

    tmpR = Rectangle(argumentsR);
    times = 3;

    tmpR.Rotate(90, times, rotation);

    double res1[] = {200.0, -100.0};
    double res2[] = {200.0, -500.0};
    double res3[] = {600.0, -500.0};
    double res4[] = {600.0, -100.0};
    Vector R1 = Vector(res1), R2 = Vector(res2), R3 = Vector(res3), R4 = Vector(res4);

    CHECK(( tmpR[0] == R1 && tmpR[1] == R2 && tmpR[2] == R3 && tmpR[3] == R4) );
}



TEST_CASE("Rotacja prostokata kat ujemny"){
    Rectangle tmpR;
    Vector trans;
    unsigned int times;
    Matrix rotation;
    


    double arg1[] = {100.0, 200.0};
    double arg2[] = {500.0, 200.0};
    double arg3[] = {500.0, 600.0};
    double arg4[] = {100.0, 600.0};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};

    tmpR = Rectangle(argumentsR);
    times = 1;

    tmpR.Rotate(-270, times, rotation);

    double res1[] = {-200.0, 100.0};
    double res2[] = {-200.0, 500.0};
    double res3[] = {-600.0, 500.0};
    double res4[] = {-600.0, 100.0};
    Vector R1 = Vector(res1), R2 = Vector(res2), R3 = Vector(res3), R4 = Vector(res4);

    CHECK(( tmpR[0] == R1 && tmpR[1] == R2 && tmpR[2] == R3 && tmpR[3] == R4) );
}





TEST_CASE("Rotacja prostokata - brak zmiany"){
    Rectangle tmpR;
    Vector trans;
    unsigned int times;
    Matrix rotation;
    


    double arg1[] = {100.0, 200.0};
    double arg2[] = {500.0, 200.0};
    double arg3[] = {500.0, 600.0};
    double arg4[] = {100.0, 600.0};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};

    tmpR = Rectangle(argumentsR);
    times = 5;

    double res1[] = {100.0, 200.0};
    double res2[] = {500.0, 200.0};
    double res3[] = {500.0, 600.0};
    double res4[] = {100.0, 600.0};
    tmpR.Rotate(360, times, rotation);

    Vector R1 = Vector(res1), R2 = Vector(res2), R3 = Vector(res3), R4 = Vector(res4);

    CHECK(( tmpR[0] == R1 && tmpR[1] == R2 && tmpR[2] == R3 && tmpR[3] == R4) );
}






TEST_CASE("Zapis do strumienia zewnetrznego"){
    double arg1[] = {10.0, 20.0};
    double arg2[] = {50.0, 20.0};
    double arg3[] = {50.0, 60.0};
    double arg4[] = {10.0, 60.0};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};
    Rectangle tmpR(argumentsR);

    std::ostringstream out;

    out << tmpR;
    std::cout << out.str() << std::endl;
    CHECK( out.str() == "   10.0000000000	   20.0000000000	\n   50.0000000000	   20.0000000000	\n   50.0000000000	   60.0000000000	\n   10.0000000000	   60.0000000000	\n");

}



TEST_CASE("Porownanie pierwszych bokow"){
    double arg1[] = {1,1};
    double arg2[] = {11,1};
    double arg3[] = {11,6};
    double arg4[] = {1,6};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};

    Rectangle tmpR = Rectangle(argumentsR);

    CHECK( tmpR.compare_len_a() );
}


TEST_CASE("Porownanie drugich bokow"){
    double arg1[] = {1,1};
    double arg2[] = {11,1};
    double arg3[] = {11,6};
    double arg4[] = {1,6};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};

    Rectangle tmpR = Rectangle(argumentsR);

    CHECK( tmpR.compare_len_b() );
}


TEST_CASE("Porownanie pierwszych bokow"){
    double arg1[] = {1,1};
    double arg2[] = {11,1};
    double arg3[] = {11,7};
    double arg4[] = {1,6};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};

    Rectangle tmpR = Rectangle(argumentsR);

    CHECK( !tmpR.compare_len_a() );
}


TEST_CASE("Porownanie pierwszych bokow"){
    double arg1[] = {1,1};
    double arg2[] = {11,1};
    double arg3[] = {11,7};
    double arg4[] = {1,6};
    Vector V1 = Vector(arg1), V2 = Vector(arg2), V3 = Vector(arg3), V4 = Vector(arg4);
    Vector argumentsR[] = {V1,V2,V3,V4};

    Rectangle tmpR = Rectangle(argumentsR);

    CHECK( !tmpR.compare_len_b() );
}

