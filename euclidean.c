// A program to implement Euclidean program
#include <stdio.h>
#include <conio.h>

int gcd(a,b)
{
	if(a==0) return b;
	if(b==0) return a;
	int r1,r2,r,q;
	r1 =a;
	r2 = b;
	while(r2>0)
	{
		q = r1/r2;
		r = r1-(r2*q);
		r1 = r2;
		r2 = r;
	}
	return r1;
	
}
int main()
{
	int a,b;
	printf("Enter the data: \n");
	scanf("%d %d",&a,&b);
	printf("\n%d",gcd(a,b));
	
	return 0;
}
