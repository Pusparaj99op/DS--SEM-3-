#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to add element to queue (enqueue)
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", data);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = data;
    printf("Enqueued %d to queue\n", data);
}

// Function to remove element from queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front++;
    }
    printf("Dequeued %d from queue\n", data);
    return data;
}

// Function to peek front element of queue
int peek() {
    if (isEmpty()) {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    return queue[front];
}

// Function to display queue contents
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents (front to rear): ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    printf("=== QUEUE OPERATIONS MENU ===\n");

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
