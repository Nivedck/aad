#include <stdio.h>

int graph[20][20];
int trans[20][20];
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

void dfs1(int u,int n){
    visited[u]=1;
    for(int v=0;v<n;v++){
        if(!visited[v]&&graph[u][v]){
            dfs1(v,n);
        }
    }
    push(u);
}

void dfs2(int u,int n){
    visited[u]=1;
    printf("%d",u);
    for(int i=0;i<n;i++){
        if(!visited[i]&&trans[u][i]){
            dfs2(i,n);
        }
    }
}

int main(){
    int n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("Enter the graph:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            trans[i][j] = graph[j][i];
        }
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs1(i,n);
        }
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    printf("Strongly connected componenets:");
    int count=0;

    while(!isEmpty()){
        int u=pop();
        if(!visited[u]){
            count++;
            printf("SCC component %d",count);
            dfs2(u,n);
            printf("\n");
        }
    }
}