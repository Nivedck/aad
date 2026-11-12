#include <stdio.h>

int dp[50][50];
int profit[50];
int weight[50];

int main(){
    int n,W;
    printf("Enter the number of items:");
    scanf("%d",&n);

    printf("Enter items:");
    for(int i=1;i<=n;i++){
        printf("Enter weight and profit of item %d",i);
        scanf("%d %d",&profit[i],&weight[i]);
    }

    printf("Enter the knapsack capacity:");
    scanf("%d",&W);

    for(int i=0;i<n;i++){
        for(int w=0;w<W;w++){
            if(w==0 || i==0){
                dp[i][w]=0;
            }
            if(weight[i]<w){
                dp[i][w]=max(dp[i-1][w],profit[i]+dp[i][w-weight[i]]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    int ans = dp[n][W];

    printf("Max profit:%d\n",ans);
}