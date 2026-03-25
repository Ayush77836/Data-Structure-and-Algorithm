#include <stdio.h>
#include <stdlib.h>

// structure for a node
struct Node {
    int data;
    struct Node* next;
};

// function to add a node at the end
struct Node* addNode(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // if list is empty
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;

    // go to last node
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// function to delete first occurrence of key
struct Node* removeFirst(struct Node* head, int key) {
    struct Node *current = head, *previous = NULL;

    // if first node itself has the key
    if (current != NULL && current->data == key) {
        head = current->next;
        free(current);
        return head;
    }

    // search for the key
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // if key not found
    if (current == NULL) {
        return head;
    }

    // remove the node
    previous->next = current->next;
    free(current);

    return head;
}

// function to print list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value, key;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = addNode(head, value);
    }

    scanf("%d", &key);

    head = removeFirst(head, key);

    display(head);

    return 0;
}