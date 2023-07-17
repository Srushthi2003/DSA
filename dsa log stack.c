#include<stdio.h>
#include<stdlib.h>
int push(int data,int n);
int isfull(int n);
int pop();
int stack[10];
int top=-1;
int main()
{
    int n; int a[10]; int op; int data;
    printf("Enter n\n");
    scanf("%d",&n);
    FILE *p;
    p = fopen("randomnum.txt","w");
    for(int i=0;i<n;i++)
    {
        a[i] = rand()%100;
    }
    for(int i=0;i<n;i++)
    {
       fprintf(p,"%d\n",a[i]);
    }
    while(1)
    {
        printf("Enter 1 --- Push Opeartion");
        printf("Enter 2 --- Pop Operation\n");
        printf("enter 3 --- exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:scanf("%d",&data);
            top = push(data,n);
            printf("VALUE = %d\n",stack[top]);
            break;
            case 2: top = pop();
            break;
            case 3:exit(0);
            break;
        }
        }
    }
int push(int data,int n){
   if(!isfull(n)) {
      top = top + 1;
      stack[top] = data;
      return top;
   } else {
      printf("Could not insert data, Stack is full.\n");
      return top;
   }
}
int isfull(int n){
   if(top == n)
      return 1;
   else
      return 0;
}
int pop()
{
   int data;
      data = stack[top];
      top = top - 1;
      return top;
}
