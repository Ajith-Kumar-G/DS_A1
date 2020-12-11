#include<stdio.h>
#include<stdlib.h>

struct node *top=NULL;

struct node
{
    int data;
    struct node *next;
};

void stack();
void push(int);
int pop();
void display();

int main()
{
    stack();
    return 1;
}

void stack()
{
    int choice=0,ele=0;
    do
    {
        printf("\n Enter the choice:\n 1.Push.\n 2.Pop.\n 3.Display.\n 4.Exit\n Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                printf("\n Enter the element to Push: ");
                scanf("%d",&ele);
                push(ele);
                break;
        case 2:
                ele=pop();
                printf("\n %d was deleted from Queue ",ele);
                break;
        case 3:
                display();
                break;
        case 4:
                exit(0);
        default:
                printf("\n Input Error Try Again! ");
                stack();
        }
    }while(1);
}

void push(int ele)
{
    struct node *newnode;
    newnode =(struct node *) malloc (sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }

    printf("\n Element %d was inserted!\n ",ele);

}
int pop()
{
     int ele;
     struct node *temp;
     if(top==NULL)
     {
         printf("\n Stack UnderFlow, The Stack is empty! \n");
         stack();
     }

     ele=top->data;
     temp=top;

     if(top->next==NULL)
     {
         top=NULL;
     }
     else
     {
        top=top->next;
     }
     free(temp);
     return ele;
}

void display()
{
    struct node *i;
    if(top==NULL)
     {
         printf("\n Stack is empty!\n ");
         stack();
     }
    printf("\n The Stack Contains:\n TOP->");
    for(i=top;i!=NULL;i=i->next)
        printf("\t%d ",i->data);

}
