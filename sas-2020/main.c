#include<stdio.h>
#include<stdlib.h>

typedef struct candidate{
    int id;
    char fullName[30];
    int votes;
}Candidate;

typedef struct elector{
    char cin[15];
    char fullName[30];
}Elector;

void readCdd(Candidate *p){
    p->votes = 0;
    printf("Enter the Id: ");
    fflush(stdin);
    scanf("%d",&p->id);
    printf("Enter Full Name: ");
    fflush(stdin);
    scanf("%s",p->fullName);
}

void readElector(Elector *p){
    printf("Enter the CIN: ");
    fflush(stdin);
    scanf("%s",p->cin);
    printf("Enter Full Name: ");
    fflush(stdin);
    scanf("%s",p->fullName);
}

void registerCandidates(Candidate *p,int len){
    for(int i=0;i<len;i++) {
        printf("\nRegistering candidate %d:\n\n",i+1);
        readCdd(&p[i]);}
}

void registerElectors(Elector *p,int len){
    for(int i=0;i<len;i++) {
        printf("\nRegistering Elector %d:\n\n",i+1);
        readElector(&p[i]);}
}

void displayCdd(Candidate p[],int len){
    printf("\n\n***** DISPLAYING CANDIDATES *****\n");
    for (int i = 0; i < len; i++)
    {
        printf("\nCandidate %d:\n",i+1);
        printf("   ID: %d\n",p[i].id);
        printf("   Name: %s\n",p[i].fullName);
    }
}

int main(){
    Candidate *c;
    int l = 3;
    c = (Candidate*)malloc(l*sizeof(Candidate));
    
    registerCandidates(c,l);
    displayCdd(c,l);

    return 0;
}


