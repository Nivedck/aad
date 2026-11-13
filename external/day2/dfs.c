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

void dfs(int source,int n){

    push(source);

    while(!isEmpty()){
        int u=pop();
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


int main() {
    int n = 4;

    int temp[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = temp[i][j];
        }
    }

    printf("DFS:");
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,n);
        }
    }

    return 0;
}
