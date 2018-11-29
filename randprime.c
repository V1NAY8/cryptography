// Program to print prime numbers from random generation in 1 to 1000
#include <stdio.h>

int main()
{
    int primes[1000],count = 0,arr_index=0,index;
    printf("Enter any data: \n");
    int ptr = getchar();
    for(int i=2;i<100;i++)
    {
        count = 0;
        for(int j=2;j<i;j++)
        {
            if((i%j)==0)
            {
                count++;
            }
        }
        if(count==0)
        {
            primes[arr_index++]=i;
        }
    }
    index = (ptr)%arr_index;
    printf("%d",primes[index]);
    return 0;
}