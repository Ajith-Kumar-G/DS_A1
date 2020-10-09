#include<stdio.h>
#include<stdlib.h>
#define size 50
int top=-1;
char stack[size];

//Expression Intake
void getData(char *infix)
{
    printf("\nEnter The Infix Expression: ");
    scanf("%s",infix);
}
//PUSH and POP operation
void PUSH(int item)
{
    if(top==size-1)
        printf("\nStack Overflow, the expression exceeds the stack limits!");
    else
    stack[++top]=item;
}
char POP()
{
    if(top==-1)
        printf("\nStack Underflow, Stack is Empty!");
    else
    {
        int popItem=stack[top--];
        return popItem;
    }
}
//checking priority
int check(char ch)
{
    switch(ch)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
    default:  return 0;
    }
}

//Main

int main()
{
    char inFix[50],item,postFix[50];
    int k=0;
    getData(inFix);
    for(int i=0;inFix[i]!='\0';i++)
    {
        switch(inFix[i])
        {
            case '(' :  PUSH(inFix[i]);
                        break;
            case ')' :  while((item=POP())!='(')
                        postFix[k++]=item;
                        break;
            case '+':

            case '-':

            case '*':

            case '^':

            case '/':
                        while(check(stack[top])>=check(inFix[i]))
                        {
                            item=POP();
                            postFix[k++]=item;
                        }
                        PUSH(inFix[i]);
                        break;
            default :  postFix[k++]=inFix[i];
                        break;
        }


    }
    while(top!=-1)
        {
            item=POP();
            postFix[k++]=item;
        }
     postFix[k++]='\0';
    printf("\nThe PostFix Expression is : %s",postFix);
    return 0;
}
