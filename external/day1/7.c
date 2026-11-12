
#include <stdio.h>
#define INF 999
#define MAX 20

int cost[MAX][MAX];
int visited[MAX] = {0};

int main() {
    int n, min, u, v, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Initialize cost matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cost[i][j] = INF;
        }
    }

    printf("Enter the edges (u, v, w):\n");
    for(int i = 0; i < e; i++) {
        int uu, vv, w;
        scanf("%d %d %d", &uu, &vv, &w);

        cost[uu][vv] = w;
        cost[vv][uu] = w;
    }

    int count = 1;
    visited[0] = 1;
    int min_cost = 0;

    printf("\nMST:\n");

    while(count < n) {
        min = INF;

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                for(int j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(min == INF) {
            printf("MST not possible!\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);

        min_cost += min;
        visited[v] = 1;
        count++;
    }

    printf("\nMinimum Cost: %d\n", min_cost);

    return 0;
}
