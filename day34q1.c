#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;


void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}


int pop() {
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
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
    gets(exp);   
    int result = evaluate(exp);

    printf("Result = %d", result);

    return 0;
}