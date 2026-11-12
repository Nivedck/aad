#include <stdio.h>

int graph[20][20],q[20],n,visited[20],start;
int front =0 , rear = -1 ;

void bfs(int start){
    q[++rear]=start;
    visited[start] = 1;

    while(front<=rear){
        int u =q[front++];
        printf("%d ",u);
        for(int v=0;v<n;v++){
            if( !visited[v] && graph[u][v]==1){
                q[rear++]=v;
                visited[v]=1;
            }
        }
    }
}

int main(){
    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("Enter the Adjacency matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter source vertex: \n");
    scanf("%d",&start);

    printf("BFS Traversal:");
    bfs(start);
}
