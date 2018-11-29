#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char key[5][6] = { "monar", "chybd", "efgik", "lpqst", "uvwxz" };

int  check(char *string)
{
	int iter = 0;
	while (string[iter] != '\0')
	{
		if (!(string[iter]>= 'a' && string[iter] <='z') && !(string[iter]>='A' && string[iter]<='Z') && string[iter]!=' ')
			return 0;
		iter++;
	}
	return 1;
}

int *return_pos(char ch)
{
	int *pos = (int*)malloc(sizeof(int) * 2);
	for (int iter = 0; iter < 5; iter++)
	{
		for (int iter1 = 0; iter1 < 5; iter1++)
		{
			if (key[iter][iter1] == ch || ( ch == 'j' && key[iter][iter1] == 'i'))
			{
				pos[0] = iter;
				pos[1] = iter1;
				return pos;
			}
		}
	}

}


char *encrypt(char *string)
{

	int *pos1 = (int*)malloc(sizeof(int) * 2);
	int *pos2=(int*)malloc(sizeof(int)*2);
	if (strlen(string) % 2 != 0)
	{
		int len = strlen(string);
		string[len] = 'z';
		string[len+1] = '\0';
	}

	for (int iter = 0; iter < strlen(string)-1; iter++)
		if (string[iter] == string[iter + 1])
		{
			string[iter + 1] = 'x';
			iter++;
		}

	for (int iter = 0; iter < strlen(string); iter+=2)
	{
		pos1 = return_pos(string[iter]);
		pos2 = return_pos(string[iter+1]);

		if (pos1[0] == pos2[0])
		{
			string[iter] = key[pos1[0]][(pos1[1]+1) % 5];
			string[iter+1] = key[pos2[0]][(pos2[1]+1) % 5];
		}
		else if (pos1[1] == pos2[1])
		{
			string[iter] = key[(pos1[0]+1)%5][pos1[1]];
			string[iter + 1] = key[(pos2[0]+1)%5][pos2[1]];
		}
		else
		{
			string[iter] = key[pos1[0]][pos2[1]];
			string[iter+1] = key[pos2[0]][pos1[1]];
		}
	}
	return string;

}


char *decrypt(char *string)
{
	int *pos1 = (int*)malloc(sizeof(int) * 2);
	int *pos2 = (int*)malloc(sizeof(int) * 2);
	for (int iter = 0; iter < strlen(string); iter += 2)
	{
		pos1 = return_pos(string[iter]);
		pos2 = return_pos(string[iter + 1]);
		if (pos1[0] == pos2[0])
		{
			string[iter] = key[pos1[0]][(pos1[1] + 4) % 5];
			string[iter + 1] = key[pos2[0]][(pos2[1] + 4) % 5];
		}
		else if (pos1[1] == pos2[1])
		{
			string[iter] = key[(pos1[0] + 4) % 5][pos1[1]];
			string[iter + 1] = key[(pos2[0] + 4) % 5][pos2[1]];
		}
		else
		{
			string[iter] = key[pos1[0]][pos2[1]];
			string[iter + 1] = key[pos2[0]][pos1[1]];
		}
	}
	return string;
}
int main()
{
	
	char *encrypt_str = (char*)malloc(sizeof(encrypt_str) * 50),*encrypted,*decrypted;
	int flag = 0;
	printf("Enter a string:\n");
	scanf("%[^\n]", encrypt_str);
	if (strlen(encrypt_str) % 2 != 0)
		flag = 1;

	if (check(encrypt_str))
	{
		encrypted=encrypt(encrypt_str);
		printf("Encrypted string is: %s\n", encrypted);
		decrypted = decrypt(encrypted);
		if (flag == 1)
			decrypted[strlen(decrypted)-1] = '\0';
        printf("Decrypted string is: %s\n", decrypted);
        }
	else
	{
		printf("Enter proper plain text\n");
	}
	return 0;
}
