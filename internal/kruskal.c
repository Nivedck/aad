#include <stdio.h>

int edges[20][3] , parent[10] ;
int n,e,u,v,w,count=0,cost=0;

int find(int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void unionSet(int a , int b){
    parent[find(a)] = find(b);
}


int main(){
    printf("Enter the number of vertices and edges:");
    scanf("%d%d",&n,&e);

    printf("Enter edges (source , destination , weight):");
    for(int i=0;i<e;i++){
        scanf("%d%d%d",&edges[i][0],&edges[i][1],&edges[i][2]);
    }

    for(int i=0;i<e;i++){
        for(int j=0;j<e-i-1;j++){
            if(edges[j][2] > edges[j+1][2]){
                for(int k=0;k<3;k++){
                    int temp = edges[j][k];
                    edges[j][k]=edges[j+1][k];
                    edges[j+1][k]=temp;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    printf("MST\n");

    for(int i=0;i<e && count<n-1;i++){
        u=edges[i][0];
        v=edges[i][1];
        w=edges[i][2];

        if(find(u)!=find(v)){
            count++;
            cost+=w;
            printf("%d --- %d = %d",u,v,w);
            unionSet(u,v);
        }
    }

    printf("Minimum Cost:%d \n", cost);
}

