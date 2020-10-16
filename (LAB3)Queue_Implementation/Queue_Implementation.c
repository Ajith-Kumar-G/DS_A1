#include<stdio.h>
#include<stdlib.h>
#define MAX 5



void operation(int *,int *,int *);
void enqueue(int ,int *,int *);
int dequeue(int *,int *,int *);
void displayQueue(int *,int *,int *);

int main()
{
    int front=0,rear=-1;
    int queue[MAX];
    operation(queue,&rear,&front);
    return 0;
}

void operation(int *queue,int *rear,int *front)
{
     int choice,element;
    do
    {
        element=0;
        choice=0;
        printf("\n\n Enter the Choice : \n\t\t 1.Enqueue\n\t\t 2.Dequeue\n\t\t 3.Display\n\t\t 4.Quit\n Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                  if(*rear==MAX-1)
                    printf("\n Queue Overflow!,Can't Enqueue, try other option!\n");
                  else
                    {
                        printf("\n Enter The element to Enqueue: ");
                        scanf("%d",&element);
                        enqueue(element,queue,rear);
                    }
                    break;
            case 2:
                   if(*rear ==-1)
                     printf("\n Queue Underflow!,Can't Dequeue, try other option!\n");
                   else
                     printf("\n %d was Dequeued from Queue \n",dequeue(queue,rear,front));
                     break;
            case 3:
                    displayQueue(queue,rear,front);
                    break;
            case 4:
                    exit(0);
            default:
                  {
                       element=0;
                       printf("\n Input Error!, press 1 to try again ! :");
                       fflush(stdin);
                       scanf("%d",&element);
                       if(element==1)
                            operation(queue,rear,front);
                        else
                            exit(0);

                  }

        }

    }while(1);
}


void enqueue(int ele,int *queue,int *rear)
{
    queue[++(*rear)]=ele;
}


int dequeue(int *queue,int *rear,int *front)
{
    int ele=queue[*front];
    if((*rear)==(*front))
    {
        *rear=-1;
        *front=0;
    }
    else
        *front+=1;
    return ele;
}


void displayQueue(int *queue,int *rear,int *front)
{
   if(*rear==-1)
        printf("\n The Queue is Empty! \n");
    else
   {
       printf("\n The Queue is : ");
       for(int i=*front;i<=*rear;i++)
       printf(" %d ",queue[i]);
   }

}
