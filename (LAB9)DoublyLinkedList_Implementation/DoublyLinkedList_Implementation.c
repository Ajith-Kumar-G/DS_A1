#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node *next;
}Node;

Node *head=NULL;

void doublyLinkedList();
void insertNode(int);
void insertNodeToLeft();
void insertNodeToRight();
void deleteSpecifiedValue();
void displayList();

int main()
{
    doublyLinkedList();
    return 0;
}

void doublyLinkedList()
{
    int choice=0;
    printf("\n <--Doubly Linked List-->");
    printf("\n 1.Enter Node\n 2.Enter Node to Left\n 3.Enter Node to Right\n 4.Delete A Node\n 5.DisplayList\n 6.Exit\n Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insertNode(0);
                break;
        case 2: insertNode(1);
                break;
        case 3: insertNode(2);
                break;
        case 4: deleteSpecifiedValue();
                break;
        case 5: displayList();
                break;
        case 6: exit(0);

        default: printf("\n Error choice, Try Again! ");
                    doublyLinkedList();
    }
    doublyLinkedList();
}

void insertNode(int flag)
{
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    printf("\n Enter the Element: ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
        printf("\n First Node created \n");
        doublyLinkedList();
    }
    if(flag==0)
    {
         Node *temp=head;
         for(temp;(temp->next)!=NULL;temp=temp->next);
         temp->next=newnode;
         newnode->prev=temp;
         newnode->next=NULL;
    }
    else
        if(flag==1)
        insertNodeToLeft(newnode);
    else
        insertNodeToRight(newnode);
}
void insertNodeToRight(Node *tempNew)
{
    int ele;
    char choice;
    printf("\n Enter the Node element To who's right you want to Insert Node: ");
    scanf("%d",&ele);
    Node *temp=head;
    for(temp;temp!=NULL;temp=temp->next)
        {
            if(temp->data==ele)
            {
                  if(temp->next!=NULL)
                  {
                        tempNew->next=temp->next;
                        tempNew->prev=temp;
                        (temp->next)->prev=tempNew;
                        temp->next=tempNew;
                        printf("\n Node created \n");
                        doublyLinkedList();
                    }
                    else
                    {
                        tempNew->next=NULL;
                        tempNew->prev=temp;
                        temp->next=tempNew;
                        printf("\n Node created \n");
                        doublyLinkedList();
                    }

            }
        }
    printf("\n The given Element was not found! ,press Y to Try again! or press anything to exit: ");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='Y' || choice =='y')
    insertNodeToRight(tempNew);
    else
    {
        free(tempNew);
        printf("\n Node creation Failed \n");
        doublyLinkedList();
    }

}
void insertNodeToLeft(Node *tempNew)
{
    int ele;
    char choice;
    printf("\n Enter the Node element To who's left you want to Insert Node: ");
    scanf("%d",&ele);
    Node *temp=head;
    if(head->data==ele)
    {
        tempNew->next=head;
        tempNew->prev=NULL;
        head=tempNew;
        printf("\n Node created \n");
        doublyLinkedList();
    }
    for(temp;temp!=NULL;temp=temp->next)
        {
            if(temp->data==ele)
            {
                    tempNew->next=temp;
                    tempNew->prev=temp->prev;
                    (temp->prev)->next=tempNew;
                    temp->prev=tempNew;
                    printf("\n Node created \n");
                    doublyLinkedList();

            }
        }
    printf("\n The given Element was not found! ,press Y to Try again! or press anything to exit: ");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='Y' || choice =='y')
    insertNodeToLeft(tempNew);
    else
    {
        free(tempNew);
        printf("\n Node creation Failed \n");
        doublyLinkedList();
    }

}
void deleteSpecifiedValue()
{
    if(head==NULL)
    {
        printf("\n Empty List!\n");
        doublyLinkedList();
    }
    int ele;
    printf("\n Enter the Node element to delete: ");
    scanf("%d",&ele);
    Node *temp=head;
    if(head->next==NULL)
    {
        if(head->data==ele)
        {
            free(temp);
            head=NULL;
            printf("\n Node Deleted. \n Now List Is empty! ");
            doublyLinkedList();
        }
    }
     else
     {
         for(temp;temp!=NULL;temp=temp->next)
        {
            if(temp->data==ele)
            {
                    if(temp->next==NULL)
                    {
                        (temp->prev)->next=NULL;
                        free(temp);
                        printf("\n Node Deleted \n");
                        doublyLinkedList();
                    }
                    if(temp->prev==NULL)
                    {
                        (temp->next)->prev=NULL;
                        head=head->next;
                        printf("\n Node Deleted \n");
                        doublyLinkedList();
                    }
                    else
                    {
                        (temp->prev)->next=temp->next;
                        (temp->next)->prev=temp->prev;
                        free(temp);
                        printf("\n Node Deleted \n");
                        doublyLinkedList();
                    }
            }
        }
     }
     printf("\n The given element %d is not present in list!\n ",ele);
}

void displayList()
{
    if(head==NULL)
    {
        printf("\n Empty List!\n");
        doublyLinkedList();
    }
    Node *temp=head;
    printf("\n The List Contains :");
    for(temp;temp!=NULL;temp=temp->next)
       {
        printf(" %d ",temp->data);
       }
    doublyLinkedList();
}

