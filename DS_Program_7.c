#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert element at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert element at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end\n", data);
}

// Function to delete a node with given value
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty! Cannot delete %d\n", data);
        return;
    }

    // If head node contains the data to be deleted
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted %d from the list\n", data);
        return;
    }

    // Search for the node to be deleted
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element %d not found in the list\n", data);
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Deleted %d from the list\n", data);
}

// Function to count the number of nodes
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to calculate sum of all elements
int sumOfElements() {
    int sum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free all nodes
void freeList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, data;

    printf("=== SINGLE LINKED LIST OPERATIONS MENU ===\n");

    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Display list\n");
        printf("5. Count nodes\n");
        printf("6. Sum of elements\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Number of nodes in the list: %d\n", countNodes());
                break;
            case 6:
                printf("Sum of all elements in the list: %d\n", sumOfElements());
                break;
            case 7:
                freeList();
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-7\n");
        }
    }

    return 0;
}
