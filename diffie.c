// Fast modular exponentiation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *tobinary(int a)
{
    int *arr = (int *)malloc(sizeof(int)*100);
    int k = 1;
    while(a>0)
    {
        arr[k++] = a%2;
        a = a/2;
    }
    // arr[0] = k-1;
    return arr;
}
int fastmodular (int a, int b, int n)
{
    int c = 1;
    int *arr = tobinary(b);
    int len = sizeof(arr)/arr[0];
    int temp = a%n;
    for (int i = 1;i<=n;i++)
    {
        if(arr[i]==1)
        {
            c = (c*temp)%n;
        }
        temp = (temp*temp)%n;
    }
    return c%n;
}
void diffie(int g, int p)
{
    
    int a = 42;
    int b = 33;
    printf("The values of a and b: \n");
    scanf("%d %d",&a,&b);
    int x = fastmodular(g,a,p);
    int y = fastmodular(g,b,p);
    int ka = fastmodular(y,a,p);
    int kb = fastmodular(x,b,p);
    printf("ka: %d kb: %d",ka,kb);
}

int main()
{
    int g,p;
    printf("Enter the values of g and p: \n");
    scanf("%d %d",&g,&p);
    diffie(g,p);
    return 0;
}
