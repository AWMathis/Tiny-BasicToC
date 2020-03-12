#include <stdio.h>
int main() {
double A=0, B=0, C=0, D=0, E=0, F=0, G=0, H=0, I=0, J=0, K=0, L=0, M=0, N=0, O=0, P=0, Q=0, R=0, S=0, T=0, U=0, V=0, W=0, X=0, Y=0, Z=0;
printf("%g\n", (double)14);

printf("Enter value for A: ");
scanf("%lf", &A );
printf("Enter value for B: ");
scanf("%lf", &B );
printf("Enter value for C: ");
scanf("%lf", &C );

if (A>B) { if (A>C) { printf("%g\n", (double)A);
 }
 }

if (A==B) { goto g1;
 }

if (A==C) { printf("%g\n", (double)3/(4+A)
);
 }

A = 1;

B = 2;

C = 3;

g1:
printf("%g\n", (double)A);
printf("%g\n", (double)B);
printf("%g\n", (double)C);

return 0;

}