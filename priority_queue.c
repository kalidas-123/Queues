/*C PROGRAM TO IMPLEMENT THE FOLLOWING ON PRIORITY QUEUE,CONSISTING OF THREE QUEUES
A.INSERT():START INSERTING THE ELEMENTS INTO QUEUES FROM THE FIRST QUEUE
B.DELETE():START DELETING THE ELEMENTS FROM THE FIRST QUEUE.
C.DISPLAY()
NOTE:EACH QUEUE IS TO BE MAINTNED AS A CIRCULAR QUEUE. */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
struct queue 
{
    int a[SIZE],front,rear,count;
};

void fn_insert(struct queue *cq,int ele)
{
    if(cq->count == SIZE)
        printf("Circular queue is full\n");
    else
    {
        cq->rear = (cq->rear + 1) % SIZE;
        cq->a[cq->rear] = ele;
        cq->count++;
    }
}

int fn_delete(struct queue *cq)
{
    int ele;
    if(cq->count == 0)
    {
        printf("Circular queue is empty\n");
        return -1;
    }
    else
    {
        ele = cq->a[cq->front];
        cq->front = (cq->front + 1) % SIZE;
        cq->count--;
        return ele;
    }
}

void fn_display(struct queue cq)
{
    int i,j = cq.front;
    if(cq.count == 0)
        printf("Circular queue is empty\n");
    else
    {
        for(i = 0 ; i < cq.count ; i++)
        {
            printf("%d\n",cq.a[j]);
            j = (j + 1) % SIZE;
        }
    }
}

int main()
{
    struct queue cq[3];
    int choice,ele,qno;
    cq[0].front = cq[1].front = cq[2].front = 0;
    cq[0].rear = cq[1].rear = cq[2].rear = -1;
    cq[0].count = cq[1].count = cq[2].count = 0;
    
    printf("The choices are as follows\n");
    printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");

    while(1)
    {
        printf("Enter the choice of operation\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the queue number\n");
                    scanf("%d",&qno);
                    printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    fn_insert(&cq[qno - 1],ele);
                    break;

            case 2: printf("Enter the queue number\n");
                    scanf("%d",&qno);
                    ele = fn_delete(&cq[qno - 1]);
                    if(ele != -1)
                        printf("Element deleted from %d queue is %d\n",qno - 1,ele);
                    break;

            case 3: printf("Elements of the first queue are\n");
                    fn_display(cq[0]);
                    printf("Elements of the second queue are\n");
                    fn_display(cq[1]);
                    printf("Elements of the third queue are\n");
                    fn_display(cq[2]);
                    break;

            case 4: exit(0);

            default:printf("Invalid input\n");

        }
    }
    return 0;
}