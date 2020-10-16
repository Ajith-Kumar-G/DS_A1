#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 5
int TOP=-1;

void operation(int[]);
void PUSH(int [],int);
int POP (int[]);
void DISPLAY(int[]);

int main()
{
    int stack[SIZE];
    operation(stack);
    return 0;
}

void operation(int stack[])
{
    int choice,ele,popele;
    char flag ;

    do{
        printf("\nEnter The choice: \n\t1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\n\nChoice : ");
        scanf("%d",&choice);
        switch(choice)
          {
            case 1:if(TOP==SIZE-1)
                    {
                        printf("\nThe Stack is full: OVERFLOW! Try other choices\n");
                        operation(stack);
                    }
                    else
                    {
                        printf("\nEnter The Element to be pushed: ");
                        scanf("%d",&ele);
                        PUSH(stack,ele);
                        printf("\nThe Element %d was pushed successfully",ele);
                    }
                    break;
             case 2: if(TOP==-1)
                    {
                        printf("\nThe Stack is Empty: Underflow! Try other choices\n ");
                        operation(stack);
                    }
                    else
                    {
                        popele=stack[TOP];
                        POP(stack);
                        printf("\nThe Element %d was popped successfully ",popele);
                    }
                    break;
             case 3:
                    printf("\nThe Stack Elements are : \n");
                    DISPLAY(stack);
                    break;
            case 4:return;
             default:
                 {
                     printf("\nInput choice ERROR! Try again! ");
                     operation(stack);
                 }

          }

       printf("\n\nDo you wish to continue operations ? Press Y to continue  : ");
       fflush(stdin);
       flag=getchar();
    }while(toupper(flag)=='Y');

}
 void PUSH(int stack[],int ele)
{
    TOP++;
    stack[TOP]=ele;
}
int POP(int stack[])
{
    int popele=stack[TOP];
    TOP--;
    return popele;
}
void DISPLAY(int stack[])
{
    for(int i=TOP;i>=0;i--)
        printf("\n\t%d ",stack[i]);
}
