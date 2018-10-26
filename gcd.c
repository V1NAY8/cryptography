#include <stdio.h>

int gcd(int a,int b)
{
    if(a==0||b==0)
        return 0;
    else if(a==b) 
        return a;
    else {
        if(a>b) return (a-b,b);
        else return (a,b-a);
    }
}

int main()
{
    int a,b;
    printf("Enter the numbers: \n");
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));
    return 0;
}