#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int front;
    int rear;
    int capacity;
    int *arr;
};
typedef struct Queue que;
que q;
void createQueue()
{
    int capacity = 10;
    char ch;
    q.front = -1;
    q.rear = -1;
    printf("Default Size of Que is :10. Do you want to change it?y/n ");
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        printf("\nEnter the new capacity\n");
        scanf("%d", &capacity);
    }
    q.capacity = capacity;
    q.arr = (int *)malloc(q.capacity * sizeof(int));
}
void enque()
{
    int ele;
    printf("\nEnter the element\n");
    scanf("%d", &ele);
    if (q.rear == -1)
    {
        q.front = q.rear = 0;
        q.arr[q.rear] = ele;
    }
    else if (q.rear == q.capacity - 1)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        q.rear++;
        q.arr[q.rear] = ele;
    }
}
void deque()
{
    int ele;
    if (q.front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else if (q.front == q.rear)
    {
        ele = q.arr[q.front];
        q.front = q.rear = -1;
    }
    else
    {
        ele = q.arr[q.front];
        q.front++;
    }
    printf("\n%d is deleted\n", ele);
}
void display()
{
    int i;
    if (q.rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\n");
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d ", q.arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    printf("Queue Operations\n");
    createQueue();
    do
    {
        printf("\n1)Enque \t 2)Deque \t 3)Display \t 4)Exit\n");
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
            free(q.arr);
            exit(0);
        }
    } while (choice != 4);

    return 0;
}