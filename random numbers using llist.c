#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node head=NULL,cur,temp1;

node inserting(FILE *fp,int n)          //UDF TO inserting A NUMBER IN THE FILE
{
    int d,i;
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&d);                                      //READING THE VALUE FROM THE FILE
        node newn=(node)malloc(sizeof(struct NODE));             // ALLOCATING MEMORY FOR THE NEWNODE FOR THE DATA TO BE insertingED
        newn->data=d;
        newn->next=NULL;
        if(head==NULL)
        {
            head=newn;
        }
        else
        {
            temp1=head;
            head=newn;
            head->next=temp1;
        }
    }
}

void sort()                                              // UDF TO SORT THE NUMBER IN THE LINKED LIST
{
    cur=head;
    while(cur->next!=NULL)
    {
        temp1=head;
        while(temp1->next!=NULL)
        {
            if(temp1->data > temp1->next->data)
            {
                int x=temp1->data;
                temp1->data=temp1->next->data;
                temp1->next->data=x;
            }
            temp1=temp1->next;
        }
        cur=cur->next;
    }
}

void rad(FILE *fp,int n)                               // UDF TO WRITE THE RANDOM VARIABLES
{ int i;
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d\t",rand()%100);                      //rand() IS AN INBUILT FUNCTION TO GENERATE THE RANDOM VARIABLE
    }
}

void display(node head,FILE *fp)                                  // UDF TO DISPLAY THE CONTENT OF THE STRUCTURE
{
    temp1=head;
    while(temp1!=NULL)
    {
        fprintf(fp,"%d ",temp1->data);
        temp1=temp1->next;
    }
}

main()
{
    int n;
    FILE *fp;
    double start,stop;
    printf("Enter the range: ");
    scanf("%d",&n);
    fp=fopen("van.txt","w");              // OPENING THE FILE "sort.txt" TO WRITE THE DATA INTO IT
    rad(fp,n);
    fclose(fp);
    fopen("van.txt","r");             // OPENING THE FILE "sort.txt" TO READ THE DATA FROM IT
    inserting(fp,n);
    start=clock();
    sort();
    stop=clock();
    fclose(fp);
    fp=fopen("sort1.txt","w");
    display(head,fp);
    fprintf(fp,"\nTime taken: %lf",(stop-start)/CLOCKS_PER_SEC);
    fclose(fp);
}
