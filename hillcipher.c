// Program to implement Hill Cipher
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **getmatrix(char *string,int n,int rows)
{
	int i = 0,length=strlen(string),k,m=0;

	int **arr = (int**)malloc(sizeof(int*)*rows);
	for (int iter = 0; iter < rows; iter++)
		arr[iter] = (int*)malloc(sizeof(int) * n);

	while (i<length)
	{
		for (k = 0; k < n; k++)
		{
			if (i>=length)
				arr[m][k] = 'z'-97;
			else
			{
				arr[m][k] = string[i]-97;
				i++;
			}
		}
		m++;
	}
	return arr;
}

int **matrix_mul(int **matrix, int **key, int m, int n,int n1)
{
	int k;
	int **result = (int**)malloc(sizeof(int*)*m);
	for (int iter = 0; iter < m; iter++)
		result[iter] = (int*)malloc(sizeof(int)*n);

	for (int iter = 0; iter < m; iter++)
	{
		for (int j = 0; j < n; j++)
		{
			k = 0;
			for (int i = 0; i < n1; i++)
				k = k + matrix[iter][i] * key[i][j];
			result[iter][j] = k%26;
		}
	}
	return result;
}

char *tostring(int **arr, int rows, int n)
{
	int i = 0;
	char *string = (char*)malloc(sizeof(char)*(rows*n));

	for (int iter = 0; iter < rows; iter++)
		for (int iter1 = 0; iter1 < n; iter1++)
			string[i++] = arr[iter][iter1]+97;
	string[i] = '\0';
	return string;
}


void getCofactor(int **A, int **temp, int p, int q, int n,int N)
{
	int i = 0, j = 0;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (row != p && col != q)
			{
				temp[i][j++] = A[row][col];
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}


int determinant(int **A, int n,int N)
{
	int D = 0; 
	if (n == 1)
		return A[0][0];

	int **temp = (int**)malloc(sizeof(int*)*N);
	for (int iter = 0; iter < N; iter++)
		temp[iter] = (int*)malloc(sizeof(int)*N);

	int sign = 1;  
	for (int f = 0; f < n; f++)
	{
		getCofactor(A, temp, 0, f, n,N);
		D += sign * A[0][f] * determinant(temp, n - 1,N);
		sign = -sign;
	}
	return D;
}


void adjoint(int **A, int **adj,int N)
{
	if (N == 1)
	{
		adj[0][0] = 1;
		return;
	}
	int sign = 1;
	int **temp = (int**)malloc(sizeof(int*)*N);
	for (int iter = 0; iter < N; iter++)
		temp[iter] = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			getCofactor(A, temp, i, j, N,N);
			sign = ((i + j) % 2 == 0) ? 1 : -1;
			adj[j][i] = (sign)*(determinant(temp, N - 1,N));
		}
	}
}


int inverseofnumber(int a, int n)
{
	int q, s1 = 1, m, r1, r2, s2 = 0, t1 = 0, t2 = 1, s, t, r;
	r1 = a;
	r2 = n;
	while (r2>0)
	{
		q = r1 / r2;
		r = r1 - q*r2;
		s = s1 - q*s2;
		t = t1 - q*t2;
		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}
	m = s1*a;
	m = m%n;
	if (m < 0)
		m = m + n;

	if (m == 1)
		return s1;
	else
		return -1;
}



int main()
{

	int n;
	int **matrix;
	printf("Enter string:\n");
	char string[50];
	scanf("%[^\n]", string);
	printf("Enter block size:\n");
	scanf("%d", &n);
	int length = strlen(string);
	int rows = (length%n == 0) ? (length / n) : ((length / n) + 1);
	matrix = getmatrix(string, n, rows);

	for (int iter = 0; iter < rows; iter++)
	{
		for (int iter1 = 0; iter1 < n; iter1++)
			printf("%d ", matrix[iter][iter1]);
		printf("\n");
	}

	fflush(stdin);
	printf("Enter Key: \n");
	scanf("%[^\n]", string);
	int **key = getmatrix(string, n, n);


	for (int iter = 0; iter < n; iter++)
	{
		for (int iter1 = 0; iter1 < n; iter1++)
			printf("%d ", key[iter][iter1]);
		printf("\n");
	}


	int **mul = matrix_mul(matrix, key, rows, n,n);
	printf("matrix after multiplication is :\n");
	for (int iter = 0; iter < rows; iter++)
	{
		for (int iter1 = 0; iter1 < n; iter1++)
			printf("%d ", mul[iter][iter1]);
		printf("\n");
	}

	int **adj = (int**)malloc(sizeof(int*)*n);
	for (int iter = 0; iter < n; iter++)
		adj[iter] = (int*)malloc(sizeof(int)*n);


	adjoint(key, adj,n);
	//printf("\n%d\n", determinant(key, n, n)%26);
	int z = determinant(key, n, n);
	if (z < 0)
		z = z + 26;


	int inverse = inverseofnumber(z, 26);

	if (inverse != -1)
	{
		for (int iter = 0; iter < n; iter++)
		{
			for (int iter1 = 0; iter1 < n; iter1++)
				adj[iter][iter1] = (inverse*adj[iter][iter1]) % 26;
		}
		mul = matrix_mul(mul, adj, rows, n, n);
		printf("string after decryption is : \n");

		for (int iter1 = 0; iter1 < rows;iter1++)
			for (int iter = 0; iter < n; iter++)
				printf("%c", (mul[iter1][iter]%26)+97);
		printf("\n");
		/*printf("\t%d", inverseofnumber(z, 26));*/
	}
	else
		printf("Inverse is  not possible\n");
	return 0;
}