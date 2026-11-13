#include <stdio.h>
#define MAX 16
#define INF 999999

int dis[16][16];
int dp[1<<MAX][MAX]
int n

int tsp(int mask,int pos){
    if(mask==(1<<n)-1){
        return dis[pos][0];
    }

    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }

    int ans = INF;
    



}