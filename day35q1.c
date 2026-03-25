#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;


void push(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}


int pop() {
    struct Node* t = top;
    int val = t->data;
    top = top->next;
    free(t);
    return val;
}


int evaluate(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        if (exp[i] == ' ') {
            i++;
            continue;
        }

        
        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        
        else {
            int b = pop();
            int a = pop();

            if (exp[i] == '+') push(a + b);
            else if (exp[i] == '-') push(a - b);
            else if (exp[i] == '*') push(a * b);
            else if (exp[i] == '/') push(a / b);

            i++;
        }
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);   

    int ans = evaluate(exp);

    printf("Result = %d", ans);

    return 0;
}