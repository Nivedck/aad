#include <stdio.h>

typedef struct Item{
    int profit;
    int weight;
    float ratio;
}Item;

int main(){
    int n,w;

    printf("Enter the number of items:");
    scanf("%d",&n);

    Item items[n];

    printf("------Enter the Items(weight,profit)------\n");
    for(int i=0;i<n;i++){
        printf("Enter Item %d:",i+1);
        scanf("%d %d",&items[i].weight,&items[i].profit);
        items[i].ratio = (float)items[i].profit/items[i].weight;
    }

    printf("Enter knapsack capacity:");
    scanf("%d",&w);

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(items[j].ratio<items[j+1].ratio){
                struct Item temp = items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }

    int capacity = w;
    int total_profit = 0;

    for(int i=0;i<n;i++){
        if(capacity>items[i].weight){
            capacity-=items[i].weight;
            total_profit+=items[i].profit;
        }else{ 
        total_profit+= items[i].profit * capacity/items[i].weight;
        }
    }

    printf("\nTotal Profit:%d",total_profit);

    return 0;

}