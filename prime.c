#include <stdio.h>
#include <stdlib.h>
int main()
{
    int prime,i;
    printf("enter prime number \n");
    scanf("%d",&prime);
    for(i=2;i<=(prime/2);i++)
    {
        if(prime%i==0)
        {
            //non prime number condition
            printf("its not a prime number\n");
            exit (1);
        }
    }
    printf("entered number is prime number\n");
    return 0;
}

