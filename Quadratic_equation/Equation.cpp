/**   \brief   The program solves quadratic equations
              with given coefficients
      \author  Zaitsev Vasilii, MIPT
      \version 5.0
      \date    September 2019

      \warning DO NOT USE
              SolveLinear and SolveSquare
              without SolveMain
*/
#include <cstdio>
#include <cmath>
#include <cassert>

///Testing function

#define TEST  SolveMain(a, b, c, &x1, &x2, &NumberOfRoots, &TypeEquation);\
               printf("%lg * x^2 + %lg * x + %lg = 0\n", a, b, c);\
               PrResult = a * x1 * x1 + b * x1 + c;\
               if  (IsEqual(PrResult, ZERO)) {\
                   printf("X1 = %.3lg\n", x1);\
                   printf("Everything is good with 1 root\n");\
               }\
               else\
                   printf("ERROR\n");\
               PrResult = a * x2 * x2 + b * x2 + c;\
               if (NumberOfRoots == 2) \
                   if  (IsEqual(PrResult, ZERO)) {\
                       printf("X2 = %.3lg\n", x2);\
                       printf("Everything is good with 2 root\n");\
                   }\
                   else\
                       printf("ERROR\n");\
                printf("\n");





/**
    INCORRECT, LINEAR, QUADRATIC - types of equation
    MAXTRIES - maximum number of tries to enter coefficient (function: Entering)
    MAXWORDS - maximum number of words in commentary (function: Entering)
    DELTA - tolerance for comparising double/float (function: IsEqual)
    ZERO  - NULL
*/
const double DELTA =  1.0e-10;
const double ZERO  =  0.0;

enum {
    INCORRECT = 3,
    LINEAR    = 2,
    QUADRATIC = 1,
    MAXTRIES  = 100,
    MAXWORDS  = 100,
};

///Declaration of the functions

void SolveMain (double a, double b, double c, double* x1, double* x2, int* NumberOfRoots, int* TypeEquation) ;
void SolveSquare (double a, double b, double c, double* x1, double* x2, int* NumberOfRoots);
void SolveLinear (double a, double b, double* x1);
void Checker ();
double  Entering (const char Message[MAXWORDS]);
int IsEqual (double a, double b);

/// Function to check the correct work of the program

void Checker ()
{
    int Testnumber = 1;
    double a  = NAN;     ///Coefficient a
    double b  = NAN;     ///Coefficient b
    double c  = NAN;     ///Coefficient c
    double x1 = NAN;     ///First Root
    double x2 = NAN;     ///Second Root
    double PrResult    = NAN;  ///Result
    int NumberOfRoots  = 15;   ///NumberOfRoots
    int TypeEquation = 15;     ///TypeEquation

    printf ("Test number %d\n", Testnumber);
    a = 1;
    b = -2;
    c = 1;
    TEST
    Testnumber++;

    printf ("Test number %d\n", Testnumber);
    a = 0;
    b = -2;
    c = 1;
    TEST
    Testnumber++;

    printf ("Test number %d\n", Testnumber);
    a = 5;
    b = 13;
    c = 1;
    TEST
    Testnumber++;

    printf ("Test number %d\n", Testnumber);
    a = 1;
    b = 0;
    c = -9;
    TEST
    Testnumber++;

    printf ("Test number %d\n", Testnumber);
    a = 1;
    b = -5;
    c = 6;
    TEST
    Testnumber++;
}

/**
 Main function of the program (a.k.a) dispatcher,
 which compare coefficients
 and use other functions to solve the equation.
 \param [in]  a,b,c         - coefficients of the equation
 \param [out] x1,x2         - roots of the equation
 \param [out] NumberOfRoots - number of roots
 \param [out] TypeEquation  - type of the equation (Quadratic, Linear or Incorrect)
*/

void SolveMain (double a, double b, double c, double* x1, double* x2, int* NumberOfRoots, int* TypeEquation)
{
    ///assertion

    assert (x1 != nullptr) ;
    assert (x2 != nullptr) ;
    assert (x1 != x2) ;
    assert (NumberOfRoots != nullptr) ;
    assert (TypeEquation  != nullptr) ;

    if ( (IsEqual (a, ZERO)) && (IsEqual (b, ZERO))) {
        *NumberOfRoots = 0;
        *TypeEquation = INCORRECT;
    }

    if ( (IsEqual (a, ZERO)) && (!IsEqual (b, ZERO))) {
        *NumberOfRoots = 1;
        *TypeEquation = LINEAR;
        SolveLinear (b, c, x1);
    }

    if ( (!IsEqual (a, ZERO)) && (!IsEqual (b, ZERO)) && (IsEqual (c, ZERO))) {
        *x1 = ZERO;
        *NumberOfRoots = 2;
        *TypeEquation = QUADRATIC;
        SolveLinear (a, b, x2);
    }

    if ( (!IsEqual (a, ZERO)) && (IsEqual (b, ZERO)) && (IsEqual (c, ZERO))) {
        *x1 = ZERO;
        *NumberOfRoots = 1;
        *TypeEquation = QUADRATIC;
    }

    if ( (!IsEqual (a, ZERO)) && (IsEqual (b, ZERO)) && (!IsEqual (c, ZERO))) {
        if (c > ZERO) {
            *NumberOfRoots = 0;
            *TypeEquation = QUADRATIC;
        }

        if (c < ZERO) {
            *NumberOfRoots = 2;
            *TypeEquation = QUADRATIC;
            *x1 =   sqrt (- c);
            *x2 = - sqrt (- c);
        }
    }

    if ( (!IsEqual (a, ZERO)) && (!IsEqual (b, ZERO)) && (!IsEqual (c, ZERO))) {
        SolveSquare (a, b, c, x1, x2, NumberOfRoots);
        *TypeEquation = QUADRATIC;
    }
}

/**
 Function that solves linear equation
 \param [in]  a,b - coefficients of the equation
 \param [out] x1  - root of the equation
*/

void SolveLinear (double a, double b, double* x1)
{
    ///assertion
    assert (x1 != nullptr);

    *x1 = - b / a;

    if (IsEqual (*x1, -ZERO))
        *x1 = ZERO;
}

/**
 Function that solves quadratic equation
 \param [in]  a,b,c         - coefficients of the equation
 \param [out] x1,x2         - roots of the equation
 \param [out] NumberOfRoots - number of roots
*/

void SolveSquare (double a, double b, double c, double* x1, double* x2, int* NumberOfRoots)
{
    ///assertion

    assert (x1 != nullptr);
    assert (x2 != nullptr) ;
    assert (NumberOfRoots != nullptr) ;

    ///Calculating Discriminant

    double D = b * b - 4.0 * a * c;

    if (D > ZERO) {
        *NumberOfRoots = 2;
        *x1 = (- b + sqrt (D)) / (2.0 * a);
        *x2 = (- b - sqrt (D)) / (2.0 * a);
    }

    if (IsEqual (D, ZERO)) {
        *NumberOfRoots = 1;
        *x1 = - b / (2.0 * a);
    }

    if (D < ZERO)
        *NumberOfRoots = 0;
}

/**
 Function that inputs the coefficients
 \param [in]  Message - message that shown to user
 Function return value of coefficient
*/

double  Entering (const char Message[MAXWORDS])
{
    double  Value   = ZERO;
    int     Correct = 0;  ///Is value correct?
    int     Tries   = 1;

    printf ("%s\n", Message);
    Correct = scanf ("%lg", &Value);
    fflush (stdin);

    while (Correct != 1 && Tries <= MAXTRIES) {
        printf ("Incorrect input, please try again\n");
        printf ("You have %d tries left", MAXTRIES - Tries);
        printf (" \n");
        printf (" \n");
        printf ("%s\n", Message);

        fflush (stdin);
        Correct =  scanf ("%lg", &Value);

        Tries++;
    }

    assert (Correct == 1);
    return Value;
}

/**
 Function that compare 2 double values
 with some tolerance DELTA
 \param [in]  a,b - 2 double values
 Function return 1 if they are equal
 and returns 0, if they are not
*/

int IsEqual (double a, double b)
{
    double difference = ( (a - b) > 0) ? (a - b) : (b - a) ;
    return (difference <= DELTA);

}



int  main ()
{
    ///initialising

    double  a =  NAN, b = NAN, c = NAN;
    int     mode = 0;
    double  x1 = NAN, x2 = NAN;
    int     NumberOfRoots = 15;
    int     TypeEquation = 15;

    ///Communication with user

    printf ("Solving quadratic equation\n");
    printf ("Version 5.0\n");
    printf ("Ax2+Bx+C=0\n");

    ///Defining mode of the program (Checker/Solving);

    printf ("Do you want to use checker mode or solving mode ?\n");
    printf ("Type 1 for checker\n");
    printf ("Type 2 for solving\n");
    scanf ("%d", &mode);
    fflush (stdin);
    printf ("\n");

    if (mode == 2) {
        ///Entering the coefficients

        a = Entering ("Input coefficient A");
        b = Entering ("Input coefficient B");
        c = Entering ("Input coefficient C");

        ///Calling function SolveMain

        SolveMain (a, b, c, &x1, &x2, &NumberOfRoots, &TypeEquation);

        ///Defining types of the equation

        switch (TypeEquation) {

            case INCORRECT :
                printf ("This is incorrect equation\n");
                break;

            case LINEAR :
                printf ("This is linear equation\n");
                break;

            case QUADRATIC :
                printf ("This is quadratic equation\n");
                break;

            default
                :
                printf ("Oooops, some error happened\n");
                break;
        }

        ///Defining Number of roots
        ///Writing the roots in console

        switch (NumberOfRoots) {

            case 0:
                printf ("Infinite number of roots or no existing roots\n");
                break;

            case 1:
                printf ("Number of roots %d\n", NumberOfRoots);
                printf ("X = %.3lg\n", x1);
                break;

            case 2:
                printf ("Number of roots %d\n", NumberOfRoots);
                printf ("X1 = %.3lg\n", x1);
                printf ("X2 = %.3lg\n", x2);
                break;
        }
    }

    ///Call checker mode

    if (mode == 1) {
        Checker();
    }

    ///Assertion

    assert ( (mode == 1) || (mode == 2));

    return 0;
}
