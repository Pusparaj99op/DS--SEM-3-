#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int cqueue[MAX];
int front = -1;
int rear = -1;
// Function to check if circular queue is empty
int isEmpty() {
    return front == -1;
}
// Function to check if circular queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}
// Function to add element to circular queue (enqueue)
void enqueue(int data) {
    if (isFull()) {
        printf("Circular Queue Overflow! Cannot enqueue %d\n", data);
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    cqueue[rear] = data;
    printf("Enqueued %d to circular queue\n", data);
}
// Function to remove element from circular queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    int data = cqueue[front];
    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Dequeued %d from circular queue\n", data);
    return data;
}
// Function to peek front element of circular queue
int peek() {
    if (isEmpty()) {
        printf("Circular Queue is empty! No front element\n");
        return -1;
    }
    return cqueue[front];
}
// Function to display circular queue contents
void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Circular Queue contents (front to rear): ");
    int i = front;
    do {
        printf("%d ", cqueue[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    printf("\n");
}
int main() {
    int choice, data;
    printf("=== CIRCULAR QUEUE OPERATIONS MENU ===\n");
    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("Front element is: %d\n", data);
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