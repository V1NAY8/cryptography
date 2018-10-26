#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int phi(int n)
{
    int result = 1;
    for(i=1;i<n;i++)
    {
        if(gcd(i,n)==1)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    int n,count,temp;
    printf("Enter the value of n: \n");
    scanf("%d",&n);
    int phi_1 = phi(n);
    for(int i = 0;i<n;i++)
    {
        count = 1;
        temp = i; // Because pow(a,i) = a power of i we do simple multiplication.
        for(int j = 0;j<n;j++)
        {
            temp = temp*j;
            if(temp%n==i)
            {
                break;
            }
            else{
                count++;
            }
        }
        if(count == phi_1)
        {
            printf("\n The primitive root of phi(%d) = %d",n,count);
        }
    }
    
    return 0;
}