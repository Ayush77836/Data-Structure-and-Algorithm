#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// push
void push(int x) {
    stack[++top] = x;
}

// pop
void pop() {
    if (top != -1) {
        top--;
    }
}

// display
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    // push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    // pop m times
    for (int i = 0; i < m; i++) {
        pop();
    }

    // display remaining stack
    display();

    return 0;
}