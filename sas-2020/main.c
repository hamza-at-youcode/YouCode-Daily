#include<stdio.h>
#include<stdlib.h>

typedef struct person{
    int id;
    char cin[15];
    char fullName[30];
}Person;

void readPerson(Person *p){
    printf("Enter the Id: ");
    fflush(stdin);
    scanf("%d",&p->id);
    printf("Enter the CIN: ");
    fflush(stdin);
    scanf("%s",p->cin);
    printf("Enter Full Name: ");
    fflush(stdin);
    scanf("%s",p->fullName);
    printf("\n******************\n");
}

void registerPersons(Person *p,int len){
    for(int i=0;i<len;i++) readPerson(&p[i]);
}

void displayCdd(Person p[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("\nCandidate %d:\n",i+1);
        printf("   ID: %d\n",p[i].id);
        printf("   Name: %s\n",p[i].fullName);
    }
}

int main(){
    Person *c;
    int l = 3;
    c = (Person*)malloc(l*sizeof(Person));
    printf("***** Registering candidates *****\n");
    registerPersons(c,l);
    printf("\n\n***** DISPLAYING CANDIDATES *****\n");
    displayCdd(c,l);

    return 0;
}


