#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to push element onto stack
void push(int data) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    stack[++top] = data;
    printf("Pushed %d to stack\n", data);
}

// Function to pop element from stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    int data = stack[top--];
    printf("Popped %d from stack\n", data);
    return data;
}

// Function to peek top element of stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    return stack[top];
}

// Function to display stack contents
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    printf("=== STACK OPERATIONS MENU ===\n");

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("Top element is: %d\n", data);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-5\n");
        }
    }

    return 0;
}
