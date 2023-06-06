#include<stdio.h>
void read(int a[90][90],int b[90][90],int r1,int c1,int r2,int c2);
void display(int a[90][90],int b[90][90],int r1,int c1,int r2,int c2);
void multi(int a[90][90],int b[90][90],int r1,int c1,int r2,int c2);

int main()
{
    int i,j,r1,c1,r2,c2;
    int r,c,a[i][j],b[i][j];
    printf("Enter r1 c1 r2 c2 \n");
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    read(a,b,r1,c1,r2,c2);
    display(a,b,r1,c1,r2,c2);
    multi(a,b,r1,c1,r2,c2);

}

void read(int a[90][90],int b[90][90],int r1,int c1,int r2,int c2)
{
    int i,j;
    printf("Enter values for 1st matrix\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf(" %d",&a[i][j]);
        }
    }
     printf("Enter values for 2nd matrix\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf(" %d",&b[i][j]);
        }
    }

}
void display(int a[90][90],int b[90][90],int r1,int c1,int r2,int c2)
{
    int i,j;
    printf(" values for matrix1\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    printf(" values for matrix2\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf(" %d",b[i][j]);
        }
        printf("\n");
    }
}

void multi(int a[90][90],int b[90][90],int r1,int c1,int r2,int c2)
{
    int k,i,j,c[i][j],sum;
     if(r2==c1)
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                sum=0;
                for(k=0;k<r2;k++)
                    sum=sum+a[i][k]*b[k][j];
                c[i][j]=sum;
            }
        }

            for(i=0;i<r1;i++)
           {
              for(j=0;j<c2;j++)
                    printf("%d ",c[i][j]);
            }
    }
}
