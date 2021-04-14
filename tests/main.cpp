#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"

#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
#include <sstream>

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.



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


TEST_CASE("Konstruktor wektora bez argumentu"){
    Vector tmpV;
    double test = 0;

    tmpV = Vector();
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
    double arg1[] = {10.00,20.000};

    a = Vector(arg1);

    std::ostringstream out;

    out << a;
    std::cout << out.str() << std::endl;
    CHECK( out.str() == "   10.0000000000	   20.0000000000	" );
}