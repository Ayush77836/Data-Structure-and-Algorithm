#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int n;

// DFS function to detect cycle
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) { // edge exists
            if (!visited[i]) {
                if (dfs(i))
                    return true;
            }
            else if (recStack[i]) {
                // back edge found → cycle
                return true;
            }
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

bool hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}