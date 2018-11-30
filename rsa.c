#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int power(int x, int y, int p)
{
	int res = 1;
	x = x % p;
	while (y > 0)
	{
		res = (res*x) % p;
		y = y - 1;
	}
	return res;
}
int gcd(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 0;
	}
	else if (a == b)
	{
		return a;
	}
	else
	{
		if (a > b)
		{
			return gcd(a - b, b);
		}
		return gcd(a, b - a);
	}
}
int modinv(int r1, int r2)
{
	int r, s, s1 = 1, s2 = 0, q = 0, gcd1;
	int x = r2, y;
	gcd1 = gcd(r1, r2);
	if (gcd1 == 1){
		while (r2 != 0)
		{
			q = r1 / r2;
			r = r1%r2;
			s = s1 - q*s2;
			r1 = r2;
			r2 = r;
			s1 = s2;
			s2 = s;
		}
		if (s1 < 0)
			s1 = s1 + x;
		return s1;
	}
	else
		return 0;
}
int finde(int a)
{
	for (int i = 2; i < a; i++)
	{
		if (gcd(a, i) == 1)
		{
			return i;
		}
	}
}
int encrypt(int m, int e, int n)
{
	return power(m, e, n);
}
int decrypt(int c, int d, int n)
{
	return power(c, d, n);
}
int main()
{
	int p = 17, q = 11;
	int n = p*q;
	int phi = (p - 1)*(q - 1);
	int e = finde(phi);
	int m, c;
	printf("enter plaintext:");
	scanf("%d", &m);
	c = encrypt(m, e, n);
	printf("cipher text is: %d", c);
	int d = modinv(e, phi);
	m = decrypt(c, d, n);
	printf("\nplain text is: %d", m);
	system("pause");
	return 0;
}