#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char getChoice(){
    printf("\n\n   ***** Records Management *****\n");
    printf("\tPress 1 to enter new records.\n");
    printf("\tPress 2 to display records.\n");
    printf("\tPress 3 to sort your records.\n");
    printf("\tPress 4 to find a record.\n");
    printf("\tPress 5 to delete a record.\n");
    printf("\tPress c to clear screen.\n");
    printf("\tPress 0 to exit.\n");
    printf("   *****************************\n");
    printf("   Your choice: ");

    return getch();
}

void readRecords(int *p,int len){
    for (int i = 0; i < len; i++)
    {
        printf("Enter record [%d]: ",i+1);
        scanf("%d",p+i);
    }
}

void displayRecords(int *p,int len){
    printf("\n\nRecords = |");
    for (int i = 0; i < len; i++)
    printf(" %d |",*(p+i));
}

int sortRecs(int *p,int len){
    int isSorted = 1;
    int i = 0,j;
    do{
        for (int j = 0; j < len-i-1; j++)
        {
            if (*(p+j) > *(p+j+1))
            {
                int tmp = *(p+j+1);
                *(p+j+1) = *(p+j);
                *(p+j) = tmp;
                isSorted = 0;
            }
            
        }
        i++;
    }while(i<len-1 && !isSorted);

    return isSorted;
}

int findRec(int *p,int len,int x){
    int low = 0,high = len-1,mid;
    int found = -1;
    sortRecs(p,len);
    do
    {
        mid = (int)(low+high)/2;
        if(*(p+mid) > x) high = mid-1;
        else if (*(p+mid) < x) low = mid+1;
        else found = mid;
        
    } while (low<=high && found == -1);

    return found;
}

void deleteRec(int *p,int *size,int x){
    int pos = findRec(p,*size,x);
    if (pos != -1){
        (*size)--;
        for (int i = pos; i < *size; i++) *(p+i) = *(p+i+1);
        p = (int*)realloc(p,(*size) * sizeof(int));
        printf("\nRecord %d deleted successfully!",x);
    }else printf("\nRecord %d does not exist!",x);
}

void addRecord(int *p,int *size){
    int r,w;
    printf("\nOn progress...\n");return;
    printf("Enter a record: ");scanf("%d",&r);
    printf("Where do you want to add this record: ");scanf("%d",&w);
}

void _continue(){
    printf("\nPress any key to continue /");
    char c = getch();
}

void clear(){
    system("cls");
}

int main(){
    int *rec,size=0;
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
            scanf("%d",&size);
            rec = (int*)malloc(size*sizeof(int));
            printf("\n");
            readRecords(rec,size);
            break;
        case '2':
            displayRecords(rec,size);
            _continue();
            break;
        case '3':
            isSorted = sortRecs(rec,size);
            if (isSorted) printf("\n\nRecords are already sorted!\n");
            else printf("\n\nRecords sorted successfully!\n");
            _continue();
            break;
        case '4':{
                int x;
                printf("\nEnter a record: ");
                scanf("%d",&x);
                int pos = findRec(rec,size,x);
                if (pos == -1) printf("\n%d does not exist!!\n",x);
                else printf("\n%d exits at position %d\n",x,pos);
                _continue();
            }
        break;
        case '5':{
            int r;
            printf("\nEnter a record to delete: ");
            scanf("%d",&r);
            deleteRec(rec,&size,r);
            _continue();
        }  
        case 'c':clear();break;  
        default:
            clear();
            printf("\n\n**** Take a coffee and try again ;) ****\n");
            break;
        }
    } while (ch != '0');
    
    return 0;
}