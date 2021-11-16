#include<stdio.h>

void sayHello(){
    printf("\nHello!");
}

void helloName(char name[]){
    printf("\nHello %s!",name);
}

int age(int year){
    int age = 2021 - year;
    return age;
}

int main(){
    int a;

    printf("Enter your date of birth: ");
    scanf("%d",&a);
    
    helloName("hamza");
    printf("\nYou are %d years old.",age(a));
}