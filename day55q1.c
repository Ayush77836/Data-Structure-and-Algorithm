#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node *Node = (struct Node*)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* Node) {
    q->arr[q->rear++] = Node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue(&q);

        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

void rightView(struct Node* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue(&q);

            if (i == size - 1)
                printf("%d ", temp->data);

            if (temp->left)
                enqueue(&q, temp->left);

            if (temp->right)
                enqueue(&q, temp->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}