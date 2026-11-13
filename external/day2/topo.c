#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];
int stack[MAX];
int top=-1;
int visited[MAX];

void push(int x){
    top++;
    stack[top]=x;
}

int pop(){
    return stack[top--];
}


void dfs(int u,int n){
    visited[u]=1;
    for(int v=0;v<n;v++){
        if(!visited[v]&&graph[u][v]){
            dfs(v,n);
        }
    }
    push(u);
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

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n);
        }
    }

    printf("Topological Sort: ");

    while(top != -1) {
        printf("%d ", pop());
    }

    return 0;
}
