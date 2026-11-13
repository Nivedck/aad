#include <stdio.h>
#define INF 99999
#define MAX 20

int dp[MAX][MAX];
int weights[MAX];
int profits[MAX];


int main(){
    int n, W;
    printf("Enter the number of items");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        printf("Enter the weight and profit of item %d:",i+1);
        scanf("%d %d",&weights[i],profits[i]);
    }

    printf("Enter the knapsack capacity:");
    scanf("%d",W);

    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(w==0 || i==0){
                dp[i][w]=0;
            }
            else if(weight[i]<=w){
                dp[i][w]=max(dp[i-1][w],profit[i]+dp[i-1][w-weights[i]]);
            }
            else{
                dp[i][w]= dp[i-1][w];
            }
        }
    }

    printf("Maximum profit:%d\n",dp[n][W]);
}