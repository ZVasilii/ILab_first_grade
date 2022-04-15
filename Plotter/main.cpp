#include "TXLib.h"
#include "FUNCTIONS.h"

int main()
{
    Func_t *ArrFunc[10] = {LIN, SQR, LOG, LOG10, SQRT, SIN, COS, HYP};  ///Creating array of functions
    txCreateWindow(SX, SY);                                             ///Creating workspace

    Prologue();                                                         ///Printing prologue

    for (int i = 0; i < 8; i++)
    {
        CreatingWindow();
        Plot(ArrFunc[i]);
        txSleep(DELAY);
        txClear();
    }

    Epilogue();                                                          ///Creating epilogue

    return 0;
}



