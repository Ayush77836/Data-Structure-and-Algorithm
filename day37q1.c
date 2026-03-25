#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element (sorted order)
void insert(int x) {
    if (size == MAX) return;

    int i = size - 1;

    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

// Delete (remove smallest element)
int deleteMin() {
    if (size == 0) return -1;

    int val = pq[0];

    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
    return val;
}

// Peek
int peek() {
    if (size == 0) return -1;
    return pq[0];
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        } 
        else if (op[0] == 'd') {
            printf("%d\n", deleteMin());
        } 
        else if (op[0] == 'p') {
            printf("%d\n", peek());
        }
    }

    return 0;
}