//exp1: BFS
#include <stdio.h>

int graph[20][20];
int queue[20], visited[20]={0};
int front=-1,rear=-1;

void enqueue(int x){
    queue[++rear]=x;
    if(front==-1) front=rear;
}

int dequeue(){
    return queue[front++];
}

int isEmpty(){
    if(front>rear || front==-1){
        return 1;
    }
    return 0;
}

void bfs(int n,int source){
    visited[source]=1;
    enqueue(source);

    while(!isEmpty()){
        int u = dequeue();
        printf("%d ",u);

        for(int v=0;v<n;v++){
            if(!visited[v]&&graph[u][v]==1){
                enqueue(v);
                visited[v]=1;
            }
        }
    }
}

int main(){
    int n,source;

    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("Enter the graph(Adj Matrix):");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter source vertex:");
    scanf("%d",&source);
    bfs(n,source);


}