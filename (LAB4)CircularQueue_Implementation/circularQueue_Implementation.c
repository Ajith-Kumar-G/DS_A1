#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int front=-1;
int rear=-1;

int queue[MAX];

void Enque(int);
int Deque();
void display();
void operation();

int main()
{
    printf("\n <-----Circular Queue----->\n");
    operation();
	return 0;
}

void operation()
{
    int option=0;
    int item;
    do{
        printf("\n 1. Insert to Queue (EnQueue)");
        printf("\n 2. Delete from the Queue (DeQueue)");
        printf("\n 3. Display the content ");
        printf("\n 4. Exit \n");
        printf("\n Enter the option :");
        scanf("%d",&option);
        switch(option)
        {
            case 1: if(front==(rear+1)%MAX)
                    {
                        printf("\n Queue Overflow! Try other Options");
                        operation();
                    }
                    else
                    {
                        printf("\n Enter the element: ");
                        scanf("%d",&item);
                        Enque(item);
                        break;
                    }
            case 2: if(front==-1 && rear==-1)
                    {
                        printf("\n Queue Underflow, it is empty! Try other Options");
                        operation();
                    }
                    else
                    {
                        item=Deque();
                        printf("\n Removed element from the queue is %d \n",item);
                        break;
                    }
            case 3: display();
                    break;
            case 4: exit(0);

            default:printf("\n Input Error! Try Again \n");
                    operation();
        }

    } while (1);

}

void Enque(int ele)
{
        rear=(rear+1)%MAX;
        queue[rear]=ele;
        if(front ==-1)
        front=0;
}
int Deque()
{
    int item;
    item=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
    return item;

}

void display()
{
    int i;
    if( front==-1 && rear==-1 )
    {
        printf("\n Queue is empty! Try other Options ");
        operation();
    }
    else
    {
        printf("\n Queue contents are: ");
        for(i=front;i!=rear;i=(i+1)%MAX)
            printf(" %d ", queue[i]);
            printf(" %d ", queue[i]);

    }
}
