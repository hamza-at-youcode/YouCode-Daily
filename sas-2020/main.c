#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
        printf("   Votes: %d\n",p[i].votes);
    }
}

void resetVotes(Candidate *p,int len){
    for(int i=0;i<len;i++) p->votes = 0;
}

int findCandidate(Candidate c[],int id,int cLen){
    for(int k=0;k<cLen;k++){
        if(c[k].id == id) return k;
    }
    return -1;
}

void vote(Elector e[],Candidate *c,int eLen,int cLen){
    int voteFor;
    int index = -1;

    for (int i = 0; i < eLen; i++)
    {
        system("cls");
        
        displayCdd(c,cLen);
        
        printf("\n\n------------- I am: ----------------\n");
        printf("------ Elector CIN: %s\n",e[i].cin);
        printf("------ Full Name: %s\n",e[i].fullName);
        printf("------------------------------------\n");
        printf("\nI vote for: ");

        scanf("%d",&voteFor);

        index =  findCandidate(c,voteFor,cLen);

        while(index == -1){
            printf("\nPlease enter a vilide ID: ");
            scanf("%d",&voteFor);
            index = findCandidate(c,voteFor,cLen);
        }

        c[index].votes+=1;
        
    }
}

int sortCandidates(Candidate *p,int len){
    int isSorted = 1;
    int i = 0,j;
    do{
        for (int j = 0; j < len-i-1; j++)
        {
            if (p[j].votes < p[j+1].votes)
            {
                int tmp = p[j].votes;
                p[j].votes = p[j+1].votes;
                p[j+1].votes = tmp;
                isSorted = 0;
            }
            
        }
        i++;
    }while(i<len-1 && !isSorted);

    return isSorted;
}

void menu(){
    printf("\n\n      ******** MENU ********\n");
    printf("   Press 1: to register candidates.\n");
    printf("   Press 2: to register electors.\n");
    printf("   Press 3: to start voting.\n");
    printf("   Press 4: to display candidates.\n");
    printf("   Press 5: to register candidates.\n");
    printf("   Press 6: to register candidates.\n");
    printf("   Press 7: to register candidates.\n");
    printf("   Press Q: to end this session.\n"); 
    printf("\n   Your choice: "); 
}

int main(){
    Candidate *c;
    Elector *e;
    int nbrOfc = 0,nbrOfe = 0;
    char choice;

    do{
        menu();
        choice = getch();
        switch(choice){
            case '1':{
                printf("\nEnter the numbre of candidates: ");
                scanf("%d",&nbrOfc);
                c = (Candidate*)malloc(nbrOfc*sizeof(Candidate));
                registerCandidates(c,nbrOfc);
            }break;

            case '2':{
                printf("\nEnter the numbre of electors: ");
                scanf("%d",&nbrOfe);
                e = (Elector*)malloc(nbrOfe*sizeof(Elector));
                registerElectors(e,nbrOfe);
            }break;

            case '3':{
                vote(e,c,nbrOfe,nbrOfc);
            }break;
            
            case '4':displayCdd(c,nbrOfc);break;

        }
    }while(choice != 'q' && choice != 'Q');

    return 0;
}


