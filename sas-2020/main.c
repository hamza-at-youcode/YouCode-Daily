#include<stdio.h>
#include<stdlib.h>
#define MAX 100

char *elector[][2] = {
    {"Hamza","HH12345"},
    {"Fatima","E987763"},
    {"Yassine","M234566"},
    {"Jawad","A123456"},
    {"Rida","BB87733"},
    {"Outhman","N56683"},
    {"Rihab","R6245634"},
    {"ABD Ellah","S2354365"},
    {"Yassmine","Y7635276"},
    {"Arwa","AR26435634"}
};

char *cdd[][2] = {
    {"1","MARWAN Moitawakil"},
    {"2","SAID Zrghili"},
    {"3","MANAL Tawfik"},
    {"4","KARIM Soul"},
    {"5","KHADIJA Soultan"}
};

void displayCdd(char* e[][2],int len){
    for (int i = 0; i < len; i++)
    {
        printf("\nCandidate %d:\n",i+1);
        printf("   ID: %s\n",e[i][0]);
        printf("   Name: %s",e[i][1]);
    }
}

void vote(char* e[][2],int st[][2],int len){
    int voteFor;

    for (int i = 0; i < len; i++)
    {
        system("cls");
        
        displayCdd(cdd,5);
        
        printf("\n\n*****************************\n");
        printf("***** Elector ID: %s\n",e[i][1]);
        printf("***** Full Name: %s\n",e[i][0]);
        printf("*****************************\n");
        printf("\nYou wante to vote for: ");

        scanf("%d",&voteFor);
        st[voteFor-1][1]+=1;
    }
}

void round1(int nbrOfe,int nbrOfCdd,int stats[][2],int losers[]){
    float bar = 15;
    for (int i = 0; i < nbrOfCdd; i++){
        if ((stats[i][1]*nbrOfe)/100<bar)
        {
            losers[i] = i+1;
        }
    }
}

int main(){
    int stats[MAX][2]; // It contains the id of candidate and nbr of votes
    int numOfe = 10;
    int numOfCdd = 5;

    for (int i = 0; i < numOfCdd; i++) {
        stats[i][0] = i+1;
        stats[i][1] = 0;
    }

    vote(elector,stats,numOfe);
     
    for (int i = 0; i < numOfCdd; i++)
    {
        printf("Cdd %d => %d\n",stats[i][0],stats[i][1]);
    }
}