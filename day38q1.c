#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Push Front
void push_front(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    dq[front] = x;
}

// Push Back
void push_back(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    dq[rear] = x;
}

// Pop Front
int pop_front() {
    if (isEmpty()) return -1;

    int val = dq[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return val;
}

// Pop Back
int pop_back() {
    if (isEmpty()) return -1;

    int val = dq[rear];

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }

    return val;
}

// Front element
int getFront() {
    if (isEmpty()) return -1;
    return dq[front];
}

// Back element
int getBack() {
    if (isEmpty()) return -1;
    return dq[rear];
}

// Size
int size() {
    if (isEmpty()) return 0;
    if (rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

// Display
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') {        // push_front
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') {   // push_back
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') {   // pop_front
            printf("%d\n", pop_front());
        }
        else if (op[0] == 'p' && op[4] == 'b') {   // pop_back
            printf("%d\n", pop_back());
        }
        else if (op[0] == 'f') {                   // front
            printf("%d\n", getFront());
        }
        else if (op[0] == 'b') {                   // back
            printf("%d\n", getBack());
        }
        else if (op[0] == 's') {                   // size
            printf("%d\n", size());
        }
        else if (op[0] == 'e') {                   // empty
            printf("%d\n", isEmpty());
        }
    }

    // Final state
    display();

    return 0;
}