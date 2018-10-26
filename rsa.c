// To implement RSA Algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// To calcuate optimally the power we use fastmodular
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

// To calculate gcd of two numbers.
int gcd(int a,int b)
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

// Extended Euclidean Algorithm to calculate Inverse of a Number.
int extgcd(int a,int b)
{
	if(a==0) return b;
	if(b==0) return a;
	int r1,r2,r,q,s1=1,s2=0,t1=0,t2=1,s,t;
	r1 =a;
	r2 = b;
    int x = r2;
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
    return s1;	
}
// Find the value of e
int finde(int a)
{
    for(int i = 2;i<a;i++)
    {
        if(gcd(a,i)==1)
            return i;
    }
}

// Encrypt the data
int encrypt(int m,int e, int n)
{
    return fastmodular(m,e,n);
}

// Decrypt the data
int decrypt(int c,int d, int n)
{
    return fastmodular(c,d,n);
}

// Implement RSA and Decryption isnt working.
int main()
{
    int xx;
    int p = 17,q = 11;
    int n = p*q;
    printf("n: %d \n",n);
    int phi = (p-1)*(q-1);
    printf("Phi: %d\n",phi);
    int e = finde(phi);
    printf("e: %d \n",e);
    int message,crypt;
    printf("Enter the message: \n");
    scanf("%d",&message);
    crypt = encrypt(message,e,n);
    printf("Cipher text is : %d \n",crypt);
    // Find the inverse of e with phi i.e. d.
    int d = extgcd(e,phi);
    printf("d:%d\n",d);
    xx = decrypt(crypt,d,n);
    printf("The message after decoding is : %d",message);

    return 0;
}