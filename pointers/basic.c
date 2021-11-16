#include<stdio.h>

int main(){
    int a = 8;
    int *p;
    p = &a;
    printf("a is an integer\n");
    printf("p is a pointer of type integer\n");
    printf("The value of a is: %d\n",a);
    printf("the address of a is: %d\n",&a);
    printf("p = %d, &a = %d | &a <=> p\n",p,&a);
    printf("*p = %d, a = %d | a <=> *p\n",*p,a);
    return 0;
}