// Program to implement Caesar Cipher
#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k,len;
    char msg[100],msg1[100],msg2[100];
    printf("Enter the first String: \n");
    gets(msg1);
    printf("Enter the Second String: \n");
    gets(msg2);
    len = (i>j)?j:i;
    k = msg2[0]-msg1[0];
    for(i=1;i<len;i++)
    {
        if((msg1[i]==' ')&&(msg2[i]==' '))
        {
            continue;
        }
        if(k!=(msg2[i]-msg1[i]))
        {
            j=0;
            break;
        }
        printf("The Key is : %d \n",k);
        // Encryption
        printf("Enter a string to encrypt: \n");
        gets(msg);
        for(i=0;i<strlen(msg);i++)
        {
            int chr = (msg[i]+k);
            printf("%c \t",(chr>122)?(chr-122+96):chr);
        }
        printf("\n");
        // Decryption
        printf("Enter a string to decrypt: \n");
        gets(msg);
        for(i=0;i<strlen(msg);i++)
        {
            int chr = (msg[i]-k);
            printf("%c \t",(chr<96)?(chr-96+122):chr);
        }

    }
    return 0;
}