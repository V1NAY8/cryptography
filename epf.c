// A program to implement euler phi function
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int c,m,n,phi;
    double p,e,a,b;
    printf("Enter case \n");
    scanf("%d",&c);
    switch(c)
    {
        case 1: printf("Enter the prime number \n");
                scanf("%lf",&p);
                printf("\n phi(%lf) = %lf",p,(p-1));
                break;
        case 2: printf("Enter the number as product of Two Primes");
                scanf("%d %d",&m,&n);
                phi = m*n;
                printf("\n phi(%d) = %d",phi,((m-1)*(n-1)));
                break;
        case 3: printf("Enter the number as power of primes");
                scanf("%lf %lf",&p,&e);
                a = pow(p,e);
                b = pow(p,e-1);
                printf("\n phi(%lf) = %lf",a,(a-b));
                break;
        default: printf("Invalid");
                break;   
    }
    return 0;
}