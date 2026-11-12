#include <stdio.h>
#define INF 99999
#define MAX 20

int cost[MAX][MAX];
int visited[MAX];

int main(){
    int n,min,count,u,v;
    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("Enter cost matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ 
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0) cost[i][j]=INF;
        }
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    visited[0]=1;

    count=1;
    int mincost=0;

    printf("Minimum Spanning Tree:\n");
    while(count<n){
        min=INF;

        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j]&&cost[i][j]<min){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }

        printf("%d-%d:%d",u,v,min);
        mincost+=min;
        visited[v]=1;
        cost[u][v]=cost[v][u]=INF;
        count++;
    }

    printf("Minimum Cost:%d\n",min);

}