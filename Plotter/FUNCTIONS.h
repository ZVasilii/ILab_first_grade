#ifndef PLOTTER_FUNCTIONS_H
#define PLOTTER_FUNCTIONS_H

#include <cmath>
#include "FUNC_DECLARATION.h"

void CreatingWindow()
{
    txSetColor(TX_RED);
    txSetFillColor(TX_WHITE);
    txRectangle(0.0, 0.0, SX, SY);
    txLine(SX / 2, SY - 1, SX / 2, 1);
    txLine(1, SY / 2, SX - 1, SY / 2);
}

void Plot(Func_t *function)
{
    int x = 0;
    int y = 0;
    double xphys = 0.0;
    double yphys = 0.0;

    char matrix[SY][SX] = {};

    for (x = 0; x < SX; x++)
    {
        xphys = (x - SX / 2) * 2.0 / SX;
        yphys = -Y_COEFF * function(X_COEFF * xphys);
        y = round((yphys * SY / 2 + SY / 2));
        if ((y > 0) && (y < SY))
            matrix[y][x] = 1;
    }


    for (y = 0; y < SY; y++)
    {
        for (x = 0; x < SX; x++)
        {
            if (matrix[y][x] == 1)
            {
                xphys = (double) x;
                yphys = (double) y;
                txSetPixel(xphys, yphys, TX_BLACK);
            }
        }
    }
}

void Prologue()
{
    txSelectFont ("Times New Roman", 60);
    txSetColor(TX_RED);
    txSetFillColor(TX_WHITE);
    txRectangle(0.0, 0.0, SX, SY);
    txTextOut(10, SY / 2 - 100, "Graphics by Zaytsev Vasilii ");
    txSleep(DELAY);
    txClear();
}

void Epilogue()
{
    txSelectFont ("Times New Roman", 60);
    txSetColor(TX_RED);
    txSetFillColor(TX_WHITE);
    txRectangle(0.0, 0.0, SX, SY);
    txTextOut(10, SY / 2 - 100, "Made using TXLib");
    txTextOut(10, SY / 2 - 200, "All rights reserved  to Ded32");
    txTextOut(10, SY / 2 - 300, "MIPT, 2019");
    txSleep(DELAY);
    txClear();
}


double COS(double x)
{
    return cos(x);
}

double SIN(double x)
{
    return sin(x);
}

double LOG(double x)
{
    //if ((IsEqual(x, 0.0)) || (x < 0.0)) return 10000000;
    if (x > 0.0) return log(x);
    else return 1000000;
}

double SQRT(double x)
{
    if (x >= 0.0) return sqrt(x);
    else return 1000000;
}

double LOG10(double x)
{
    if (x > 0.0) return log10(x);
    else return 1000000;
}

double SQR(double x)
{
    return (x * x);
}

double LIN(double x)
{
    return (x);
}

double HYP(double x)
{
    if ((x > 0.0) || (x < 0.0)) return 1 / x;
    else return 1000000;
}

#endif //PLOTTER_FUNCTIONS_H
