#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int n;

// create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
void dfs(int node) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // input edges
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int components = 0;

    // count components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}