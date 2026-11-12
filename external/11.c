#include <stdio.h>
#define INF 99999
#define MAX 16

int n;
int dis[MAX][MAX];
int dp[1<<MAX][MAX];

int tsp(int mask,int pos){
    if(mask==(1<<n)-1){
        return dis[pos][0];
    }
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }

    int ans = INF;

    for(int nextcity=0;nextcity<n;nextcity++){
        if((mask & (1<<nextcity))==0){
            int cost = dis[pos][nextcity] + tsp(mask | 1<<nextcity,nextcity);
            if(cost<ans){
                ans=cost;
            }
        }
    }

    return dp[mask][pos]=ans;
}

