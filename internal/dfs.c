#include <stdio.h>

int graph[10][10] ,visited[10],stack[10], n , start;
int top = -1;

void dfs(int start){
    stack[++top] = start;
    visited[start]=1;

    while(top!=-1){
        int u = stack[top--];
        printf("%d ",u);
        for(int v=n-1;v>=0;v++){
            if(graph[u][v] && !visited[v]){
                stack[++top]=v;
                visited[v];
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

    printf("DFS Traversal:");
    dfs(start);
}
