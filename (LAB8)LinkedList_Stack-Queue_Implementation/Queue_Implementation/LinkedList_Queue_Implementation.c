#include<stdio.h>
#include<stdlib.h>
struct node *front=NULL, *rear=NULL;

struct node
{
    int data;
    struct node *next;
};

void queue();
void insNode(int);
int delNode();
void display();

int main()
{
    queue();

    return 1;
}

void queue()
{
    int choice=0,ele=0;
    do
    {
        printf("\n Enter the choice:\n 1.Insert.\n 2.Delete.\n 3.Display.\n 4.Exit\n Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                printf("\n Enter the element to Insert: ");
                scanf("%d",&ele);
                insNode(ele);
                break;
        case 2:
                ele=delNode();
                printf("\n %d was deleted from Queue ",ele);
                break;
        case 3:
                display();
                break;
        case 4:
                exit(0);
        default:
                printf("\n Input Error Try Again! ");
                queue();
        }
    }while(1);
}

void insNode(int ele)
{
    struct node *newnode;
    newnode =(struct node *) malloc (sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }

    printf("\n Element %d was inserted!\n ",ele);

}
int delNode()
{
     int ele;
     struct node *temp;
     if(front==NULL)
     {
         printf("\n Queue UnderFlow, The queue is empty! \n");
         queue();
     }

     ele=front->data;
     temp=front;

     if(front==rear)
     {
          front=NULL;
          rear=NULL;
     }
     else
     {
        front=front->next;
     }
     free(temp);
     return ele;
}

void display()
{
    struct node *i;
    if(front==NULL && rear==NULL)
     {
         printf("\n Queue is empty!\n ");
         queue();
     }
    printf("\n The Queue Contains:");
    for(i=front;i!=NULL;i=i->next)
        printf("%d ",i->data);

}
