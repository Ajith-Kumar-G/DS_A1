#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1=NULL,*head2=NULL;

void linkedList();
int choiceFlag();
void insert(int);
void display(int);
void reverse(int);
void sorting(int);
void swap(struct node*,struct node*);
void concate();

int main()
{
    linkedList();
    return 1;
}

void linkedList()
{
    int choice1,choice2;
    printf("\n 1. Insert  \n 2. Display  \n 3. Reverse \n 4. Sort \n 5. Concatinate and display \n 6. Exit");
    printf("\n Enter your choice : ");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1: choice2=choiceFlag();insert(choice2); break;
        case 2: choice2=choiceFlag();display(choice2);break;
        case 3: choice2=choiceFlag();reverse(choice2);break;
        case 4: choice2=choiceFlag();sorting(choice2);break;
        case 5: concate();break;
                break;
        case 6:exit(0);
        default:printf("\n Try Again!\n");
    }
   linkedList();
}

int choiceFlag()
{
    int flag=0;
    do{
    printf("\n 1.First List\n 2.Second List\n Choice: ");
    scanf("%d",&flag);
    if(flag!=1 && flag!=2)
        printf("\n Error choice, Try again! ");
    }
    while(flag!=1 && flag!=2);

    return flag;
}

void insert(int flag)
{
    struct node *newnode,*temp,**head;
    int item;
    newnode =(struct node *) malloc (sizeof(struct node));
    printf(" Enter the data : ");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=NULL;

    if(flag==1)
    head=&head1;
    else
    head=&head2;


    if (*head==NULL)
     {
       *head=newnode;
       printf("\n First Node created\n");
     }
     else
    {
        temp=*head;

        while(temp->next!=NULL)
        {
                temp=temp->next;
        }
        temp->next=newnode;

       printf("\n Next Node created\n");
   }

}
void reverse(int flag )
{

    struct node **head;

    if(flag==1)
    head=&head1;
    else
    head=&head2;

    if(*head==NULL)
    {
        printf("\n List Empty! \n");
        return;
    }

    struct node *pre=NULL,*forw=NULL,*cur=*head;

    while(cur!=NULL)
    {
        forw=cur->next;
        cur->next=pre;
        pre=cur;
        cur=forw;
    }
    *head=pre;
    printf("\n Reversed! \n");
}
void sorting(int flag )
{
    struct node **head;
    int swapFlag;
    if(flag==1)
    head=&head1;
    else
    head=&head2;

    if(*head==NULL)
    {
        printf("\n List Empty! \n");
        return;
    }

    struct node *temp1=*head,*temp2=NULL;
    do
    {
        temp1 = *head;
        swapFlag = 0;
        while (temp1->next!=temp2)
        {
            if (temp1->data > (temp1->next)->data)
            {
                swap(temp1, temp1->next);
                swapFlag=1;
            }
            temp1=temp1->next;
        }
        temp2=temp1;
    }
    while (swapFlag);
    printf("\n Sorted! \n");
}

void swap(struct node *t1, struct node *t2)
{
    int temp = t1->data;
    t1->data = t2->data;
    t2->data = temp;
}

void concate()
{
    struct node *temp1=head1,*temp2=head2;

    while(temp1->next!=NULL)
    temp1=temp1->next;
    temp1->next=temp2;
    display(0);
}

void display(int flag)
{
    struct node *ptr;
    if(flag==1)
    ptr=head1;
    else
    if(flag==2)
    ptr=head2;
    else
    ptr=head1;

    if(ptr==NULL)
    {
        printf("\n List Empty! \n");
    }
    else
    {
        printf("\n");
        while(ptr!=NULL)
       {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
       }
    }

}



