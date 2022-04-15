
#ifndef PLOTTER_FUNC_DECLARATION_H
#define PLOTTER_FUNC_DECLARATION_H


const int SX = 800;                 ///Size of the Window (x axis)
const int SY = 600;                 ///Size of the Window (y axis)

const double X_COEFF = 5;           ///Coefficient of expand (x axis)
const double Y_COEFF = 0.8;         ///Coefficient of expand (y axis)
const double DELAY = 3000;          ///Delay between different graphics

typedef double (Func_t)(double x);  ///Function type


void CreatingWindow();              ///Function that creates blank window

void Prologue();                    ///Function that prints prologue

void Epilogue();                    ///Function that prints epilogue

void Plot(Func_t *function);        ///Function that prints epilogue


double COS(double x);               ///Math functions

double SIN(double x);               ///Math functions

double LOG(double x);               ///Math functions

double SQRT(double x);              ///Math functions

double LOG10(double x);             ///Math functions

double SQR(double x);               ///Math functions

double LIN(double x);               ///Math functions

double HYP(double x);               ///Math functions


#endif //PLOTTER_FUNC_DECLARATION_H
