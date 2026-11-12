#include <stdio.h>
#define INF 99999
#define MAX 16

//second revision :( , forgetting everything.. 

int dis[MAX][MAX];
int dp[1<<MAX][MAX];
int n;

int tsp(int mask,int pos){
    if(mask==(1<<n)-1){
        return dis[pos][0];
    }
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    int ans=INF;
    for(int next = 0;next<n;next++){
        if((mask & (1<<next))==0){
            int cost = dis[pos][next] + tsp((mask | 1<<next),next);
            if(cost<ans) ans = cost;
        }
    }

    return dp[mask][pos]=ans;
}

int main(){
    printf("Enter the number of cities:");
    scanf("%d",&n);

    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }

    printf("Enter the distance matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&dis[i][j]);
        }
    }

    int min_cost = tsp(1,0);

    printf("Minimum Cost:%d",min_cost);
}

