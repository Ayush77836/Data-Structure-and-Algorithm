#include <stdio.h>
#define INF 99999

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cost[100][100];
    
    // Initialize matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }

    // Input edges
    int u, v, w;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w; // remove this line if graph is directed
    }

    int source;
    scanf("%d", &source);

    int dist[100], visited[100];

    // Initialize distances
    for(int i = 1; i <= n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    // Dijkstra Algorithm
    for(int count = 1; count < n; count++) {
        int min = INF, next = -1;

        // Find minimum distance vertex
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                next = i;
            }
        }

        if(next == -1) break;

        visited[next] = 1;

        // Update distances
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[next] + cost[next][i] < dist[i]) {
                dist[i] = dist[next] + cost[next][i];
            }
        }
    }

    // Output
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}