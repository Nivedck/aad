#include <stdio.h>
#define MAX_V 20
#define MAX_E 100

int parent[MAX_V];

typedef struct Edge{
    int u,v,w;
}Edge;

int find(int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void unionSet(int a,int b){
    parent[find(a)]=find(b);
}

int main(){
    int n,e,count=0,cost=0;
    Edge edges[MAX_E];

    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("Enter the number of edges:");
    scanf("%d",&e);

    
    for(int i=0;i<e;i++){
        printf("Enter edge %d:",i+1);
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    }

    for(int i=0;i<n;i++){
    parent[i]=i;
    }

    for(int i=0;i<e-1;i++){
        for(int j=0;j<e-i-1;j++){
            if(edges[j].w>edges[j+1].w){
                Edge temp = edges[j];
                edges[j]=edges[j+1];;
                edges[j+1] = temp;
            }
        }
    }

    printf("\nSorted Edges:\n");

for(int i=0;i<e;i++){
    printf("%d - %d : %d\n",
           edges[i].u, edges[i].v, edges[i].w);
}

    printf("Minimum Spanning Tree \n");
        for(int i=0;i<e && count<n-1;i++){
            int u=edges[i].u;
            int v=edges[i].v;
            int w=edges[i].w;

            if(find(u)!=find(v)){
                printf("%d - %d : %d \n",u,v,w);
                unionSet(u,v);
                cost+=w;
                count++;
                
            }
        }

        printf("Total Cost:%d \n",cost);
        
    

    return 0;

}
