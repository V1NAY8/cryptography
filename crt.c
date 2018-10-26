#include<stdio.h>
#include<stdlib.h>

// Extended Euclidean function to find inverse.

int ext(int a, int b)
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
		
	}
	if(s1<0)
	{
		s1 = s1+26;
		
	}
    return s1;
    
}

int main()
{
    int i,x = 0,k,n,product = 1;
    printf("Enter the number of equations: \n",n);
    int a[n],m[n],inv[n],M[n];
    printf("\n A array");
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n m array");
    for(i = 0;i<n;i++)
    {
        scanf("%d",&m[i]);
        product = product *m[i];
    }
    
    for(i=0;i<n;i++)
    {
        M[i] = product/m[i];
        inv[i] = ext(M[i],m[i]);
    }
    //Result
    for(i=0;i<n;i++)
    {
        x = x + (a[i]*M[i]*inv[i]);
        printf("M%d : %d",i,M[i]);
    }
    printf("\n The Value of x is %d",x%product);

    return 0;
}