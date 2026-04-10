#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];


int queue[MAX];
int front = -1, rear = -1;


struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}


void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}


void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}


int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}


void BFS(int s) {
    enqueue(s);
    visited[s] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); 
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(s);

    return 0;
}