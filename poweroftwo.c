#include<stdio.h>
#include<stdlib.h>

int fun(int n)
{
if((n&(n-1)))
{
printf("the entered number is NOT  power of 2\n");
}
else 
{
printf("the entered number is power of 2\n");
}
}

int main()
{
int n;
printf("enter a number\n ");
scanf("%d",&n);
fun(n);
}
