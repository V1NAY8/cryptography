// Program to implement Discrete Logarithm function
#include <stdio.h>
#include <stdlib.h>

int gcd(int r1,int r2)
{
    int q,r;
    if(r2==0)
        return r1;
    else
    {
        q = r1/r2;
        r = r1-q*r2;
        r1 = r2;
        r2 = r;
        gcd(r1,r2);
    }
}

int phi(int n)
{
    int result = 0;
    for(int i=1;i<n;i++)
    {
        if(gcd(n,i)==1)
        {
            result++;
        }
    }
    return result;
}

int discretelog(int a, int b, int c)
{
    int g=1;
    b = b%c;
    for(int i = 0;i<phi(c);i++)
    {
        if(g==b)
            return 1;
        g = (g*a)%c;
    }
    return -1;
}

int main()
{
    int a,b,c;
    printf("\n Enter the values of a,b,c \n");
    scanf("%d %d %d",&a,&b,&c);
    if(discretelog(a,b,c)==1)
        printf("\n Discrete Logarithm Exists");
    else
        printf("\n Discrete Logarithm Doesn't Exists");
    return 0;
}