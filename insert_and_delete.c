/*C PROGRAM TO TO PERFORM INSERT AND DELETE OPERATIONS USING QUEUES*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
struct queue
{
    int a[SIZE],front,rear;
};

void fn_insert(struct queue *q,int ele)
{
    if(q->rear == SIZE -1)
        printf("Queue Overflow\n");
    else 
    {
        q->a[++q->rear] = ele;
    }
}

int fn_delete(struct queue *q)
{
    int ele;
    if(q->front > q->rear)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        ele = q->a[q->front++];
        return ele;
    }
}

void fn_display(struct queue q)
{
    int i;

    if(q.front > q.rear)
    {
        printf("Queue is empty\n");
    }
    else 
    {
        for(i = q.front ; i <= q.rear ; i++)
            printf("%d\n",q.a[i]);
    }
}

int main()
{
    struct queue q;
    q.front = 0;
    q.rear = -1;
    int choice,ele;

    printf("The choices are as follows\n");
    printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");

    for(;;)
    {
        printf("Enter the choice of operation\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    fn_insert(&q,ele);
                    break;

            case 2: ele = fn_delete(&q);
                    if(ele != -1)
                        printf("Element deleted is %d\n",ele);
                    break;

            case 3: printf("Elements of the queue are as follows\n");
                    fn_display(q);
                    break;

            case 4: exit(0);

            default :printf("Invalid input\n");
        }
    }
    return 0;
}