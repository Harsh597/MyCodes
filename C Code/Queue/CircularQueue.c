#include <stdio.h>
#include <stdlib.h>
struct Circularqueue
{
    int front;
    int rear;
    int capacity;
    int *arr;
};
typedef struct Circularqueue cque;
cque cq;
void createcqueue()
{
    int capacity = 10;
    char ch;
    cq.front = -1;
    cq.rear = -1;
    printf("Default Size of cque is :10. Do you want to change it?y/n ");
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        printf("\nEnter the new capacity\n");
        scanf("%d", &capacity);
    }
    cq.capacity = capacity;
    cq.arr = (int *)malloc(cq.capacity * sizeof(int));
}
void enque()
{
    int ele;
    printf("\nEnter the element\n");
    scanf("%d", &ele);
    if (cq.front == -1 && cq.rear == -1)
    {
        cq.front = cq.rear = 0;
        cq.arr[cq.rear] = ele;
    }
    else if ((cq.rear +1)%cq.capacity==cq.front)
    {
        printf("\nCircular queue is full\n");
    }
    else
    {
        cq.rear=(cq.rear+1)%cq.capacity;
        cq.arr[cq.rear] = ele;
    }
}
void deque()
{
    int ele;
    if (cq.front == -1 && cq.rear==-1)
    {
        printf("\ncqueue is empty\n");
    }
    else if (cq.front == cq.rear)
    {
        ele = cq.arr[cq.front];
        cq.front = cq.rear = -1;
    }
    else
    {
        ele = cq.arr[cq.front];
        cq.front=(cq.front+1)%cq.capacity;
    }
    printf("\n%d is deleted\n", ele);
}
void display()
{
    int i=cq.front;
    if (cq.rear == -1 && cq.front==-1)
    {
        printf("\ncqueue is empty\n");
    }
    else
    {
        printf("\n");
       while(i<=cq.rear)
        {
            printf("%d ", cq.arr[i]);
            i=(i+1)%cq.capacity;
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    printf("Circular cqueue Operations\n");
    createcqueue();
    do
    {
        printf("\n1)Encque \t 2)Decque \t 3)Display \t 4)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            free(cq.arr);
            exit(0);
        }
    } while (choice != 4);

    return 0;
}