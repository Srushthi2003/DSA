#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[100][100],b[100][100],c[100][100];
int i,j,k;
void read(FILE *fp,int a[100][100],int n);
void display(FILE *fp,int a[100][100],int n);
void trans(FILE *fp,int a[100][100],int n);



int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("array.txt","r");
    fp2=fopen("array1.txt","w");
    int n;
    clock_t start,end;
    double total;
    start=clock();
    printf("enter n\n");
    scanf("%d",&n);
    read(fp1,a,n);
    display(fp2,a,n);
    trans(fp2,a,n);
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time:%f\n ",total);
    fclose(fp1);
    fclose(fp2);

}
void read(FILE *fp,int a[100][100],int n)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp,"%d ",&a[i][j]);
        }
    }
}
void display(FILE *fp,int a[100][100],int n)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fprintf(fp,"%d ",a[i][j]);
        }
        fprintf(fp,"\n");
    }
}
void trans(FILE *fp,int a[100][100],int n)
{

    int temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<j)
            {
            temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
            }
             fprintf(fp," %d ",a[i][j]);
        }

        fprintf(fp,"\n");
    }


}
