#include <stdio.h>
#include <string.h>

int hash[100]={0};

void symmetric_pairs(int a[][2], int n)
{
    int i;

    for(i=0; i<n; i++) {

        if(! hash[a[i][0]])
            hash[a[i][0]] = a[i][1];

        if((hash[a[i][1]] == a[i][0]))
            printf("(%d,%d) (%d,%d) are paires\n", a[i][0], a[i][1], a[i][1], a[i][0]);
    }
}

int main()
{
    int a[][2]={{11,20},
               {30,40},
               {5,10},
               {40,30},
               {10,5}};

    int n = sizeof(a)/sizeof(a[0]);

    symmetric_pairs(a, n);

    return 0;
}
