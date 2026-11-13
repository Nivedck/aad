#include <stdio.h>

typedef struct Item{
    int profit,weight,ratio;
}Item;


int main(){
    int n,W;;
    Item items[50];

    printf("Enter the number of items:");
    scanf("%d",&n);

    printf("Enter the items:");
    for(int i=0;i<n;i++){
        printf("Enter weight and profit of item %d:",i+1);
        scanf("%d %d",&items[i].weight,&items[i].profit);
        items[i].ratio = items[i].profit/items[i].weight;

    }

    printf("Enter the knapsack capacity:");
    scanf("%d",&W);

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(items[j].ratio>items[j+1].ratio){
                Item temp = items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }

    int capacity = W;
    int total_profit=0;
    
    for(int i=0;i<n;i++){
        if(items[i].weight<capacity){
            capacity -= items[i].weight;
            total_profit += items[i].profit;
        }else{
            total_profit += items[i].profit * capacity/items[i].weight;
        }
    }

    printf("Maximum Profit:%d \n",total_profit);
    
}