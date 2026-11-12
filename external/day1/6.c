#include <stdio.h>
#define MAX 50

typedef struct Edge{
    int u,v,w;
}Edge;

int parent[MAX];

int find(int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void union_set(int a,int b){
    parent[find(a)]=find(b);
}

void kruskals(struct Edge edges[],int e,int n){
    
    for(int i=0;i<e;i++){
        for(int j=0;j<e-i-1;j++){
            if(edges[j].w>edges[j+1].w){
                Edge temp = edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }

    int count=0;
    int cost=0;

    printf("\nMST\n");
    for(int i=0;i<e;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;

        if(find(u)!=find(v)){
            printf("%d - %d : %d \n",u,v,w);
            cost+=w;
            union_set(u,v);
            count++;
        }
    }
    printf("Minimum Cost:%d\n",cost);
}




int main(){
    int n=7;
    int e=11;

    Edge edges[11]={
        {0,1,7},
        {0,3,5},
        {1,2,8},
        {1,3,9},
        {1,4,7},
        {2,4,5},
        {3,4,15},
        {3,5,6},
        {4,5,8},
        {4,6,9},
        {5,6,11}
    };

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    kruskals(edges,e,n);

    return 0;
}
