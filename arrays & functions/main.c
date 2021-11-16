#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

char getChoice(){
    printf("\n\n   ***** Records Management *****\n");
    printf("Press 1 to enter new records.\n");
    printf("Press 2 to display records.\n");
    printf("Press 3 to sort your records.\n");
    printf("Press 4 to find a record.\n");
    printf("Press c to clear screen.\n");
    printf("Press 0 to exit.\n");
    printf("   Your choice: ");
    return getch();
}

void readRecords(int rec[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("Enter record [%d]: ",i+1);
        scanf("%d",rec+i);
    }
}

void displayRecords(int rec[],int len){
    printf("\n\nRecords = |");
    for (int i = 0; i < len; i++)
    printf(" %d |",rec[i]);
}

int sortRecs(int rec[],int len){
    int isSorted = 1;
    int i = 0,j;
    do{
        for (int j = 0; j < len-i-1; j++)
        {
            if (rec[j]>rec[j+1])
            {
                int tmp = rec[j];
                rec[j] = rec[j+1];
                rec[j+1] = tmp;
                isSorted = 0;
            }
            
        }
        i++;
    }while(i<len-1 && !isSorted);

    return isSorted;
}

int findRec(int rec[],int len,int x){
    int low = 0,high = len-1,mid;
    int found = -1;
    sortRecs(rec,len);
    do
    {
        mid = (int)(low+high)/2;
        if(rec[mid] > x) high = mid-1;
        else if (rec[mid] < x) low = mid+1;
        else found = mid;
        
    } while (low<=high && found == -1);

    return found;
}

void _continue(){
    printf("\nPress any key to continue /");
    char c = getch();
}

void clear(){
    system("cls");
}

int main(){
    int arr[MAX],len=0;
    int isSorted,c;
    char ch;
    
    do
    {
        ch = getChoice();
        switch (ch)
        {
        case '0':break;
        case '1':
            printf("\nHow many record: ");
            scanf("%d",&len);
            printf("\n");
            readRecords(arr,len);
            break;
        case '2':
            displayRecords(arr,len);
            _continue();
            break;
        case '3':
            isSorted = sortRecs(arr,len);
            if (isSorted) printf("\n\nRecords are already sorted!\n");
            else printf("\n\nRecords sorted successfully!\n");
            _continue();
            break;
        case '4':{
                int x;
                printf("\nEnter a record: ");
                scanf("%d",&x);
                int pos = findRec(arr,len,x);
                if (pos == -1) printf("\n%d does not exist!!\n",x);
                else printf("\n%d exits at position %d\n",x,pos);

                _continue();
            }
        break;  
        case 'c':clear();break;  
        default:
            clear();
            printf("\n\n**** Take a coffee and try again ;) ****\n");
            break;
        }
    } while (ch != '0');
    

    
    
    

    return 0;
}