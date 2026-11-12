//Exp2:DFS
#include <stdio.h>

int graph[20][20];
int visited[20],stack[20];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int isEmpty(){
    return (top==-1);
}

void dfs(int n , int source){
    visited[source]=1;
    push(source);
    
    while(!isEmpty()){
        int u = pop();

        if(!visited[u]){ 
            visited[u]=1;
            printf("%d ",u);

            for(int v=n-1;v>=0;v--){
                if(!visited[v]&&graph[u][v]){
                    push(v);
                }
            }
        }
    }
}

int main(){
    int n,source;
    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("Enter the Adj Matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter the source vertex:");
    scanf("%d",&source);

    dfs(n,source);
}