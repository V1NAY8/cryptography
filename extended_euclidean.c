// euclidean program
#include<stdio.h>
#include<conio.h>

int extgcd(a,b)
{
	if(a==0) return b;
	if(b==0) return a;
	int r1,r2,r,q,s1=1,s2=0,t1=0,t2=1,s,t;
	r1 =a;
	r2 = b;
	while(r2>1)
	{
		q = r1/r2;
		r = r1-(r2*q);
		r1 = r2;
		r2 = r;
		
		s = s1-(s2*q); 
		s1 = s2;
		s2 = s;
		
		t = t1-(t2*q); 
		t1 = t2;
		t2 = t;
		
	}
	if(s1<0)
	{
		s1 = s1 + 26;
		
	}
	printf("%d %d %d",r,s,t);
	return 0;
	
}

int main()
{
	int a,b,x;
	printf("Enter the data: \n");
	scanf("%d %d",&a,&b);
	printf("\n%d",extgcd(a,b));
	return 0;
}
