#include<stdio.h>
#include<stdlib.h>
void print_f(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
int *boxing(int *arr1, int *arr2, int n)
{
	int *arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr1[arr2[i] - 1];
	}
	return arr;
}
int *cir_shift(int *arr)
{
	int a = arr[0];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[4] = a;
	return arr;
}
int **key_gen(int *key)
{
	int **keyfinal = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++)
	{
		keyfinal[i] = (int*)malloc(sizeof(int) * 8);
	}
	int straight_pbox[10] = { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
	key = boxing(key, straight_pbox, 10);
	/*printf("\n key after p boxing");
	print_f(key, 10);*/
	int *larr = (int*)malloc(sizeof(int) * 5);
	int *rarr = (int*)malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
	{
		larr[i] = key[i];
		rarr[i] = key[i + 5];
	}
	larr = cir_shift(larr);
	rarr = cir_shift(rarr);

	int *arr = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = larr[i];
		arr[i + 5] = rarr[i];
	}
	int comp_pbox[8] = { 6, 3, 7, 4, 8, 5, 10, 9 };
	arr = boxing(arr, comp_pbox, 8);
	for (int i = 0; i < 8; i++)
	{
		keyfinal[0][i] = arr[i];
	}
	larr = cir_shift(larr);
	larr = cir_shift(larr);
	rarr = cir_shift(rarr);
	rarr = cir_shift(rarr);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = larr[i];
		arr[i + 5] = rarr[i];
	}
	arr = boxing(arr, comp_pbox, 8);
	for (int i = 0; i < 8; i++)
	{
		keyfinal[1][i] = arr[i];
	}
	return keyfinal;
}
int *xor(int *x, int *y, int n)
{
	int *arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = x[i] ^ y[i];
	}
	return arr;
}

int *function(int *key, int r[])
{
	int *R = (int*)malloc(sizeof(int) * 10);
	int *R1 = (int*)malloc(sizeof(int) * 4);
	int exp_pbox[8] = { 4, 1, 2, 3, 2, 3, 4, 1 };
	R = boxing(r, exp_pbox, 8);
	printf("\nright after expansion pbox");
	print_f(R, 8);
	R = xor(R, key, 8);
	int s1[4][4] = { 1, 0, 3, 2, 3, 2, 1, 0, 0, 2, 1, 3, 3, 1, 3, 2 };
	int s2[4][4] = { 0, 1, 2, 3, 2, 0, 1, 3, 3, 0, 1, 0, 2, 1, 0, 3 };
	int rs1[4], rs2[4];
	for (int i = 0; i < 4; i++)
	{
		rs1[i] = R[i];
		rs2[i] = R[i + 4];
	}
	int a = (2 * rs1[0]) + rs1[3];
	int b = (2 * rs1[1]) + rs1[2];
	int c = s1[a][b];
	rs1[0] = c / 2;
	rs1[1] = c % 2;
	a = (2 * rs2[0]) + rs2[3];
	b = (2 * rs2[1]) + rs2[2];
	c = s2[a][b];
	rs1[2] = c / 2;
	rs1[3] = c % 2;
	int s_pbox[4] = { 2, 4, 3, 1 };
	R1 = boxing(rs1, s_pbox, 4);
	return R1;
}
int *outputfunction(int *l, int *r, int *key)
{
	int *farr = function(key, r);
	int *round = xor(farr, l, 4);
	return round;
}

int *encrypt(int *plaintext, int *key)
{
	int initial_permutation[8] = { 2, 6, 3, 1, 4, 8, 5, 7 };
	plaintext = boxing(plaintext, initial_permutation, 8);
	printf("\nplain text after initial permutation:");
	print_f(plaintext, 8);
	int **keys = key_gen(key);
	int *key1 = (int*)malloc(sizeof(int) * 8);
	int *key2 = (int*)malloc(sizeof(int) * 8);
	for (int i = 0; i < 8; i++)
	{
		key1[i] = keys[0][i];
		key2[i] = keys[1][i];
	}
	printf("\nkey1 is:");
	print_f(key1, 8);
	printf("\nkey2 is:");
	print_f(key2, 8);
	int r1[4], l1[4];
	for (int i = 0; i < 4; i++)
	{
		r1[i] = plaintext[i + 4];
		l1[i] = plaintext[i];
	}
	int *round1 = outputfunction(l1, r1, key1);
	printf("\nround1:");
	print_f(round1, 4);
	int *round2 = outputfunction(r1, round1, key2);
	printf("\nround2:");
	print_f(round2, 4);
	int *final = (int*)malloc(sizeof(int) * 8);
	for (int i = 0; i < 4; i++)
	{
		final[i] = round2[i];
		final[i + 4] = round1[i];
	}
	int final_permutation[8] = { 4, 1, 3, 5, 7, 2, 8, 6 };
	final = boxing(final, final_permutation, 8);
	return final;
}
int *decrypt(int *plaintext, int *key)
{
	int initial_permutation[8] = { 2, 6, 3, 1, 4, 8, 5, 7 };
	plaintext = boxing(plaintext, initial_permutation, 8);
	printf("\nplain text after initial permutation:");
	print_f(plaintext, 8);
	int **keys = key_gen(key);
	int *key1 = (int*)malloc(sizeof(int) * 8);
	int *key2 = (int*)malloc(sizeof(int) * 8);
	for (int i = 0; i < 8; i++)
	{
		key1[i] = keys[0][i];
		key2[i] = keys[1][i];
	}
	printf("\nkey1 is:");
	print_f(key1, 8);
	printf("\nkey2 is:");
	print_f(key2, 8);
	int r1[4], l1[4];
	for (int i = 0; i < 4; i++)
	{
		r1[i] = plaintext[i + 4];
		l1[i] = plaintext[i];
	}
	int *round1 = outputfunction(l1, r1, key2);
	printf("\nround1:");
	print_f(round1, 4);
	int *round2 = outputfunction(r1, round1, key1);
	printf("\nround2:");
	print_f(round2, 4);
	int *final = (int*)malloc(sizeof(int) * 8);
	for (int i = 0; i < 4; i++)
	{
		final[i] = round2[i];
		final[i + 4] = round1[i];
	}
	int final_permutation[8] = { 4, 1, 3, 5, 7, 2, 8, 6 };
	final = boxing(final, final_permutation, 8);
	return final;
}
int main()
{
	int *plaintext = (int*)malloc(sizeof(int) * 8);
	printf("enter plaintext\n");
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &plaintext[i]);
	}
	int key[10] = { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 };
	int *ciphertext = (int*)malloc(sizeof(int) * 8);
	printf("\nencrypting....");
	ciphertext = encrypt(plaintext, key);
	printf("\ncipher text is:");
	print_f(ciphertext, 8);
	printf("\n\ndecrypting..");
	plaintext = decrypt(ciphertext, key);
	printf("\nplaintext is:");
	print_f(plaintext, 8);
	return 0;
}
