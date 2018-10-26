// Program to implement Rabin Miller Primality Test
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int power(int x,int y,int p)
{
    int res = 1;
    x = x%p;
    while(y>0)
    {
        res = (res*x)%p;
        y = y-1;
    }
    return res;
}

int isprime(int n)
{
    if(n<=1 || n==4)
        return 0;
    if(n<=3)
        return -1;
    int d = n-1;
    int k = 0;
    while(d%2==0)
    {
        k++;
        d = d/2;
    }
    int a = 2+rand()%(n-4);
    int x = power(a,d,x);
    if(x==1 ||x ==(n-1))
        return 1;
    int j = 0,y=x;
    while(j<k)
    {
        x = (x*y)%n;
        if(x ==n-1)
            return 1;
        j++;
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter the value of n: \n");
    scanf("%d",&n);
    int x = isprime(n);
    if(x==1)
    {
        printf("Inconclusive");
    }
    else{
        printf("Composite");
    }
    return 0;
}