//Exp3: SCC
#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];
int trans[MAX][MAX];
int visited[MAX]={0};
int stack[MAX+1];
int top=-1;

void push(int x){
    stack[++top]=x; 
}

int pop(){
    return stack[top--];
}

void dfs1(int u,int n){
    visited[u]=1;
    for(int v=0;v<n;v++){
        if(graph[u][v] && !visited[v]){
            dfs1(v,n);
        }
    }
    push(u);
}

void dfs2(int u,int n){
    visited[u]=1;
    printf("%d ",u);
    for(int v=0;v<n;v++){
        if(trans[u][v]&& !visited[v]){
            dfs2(v,n);
        }
    }
}

int main(){
    
    int n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the graph(adj matrix):");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            trans[j][i]=graph[i][j];
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

    int count=0;
    printf("SCC's of graph: \n");
    while(top>=0){
        int curr=pop();
        if(!visited[curr]){
            count++;
            printf("SCC %d:",count);
            dfs2(curr,n);
            printf("\n");
        }
    }

}
