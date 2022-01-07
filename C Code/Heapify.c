#include<stdio.h>
void displayHeap(int arr[],int n)
{
    printf("\n\tMinHeap  \n");
    int i = 0; //lc :left child, rc : right child
    int lc=2*i+1;
    int rc=lc+1;
    printf("\nRoot ");
    while (i < n)
    {
        printf("Node : %d\n", arr[i]);
        if (lc < n)
        {
            printf("Left Child : %d  ", arr[lc]);
        }
        else
        {
            printf("Left Child : -1  ");
        }

        if ((rc) < n)
        {
            printf("Right Child : %d", arr[rc]);
        }
        else
        {
            printf("Right Child : -1  ");
        }
        i++;
        printf("\n\n");
    }
}
void heapify(int arr[],int n,int i)
{
    
    int largest=i;
    int lc=2*i+1;  //lc :left child, rc: right child
    int rc=lc+1;
    
    if(lc<n && arr[lc]>arr[largest])
        largest=lc;
    if(rc<n && arr[rc]>arr[largest])
        largest=lc;
        
    if(largest!=i)
    {
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
    }
    heapify(arr,n,largest);

    
}

int main()
{
    int arr[]={10,19,14,26,127,42,31,33,44,35};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("\nn = %d",n);
    int start=(n/2)-1;
    printf("\nstart  = %d",start);

    for(int i=start;i>=0;i--)
    {
        heapify(arr,n,i);
        printf("\nHeapify");
    }

    //displayHeap(arr,n);
    
    return 0;
}