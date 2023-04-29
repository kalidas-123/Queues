/*C PROGRAM TO INSERT AND DELETE OPERATIONS USING QUEUES*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
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
    int i,j;

    if(cq.count == 0)
        printf("Circular queue is empty\n");
    else
    {
        j = cq.front;
        for(i = 0 ; i < cq.count ; i++)
        {
            printf("%d\n",cq.a[j]);
            j = (j + 1) % SIZE;
        }
    }
}

int main()
{
    struct queue cq;
    int choice,ele;
    cq.front = 0;
    cq.rear = -1;
    cq.count = 0;

    printf("The choices are as follows\n");
    printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");

    while(1)
    {
        printf("Enter the choice of operation\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    fn_insert(&cq,ele);
                    break;

            case 2: ele = fn_delete(&cq);
                    if(ele != -1)
                        printf("Element deleted is %d\n",ele);
                    break;

            case 3: printf("Elements of the queue are as follows\n");
                    fn_display(cq);
                    break;

            case 4: exit(0);

            default: printf("Invalid input\n");

        }
    }

    return 0;
}