#include <stdio.h>

void Resistance(int r12, int r13,int r23, int r22, int r33,int *rFA, int *rFB )
{
    int r1A, r2A, r3A, rB, rParB, rParA;          //r*A - numerator of 1,2,3 resistors; rB - denominator of resistors;
    r1A = r12*r13;                                          //rParA,rParB - numerator and denominator of parallel sector;
    r2A = r12*r23;                                          // rFA,rFB - numerator and denominator of final resistance;
    r3A = r23*r13;
    rB = r12+r23+r13;
    r1A = r1A+ r22*rB;
    r3A = r3A+ r33*rB;
    rParA = r1A *r3A;
    rParB = (r1A + r3A) * rB;
    *rFA = rParA*rB+rParB*r2A;
    *rFB = rParB * rB;
}

void NOD(int *rFA,int *rFB)
{
    int n1,n2;
    n1 = *rFA;
    n2 = *rFB;
    while ((n1 != 0) && (n2 != 0))
        if (n1>n2) {
            n1 = n1 - n2;
        } else {
            n2 = n2 - n1;
        };
    *rFA /= n1;
    *rFB /= n1;
}

int main()
{
    printf("Resistors for Lib-Mipt\n");
    printf("Version 1.0\n");
    int r12, r13, r23, r22, r33,rFA,rFB; // r12 - top-left; r22 - top-left; r13 - ctntral; r23 - bottom-left; r33 - bottom-right;
    r12 = r13 = r23 = r22 = r33 = 0;
    printf("Enter the top-left value\n");
    scanf("%d", &r12);
    printf("Enter the top-right value\n");
    scanf("%d", &r22);
    printf("Enter the central value\n");
    scanf("%d", &r13);
    printf("Enter the bottom-left value\n");
    scanf("%d", &r23);
    printf("Enter the bottom-right value\n");
    scanf("%d", &r33);
    printf("\n");
    Resistance(r12,r13,r23,r22,r33,&rFA,&rFB);
    NOD(&rFA,&rFB);
    printf("Resestance is equal to \n");
    printf("%d\n", rFA);
    printf("---\n");
    printf("%d\n", rFB);
}
