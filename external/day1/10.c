#include <stdio.h>

int dp[100][100];
int profit[50];
int weight[50];

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int n,W;
    printf("Enter the number of items:");
    scanf("%d",&n);
    printf("Enter the items(weight,profit):");
    for(int i=1;i<=n;i++){
        scanf("%d %d",&weight[i],&profit[i]);
    }

    printf("Enter the knapsack capacity:");
    scanf("%d",&W);

    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
            }
            else if(weight[i]<=w){
                dp[i][w]=max(dp[i-1][w],profit[i]+dp[i][w-weight[i]]);
            }
            else{
                dp[i][w]= dp[i-1][w];
            }
        }
    }

    printf("Maximum profit:%d\n",dp[n][W]);

}