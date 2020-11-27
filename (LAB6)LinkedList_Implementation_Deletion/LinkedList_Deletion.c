#include<stdio.h>
#include<stdlib.h>

struct node
{
    int id;
    char name[20];
    int sem;
    struct node *next;
};

struct node *head=NULL;

void linkedList();
void insertNode();
void deleteNode(int);
void deleteNodeAtBegin();
void deleteNodeAtEnd();
void deleteNodeOFGiven();
void displayList();

int size=0;

int main()
{
    linkedList();
    return 0;
}

void linkedList()
{
    int choice1,choice2;
    printf("\n\n <---Enter the Operation--->");
    printf("\n 1.Insert Node. \n 2.Delete Node \n 3.Display List\n 4.Exit.\n Choice: ");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:
                insertNode();
                break;
        case 2:
                printf("\n 1.At the First Position \t 2.At End of list\t 3.At Given Element Position\n Choice:");
                scanf("%d",&choice2);
                switch(choice2)
                {
                        case 1: deleteNode(1);
                                break;
                        case 2: deleteNode(2);
                                break;
                        case 3: deleteNode(3);
                                break;
                        default: printf("\n Input Error, try Again!\n ");
                                 linkedList();

                }
                break;

        case 3: displayList();
                break;

        case 4: exit(0);

        default: printf("\n Input error, Try again!!\n");
                 linkedList();
    }
}

void insertNode()
{
    struct node *newnode,*temp;
    newnode =(struct node *) malloc (sizeof(struct node));
    printf("\n <--Enter the Details--> ");
    printf("\n ID: ");  scanf("%d",&(newnode->id));
    printf(" Name: ");    scanf("%s",(newnode->name));
    printf(" Sem: ");  scanf("%d",&(newnode->sem));
    if (head==NULL)
     {
       newnode->next=NULL;
       head=newnode;
       printf("\n Node created\n");
       linkedList();
       size++;
     }
    for(temp=head;(temp->next)!=NULL;temp=(temp->next));
    newnode->next=NULL;

    {
            temp->next=newnode;
            size++;
            printf("\n Node created  \n");
            linkedList();
    }

}

void deleteNode(int flag)
{
    if(head==NULL)
    {
        printf("\n The List is Empty! \n");
        linkedList();
    }
    else
    if(head->next==NULL)
    {
         printf("\n Node Deleted. \n Now List Is empty! ");
         free(head);
         head=NULL;
        linkedList();
    }
    else
    {
        switch(flag)
        {
            case 1: deleteNodeAtBegin();
                    break;
            case 2: deleteNodeAtEnd();
                    break;
            case 3: deleteNodeOFGiven();
                    break;
        }

        linkedList();
    }
}

void deleteNodeAtBegin()
{
    struct node* temp=head;
    head=head->next;
    free(temp);
    printf("\n Node Deleted.");
}
void deleteNodeAtEnd()
{
    struct node* temp=head;
    for(temp;(temp->next)->next!=NULL;temp=temp->next);
    free(temp->next);
    temp->next=NULL;
    printf("\n Node Deleted.");
}
void deleteNodeOFGiven()
{
     struct node* temp1=head,*temp2=temp1;
     int ele;
     printf("\n Enter the Element :");
     scanf("%d",&ele);
     for(temp1;temp1->next!=NULL;temp1=temp1->next)
     {
         temp2=temp1->next;
         if(temp2->id==ele)
         {
             temp1->next=temp2->next;
             free(temp2);
             printf("\n Node Deleted.");
             return;
         }
         if(temp1->id==ele)
         {
             head=temp2;
             free(temp1);
             printf("\n Node Deleted.");
             return;
         }
     }
     printf("\n Element Not Present In List! ");
     linkedList();
}

void displayList()
{
   if(head==NULL)
    {
        printf("\n Empty List!\n");
        linkedList();
    }
    printf("\n The List is :");
    for(struct node *temp=head;temp!=NULL;temp=temp->next)
       {
        printf("\n\n <---Student Details--->");
        printf("\n ID: %d ",temp->id);
        printf("\n Name: %s ",temp->name);
        printf("\n Sem: %d",temp->sem);
         printf("\n <----------x---------->");
       }
       linkedList();
}

