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
int main()
{
    int a,b,c;
    printf("Enter the values of a,b,c");
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",fastmodular(a,b,c));
    return 0;
}
