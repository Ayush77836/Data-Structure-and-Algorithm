#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// push operation
void push(int x) {
    if (top == MAX - 1) {
        return; // overflow ignored as not required
    }
    stack[++top] = x;
}

// pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

// display operation
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");
}

int main() {
    int n, type, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &value);
            push(value);
        } 
        else if (type == 2) {
            pop();
        } 
        else if (type == 3) {
            display();
        }
    }

    return 0;
}