#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front=-1,rear=-1;

void enqueue(int x){
    rear++;
    queue[rear]=x;
    if(front==-1)front=0;
}

int dequeu(){
    return queue[front++];
}

int isEmpty(){
    if(front>rear || rear==-1){
        return 1;
    }else{
        return 0;
    }
}

void bfs(int n,int source){
    visited[source]=1;
    enqueue(source);
    while(!isEmpty()){
        int u=dequeu();
        printf("%d ",u);
        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v]){
                visited[v]=1;
                enqueue(v);
            }
        }
    }
}


int main(){
    int n=10;
    int source=0;

    int temp[10][10]={
        {0,1,1,0,0,0,0,0,0,0},
        {1,0,0,1,1,0,0,0,0,0},
        {1,0,0,0,0,1,1,0,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,0,1,0},
        {0,0,1,0,0,0,0,0,0,1},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0}
    };

    for(int i=0;i<n;i++){
        visited[i]=0;
        for(int j=0;j<n;j++){
            graph[i][j]=temp[i][j];
        }
    }

    printf("BFS Traversal: ");
    bfs(n,source);

    return 0;
}
