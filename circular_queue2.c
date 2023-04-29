/*C PROGRAM TO IMPLEMENT THE FOLLOWING ON PRIORITY QUEUE, CONSISTING OF THREE QUEUES:
A.INSERT():-START INSERING THE ELEMENTS THE ELEMENTS INTO THE QUEUES FROM THE FIRST QUEUE
B.DELETE():-START DELETING THE ELEMENTS FROM THE FIRST QUEUE
C.DISPLAY()
NOTE:EACH QUEUE IS TO BE MAINTAINED AS A CIRCULAR QUEUE */

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
    int choice,ele;
    struct queue cq1,cq2,cq3;
    cq1.front = cq2.front = cq3.front = 0;
    cq1.rear = cq2.rear = cq3.rear = -1;
    cq1.count = cq2.count = cq3.count = 0;

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
                    
                    if(cq1.count != SIZE)
                        fn_insert(&cq1,ele);
                    else if(cq2.count != SIZE)
                        fn_insert(&cq2,ele);
                    else if(cq3.count != SIZE)
                        fn_insert(&cq3,ele);
                    else
                        printf("All the circular queues are full\n");
                    break;

            case 2: if(cq1.count != 0)
                    {
                        ele = fn_delete(&cq1);
                        printf("Element deleted from first queue is %d\n",ele);
                    }
                    else if(cq2.count != 0)
                    {
                        ele = fn_delete(&cq2);
                        printf("Element deleted from second queue is %d\n",ele);
                    }
                    else if(cq3.count != 0)
                    {
                        ele = fn_delete(&cq3);
                        printf("Element deleted from third queue is %d\n",ele);
                    }
                    else
                    {
                            printf("All the three queues are empty\n");
                    }    
                    break;

            case 3: printf("Element of the first queue are\n");
                    fn_display(cq1);
                    printf("Elements of the second queue are\n");
                    fn_display(cq2);
                    printf("Elements of the third queue are\n");
                    fn_display(cq3);
                    break;

            case 4:exit(0);

            default: printf("Invalid input\n");
            
        }
    }
    return 0;
}