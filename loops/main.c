#include<stdio.h>
#include<stdlib.h>

int main(){
    // for loop:
    int i,j;
    int a,b;
    printf("\nTable of multiplication of: ");
    scanf("%d",&a);
    for (i = 1; i <10 ; i++)
    {
        printf("%d * %d = %d\n",a,i,a*i);
    }

    // Draw a pyramid
    printf("\n\nPyramid of %d stars:\n",a);
    for (i = a; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Enter a again
    int aAgain;
    do
    {
        printf("\nYou will not get out from this untile you enter %d! ",a);
        scanf("%d",&aAgain);
    } while (aAgain!=a);
    
    
    
}