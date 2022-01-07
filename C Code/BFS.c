#include<stdio.h>
#define MAX 10
int adjmat[MAX][MAX];
int queue[MAX],visited[MAX],vertices,f=-1,r=-1;
int isempty_queue()
{
    if(f==-1 || f>r)
    return 1;
    else
    return 0;
}
void enque(int v)
{
    if(r==-1)
    {
        f=r=0;
        queue[r]=v;
    }
    else if(r==MAX-1)
    {
        printf("\nQueue is Full");
    }
    else
    {
        queue[++r]=v;
    }
}
int deque()
{
    int ele;
    if(f==-1)
    {
       printf("\nQueue is empty") ;
    }
    else if(f==r)
    {
        ele=queue[f];
        f=r=-1;
    }
    else
    {
        ele=queue[f];
        f++;
    }
    return ele;
}
void bfs(int v)
{
    enque(v);
    while(!isempty_queue())
    {
        v=deque();
        visited[v]=1;
        printf("%d  ",v);
        for(int i=0;i<vertices;i++)
        {
            if(adjmat[v][i]==1 && visited[i]==0)
            {
                enque(i);
                visited[i]=1;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     if(adjmat[v][i] && !visited[v])
    //         q[++r]=i;
    //     if(f<=r)
    //     {
    //         visited[++f]=1;
    //         bfs(q[f++]);
    //     }
    // }
}
int main()
{
    int vertices,v;
    printf("Enter the number of vertices present in the graph (max 10)");
    scanf("%d",&vertices);
    
    for(int i=0;i<MAX;i++)
        visited[i]=0;
    printf("Now enter the values for the adjacency matrix of the graphs\n");
    for(int i=0;i<vertices;i++)
        for(int j=0;j<vertices;j++)
            scanf("%d",&adjmat[i][j]);
    
    printf("\n Enter the starting vertex:");
	scanf("%d",&v);
    
   bfs(v);
    
    return 0;
}