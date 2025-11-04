# Data Structures Programs (4-7)

## Program 4: Stack Implementation using Arrays

### Aim
To implement a menu-driven program for Stack data structure using arrays to demonstrate LIFO (Last In First Out) operations including push, pop, peek, and display functionalities with proper error handling for overflow and underflow conditions.

### Theory
A Stack is a fundamental linear data structure that operates on the Last In First Out (LIFO) principle. It can be visualized as a collection of elements where insertion and deletion operations are performed at one end only, called the "top" of the stack.

**Key Characteristics:**
- **LIFO Principle**: The last element added is the first one to be removed
- **Single Access Point**: All operations occur at the top of the stack
- **Dynamic Size**: Can grow and shrink during runtime (within array limits)

**Applications:**
- Function call management in programming languages
- Expression evaluation and syntax parsing
- Undo operations in text editors
- Browser back button functionality
- Memory management in recursive algorithms

**Basic Operations:**
1. **Push**: Insert an element at the top of the stack
2. **Pop**: Remove and return the top element from the stack
3. **Peek/Top**: Return the top element without removing it
4. **isEmpty**: Check if the stack is empty
5. **isFull**: Check if the stack is full (for array implementation)

### Algorithm

**Main Algorithm:**
```
START
1. Initialize stack array of size MAX
2. Set top = -1 (indicates empty stack)
3. Display menu with options
4. Read user choice
5. Based on choice, call appropriate function
6. Repeat until user chooses to exit
END
```

**Push Operation:**
```
PUSH(data)
START
1. IF top == MAX-1 THEN
     Print "Stack Overflow"
     RETURN
2. ELSE
     top = top + 1
     stack[top] = data
     Print "Element pushed successfully"
END
```

**Pop Operation:**
```
POP()
START
1. IF top == -1 THEN
     Print "Stack Underflow"
     RETURN -1
2. ELSE
     data = stack[top]
     top = top - 1
     Print "Element popped successfully"
     RETURN data
END
```

**Peek Operation:**
```
PEEK()
START
1. IF top == -1 THEN
     Print "Stack is empty"
     RETURN -1
2. ELSE
     RETURN stack[top]
END
```

**Display Operation:**
```
DISPLAY()
START
1. IF top == -1 THEN
     Print "Stack is empty"
2. ELSE
     FOR i = top TO 0 DO
       Print stack[i]
     END FOR
END
```

### Code
```c
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
```

### Output
```
=== STACK OPERATIONS MENU ===

1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to push: 10
Pushed 10 to stack

1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to push: 20
Pushed 20 to stack

1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to push: 30
Pushed 30 to stack

1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack contents (top to bottom): 30 20 10

1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 3
Top element is: 30

1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 30 from stack

1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack contents (top to bottom): 20 10

1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 5
Exiting program. Goodbye!
```

### Result
The Stack implementation using arrays has been successfully developed and tested. The program demonstrates:

1. **Successful Implementation**: All four basic stack operations (push, pop, peek, display) work correctly
2. **LIFO Principle**: Elements are removed in reverse order of insertion, confirming Last In First Out behavior
3. **Error Handling**: Proper handling of stack overflow and underflow conditions
4. **Menu-Driven Interface**: User-friendly interface allowing multiple operations in a single execution
5. **Memory Efficiency**: Uses array-based implementation for constant time operations O(1)
6. **Boundary Conditions**: Correctly handles empty stack and full stack scenarios

**Time Complexity Analysis:**
- Push Operation: O(1)
- Pop Operation: O(1)
- Peek Operation: O(1)
- Display Operation: O(n), where n is the number of elements

**Space Complexity**: O(MAX) where MAX is the maximum size of the stack array.

The program successfully validates the theoretical concepts of stack data structure through practical implementation.

---

## Program 5: Queue Implementation using Arrays

### Aim
To implement a menu-driven program for Queue data structure using arrays to demonstrate FIFO (First In First Out) operations including enqueue, dequeue, peek, and display functionalities with proper handling of queue overflow and underflow conditions.

### Theory
A Queue is a fundamental linear data structure that operates on the First In First Out (FIFO) principle. It can be visualized as a collection of elements where insertion occurs at one end (rear) and deletion occurs at the other end (front).

**Key Characteristics:**
- **FIFO Principle**: The first element added is the first one to be removed
- **Two Access Points**: Insertion at rear, deletion at front
- **Sequential Processing**: Elements are processed in the order they arrive

**Applications:**
- CPU scheduling in operating systems
- Handling requests in web servers
- Breadth-First Search (BFS) in graphs
- Print queue management
- Buffer for data streams
- Call center systems

**Basic Operations:**
1. **Enqueue**: Insert an element at the rear of the queue
2. **Dequeue**: Remove and return the front element from the queue
3. **Peek/Front**: Return the front element without removing it
4. **isEmpty**: Check if the queue is empty
5. **isFull**: Check if the queue is full (for array implementation)

### Algorithm

**Main Algorithm:**
```
START
1. Initialize queue array of size MAX
2. Set front = -1, rear = -1 (indicates empty queue)
3. Display menu with options
4. Read user choice
5. Based on choice, call appropriate function
6. Repeat until user chooses to exit
END
```

**Enqueue Operation:**
```
ENQUEUE(data)
START
1. IF rear == MAX-1 THEN
     Print "Queue Overflow"
     RETURN
2. ELSE
     IF front == -1 THEN
       front = 0
     END IF
     rear = rear + 1
     queue[rear] = data
     Print "Element enqueued successfully"
END
```

**Dequeue Operation:**
```
DEQUEUE()
START
1. IF front == -1 THEN
     Print "Queue Underflow"
     RETURN -1
2. ELSE
     data = queue[front]
     IF front == rear THEN
       front = rear = -1
     ELSE
       front = front + 1
     END IF
     Print "Element dequeued successfully"
     RETURN data
END
```

**Peek Operation:**
```
PEEK()
START
1. IF front == -1 THEN
     Print "Queue is empty"
     RETURN -1
2. ELSE
     RETURN queue[front]
END
```

**Display Operation:**
```
DISPLAY()
START
1. IF front == -1 THEN
     Print "Queue is empty"
2. ELSE
     FOR i = front TO rear DO
       Print queue[i]
     END FOR
END
```

### Code
```c
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
```

### Output
```
=== QUEUE OPERATIONS MENU ===

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to enqueue: 10
Enqueued 10 to queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to enqueue: 20
Enqueued 20 to queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to enqueue: 30
Enqueued 30 to queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue contents (front to rear): 10 20 30

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 3
Front element is: 10

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Dequeued 10 from queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue contents (front to rear): 20 30

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 5
Exiting program. Goodbye!
```

### Result
The Queue implementation using arrays has been successfully developed and tested. The program demonstrates:

1. **Successful Implementation**: All four basic queue operations (enqueue, dequeue, peek, display) work correctly
2. **FIFO Principle**: Elements are removed in the same order they were inserted, confirming First In First Out behavior
3. **Error Handling**: Proper handling of queue overflow and underflow conditions
4. **Menu-Driven Interface**: User-friendly interface allowing multiple operations in a single execution
5. **Memory Management**: Efficient use of array indices for front and rear pointers
6. **Boundary Conditions**: Correctly handles empty queue and full queue scenarios

**Time Complexity Analysis:**
- Enqueue Operation: O(1)
- Dequeue Operation: O(1)
- Peek Operation: O(1)
- Display Operation: O(n), where n is the number of elements

**Space Complexity**: O(MAX) where MAX is the maximum size of the queue array.

**Limitation**: This simple queue implementation wastes space as the front part of the array cannot be reused after dequeue operations. This limitation is addressed in circular queue implementation.

The program successfully validates the theoretical concepts of queue data structure through practical implementation.

---

## Program 6: Circular Queue Implementation using Arrays

### Aim
To implement a circular queue data structure using arrays with enqueue, dequeue, peek, and display operations to overcome the space wastage problem of linear queue implementation and demonstrate efficient memory utilization through circular indexing.

### Theory
A Circular Queue is an advanced version of linear queue that connects the end of the queue back to the beginning, forming a circular structure. This design overcomes the major limitation of linear queues where memory space gets wasted after dequeue operations.

**Key Characteristics:**
- **Circular Structure**: Last position connects back to the first position
- **Space Efficiency**: Reuses memory locations that become available after dequeue
- **FIFO Principle**: Maintains First In First Out ordering
- **Fixed Size**: Predetermined maximum capacity

**Advantages over Linear Queue:**
- **Memory Reuse**: Previously occupied positions can be used again
- **No Memory Wastage**: Full utilization of allocated array space
- **Constant Time Operations**: All operations remain O(1)
- **Better Performance**: No need for shifting elements

**Applications:**
- **CPU Scheduling**: Round-robin scheduling algorithms
- **Buffer Management**: Circular buffers in streaming applications
- **Traffic Light Systems**: Cyclic traffic control
- **Memory Management**: Ring buffers in operating systems
- **Producer-Consumer Problems**: Synchronized data sharing

**Basic Operations:**
1. **Enqueue**: Insert element at rear position using modular arithmetic
2. **Dequeue**: Remove element from front position using modular arithmetic
3. **Peek**: View front element without removing it
4. **isFull**: Check if queue is full using circular condition
5. **isEmpty**: Check if queue is empty

### Algorithm

**Main Algorithm:**
```
START
1. Initialize circular queue array of size MAX
2. Set front = -1, rear = -1 (indicates empty queue)
3. Display menu with options
4. Read user choice
5. Based on choice, call appropriate function
6. Repeat until user chooses to exit
END
```

**Enqueue Operation:**
```
ENQUEUE(data)
START
1. IF (rear + 1) % MAX == front THEN
     Print "Circular Queue Overflow"
     RETURN
2. ELSE
     IF front == -1 THEN
       front = 0
       rear = 0
     ELSE
       rear = (rear + 1) % MAX
     END IF
     cqueue[rear] = data
     Print "Element enqueued successfully"
END
```

**Dequeue Operation:**
```
DEQUEUE()
START
1. IF front == -1 THEN
     Print "Circular Queue Underflow"
     RETURN -1
2. ELSE
     data = cqueue[front]
     IF front == rear THEN
       front = rear = -1
     ELSE
       front = (front + 1) % MAX
     END IF
     Print "Element dequeued successfully"
     RETURN data
END
```

**isFull Check:**
```
ISFULL()
START
  RETURN (rear + 1) % MAX == front
END
```

**Display Operation:**
```
DISPLAY()
START
1. IF front == -1 THEN
     Print "Circular Queue is empty"
2. ELSE
     i = front
     DO
       Print cqueue[i]
       i = (i + 1) % MAX
     WHILE i != (rear + 1) % MAX
END
```

### Code
```c
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
```

### Output
```
=== CIRCULAR QUEUE OPERATIONS MENU ===

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to enqueue: 10
Enqueued 10 to circular queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to enqueue: 20
Enqueued 20 to circular queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to enqueue: 30
Enqueued 30 to circular queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Circular Queue contents (front to rear): 10 20 30

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Dequeued 10 from circular queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter element to enqueue: 40
Enqueued 40 to circular queue

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Circular Queue contents (front to rear): 20 30 40

1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 5
Exiting program. Goodbye!
```

### Result
The Circular Queue implementation using arrays has been successfully developed and tested. The program demonstrates:

1. **Successful Implementation**: All four basic circular queue operations work correctly with proper circular indexing
2. **Space Efficiency**: Demonstrates memory reuse capability by allowing enqueue after dequeue operations
3. **FIFO Principle**: Maintains First In First Out ordering while utilizing circular structure
4. **Modular Arithmetic**: Successfully implements circular indexing using modulo operator (% MAX)
5. **Overflow Prevention**: Correctly identifies when queue is full using circular condition
6. **Memory Optimization**: Eliminates space wastage problem present in linear queue implementation

**Time Complexity Analysis:**
- Enqueue Operation: O(1)
- Dequeue Operation: O(1)
- Peek Operation: O(1)
- Display Operation: O(n), where n is the number of elements
- isFull/isEmpty Check: O(1)

**Space Complexity**: O(MAX) where MAX is the maximum size of the circular queue array.

**Key Advantages Achieved:**
- **100% Space Utilization**: No memory wastage unlike linear queue
- **Constant Time Operations**: All operations maintain O(1) complexity
- **Circular Reusability**: Previously dequeued positions can be reused for new elements

The program successfully demonstrates the superiority of circular queue over linear queue implementation in terms of memory efficiency and space utilization.

---

## Program 7: Single Linked List Implementation

### Aim
To implement a single linked list data structure with dynamic memory allocation to perform insertion, deletion, traversal operations, and additionally calculate the total number of nodes and sum of all elements in the list to demonstrate the flexibility and efficiency of linked data structures.

### Theory
A Single Linked List is a dynamic linear data structure where elements (nodes) are stored in sequence, but unlike arrays, they are not stored in contiguous memory locations. Each node contains two parts: data and a pointer to the next node.

**Key Characteristics:**
- **Dynamic Memory**: Nodes are allocated at runtime using malloc()
- **Sequential Access**: Elements must be accessed sequentially from head
- **Non-Contiguous Storage**: Nodes can be stored anywhere in memory
- **Pointer-Based**: Uses pointers to establish connections between nodes

**Node Structure:**
```
[Data | Next Pointer] -> [Data | Next Pointer] -> ... -> NULL
```

**Advantages:**
- **Dynamic Size**: Can grow or shrink during runtime
- **Memory Efficiency**: Allocates memory only when needed
- **Insertion/Deletion**: Easy insertion and deletion at any position
- **No Memory Waste**: No pre-allocation of unused memory

**Disadvantages:**
- **No Random Access**: Cannot directly access elements by index
- **Extra Memory**: Requires additional memory for storing pointers
- **Cache Performance**: Poor cache locality due to non-contiguous storage

**Applications:**
- **Dynamic Arrays**: When size is not known beforehand
- **Implementation of Stacks and Queues**: Using linked representation
- **Polynomial Arithmetic**: Representing sparse polynomials
- **Music Playlist**: Next song functionality
- **Browser History**: Forward navigation
- **Undo Operations**: Chain of previous states

### Algorithm

**Main Algorithm:**
```
START
1. Initialize head pointer to NULL
2. Display menu with options
3. Read user choice
4. Based on choice, call appropriate function
5. Repeat until user chooses to exit
6. Free all allocated memory before exit
END
```

**Insert at Beginning:**
```
INSERT_AT_BEGINNING(data)
START
1. Create new node using malloc()
2. Set newNode->data = data
3. Set newNode->next = head
4. Set head = newNode
5. Print success message
END
```

**Insert at End:**
```
INSERT_AT_END(data)
START
1. Create new node using malloc()
2. Set newNode->data = data
3. Set newNode->next = NULL
4. IF head == NULL THEN
     head = newNode
5. ELSE
     temp = head
     WHILE temp->next != NULL DO
       temp = temp->next
     END WHILE
     temp->next = newNode
6. Print success message
END
```

**Delete Node:**
```
DELETE_NODE(data)
START
1. IF head == NULL THEN
     Print "List is empty"
     RETURN
2. IF head->data == data THEN
     temp = head
     head = head->next
     free(temp)
     RETURN
3. temp = head
4. WHILE temp->next != NULL AND temp->next->data != data DO
     temp = temp->next
   END WHILE
5. IF temp->next == NULL THEN
     Print "Element not found"
   ELSE
     nodeToDelete = temp->next
     temp->next = nodeToDelete->next
     free(nodeToDelete)
END
```

**Count Nodes:**
```
COUNT_NODES()
START
1. count = 0
2. temp = head
3. WHILE temp != NULL DO
     count = count + 1
     temp = temp->next
   END WHILE
4. RETURN count
END
```

**Sum of Elements:**
```
SUM_OF_ELEMENTS()
START
1. sum = 0
2. temp = head
3. WHILE temp != NULL DO
     sum = sum + temp->data
     temp = temp->next
   END WHILE
4. RETURN sum
END
```

**Display List:**
```
DISPLAY()
START
1. IF head == NULL THEN
     Print "List is empty"
2. ELSE
     temp = head
     WHILE temp != NULL DO
       Print temp->data + "->"
       temp = temp->next
     END WHILE
     Print "NULL"
END
```

### Code
```c
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
```

### Output
```
=== SINGLE LINKED LIST OPERATIONS MENU ===

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 2
Enter element to insert at end: 10
Inserted 10 at the end

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 2
Enter element to insert at end: 20
Inserted 20 at the end

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 1
Enter element to insert at beginning: 5
Inserted 5 at the beginning

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 4
Linked List: 5 -> 10 -> 20 -> NULL

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 5
Number of nodes in the list: 3

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 6
Sum of all elements in the list: 35

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 3
Enter element to delete: 10
Deleted 10 from the list

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 4
Linked List: 5 -> 20 -> NULL

1. Insert at beginning
2. Insert at end
3. Delete node
4. Display list
5. Count nodes
6. Sum of elements
7. Exit
Enter your choice: 7
Exiting program. Goodbye!
```

### Result
The Single Linked List implementation has been successfully developed and tested. The program demonstrates:

1. **Dynamic Memory Management**: Successfully allocates and deallocates memory using malloc() and free()
2. **Complete Functionality**: All basic operations (insertion, deletion, display) work correctly
3. **Special Features**: Successfully implements node counting and sum calculation as required
4. **Memory Safety**: Proper handling of NULL pointers and memory deallocation
5. **Flexible Insertion**: Supports insertion at both beginning and end of the list
6. **Search and Delete**: Efficiently finds and removes specific elements from the list
7. **Statistical Functions**: Accurately counts nodes and calculates sum of all elements

**Time Complexity Analysis:**
- Insert at Beginning: O(1)
- Insert at End: O(n), where n is the number of nodes
- Delete Node: O(n) in worst case
- Display: O(n)
- Count Nodes: O(n)
- Sum of Elements: O(n)

**Space Complexity**: O(n) where n is the number of nodes, plus O(1) for each node's pointer overhead.

**Key Achievements:**
- **Dynamic Size Management**: List can grow and shrink as needed
- **Efficient Memory Usage**: No pre-allocation of unused memory
- **Robust Error Handling**: Proper handling of empty list and element not found scenarios
- **Clean Memory Management**: All allocated memory is properly freed on exit

**Additional Features Implemented:**
- **Node Counter**: Real-time count of total nodes in the list
- **Sum Calculator**: Computes sum of all data elements
- **Memory Cleanup**: Prevents memory leaks by freeing all nodes

The program successfully demonstrates the power and flexibility of linked data structures compared to static array implementations, while also providing the specific functionality of counting nodes and calculating element sum as requested.

---

## Overall Conclusion

All four fundamental data structure programs have been successfully implemented and thoroughly tested, demonstrating both theoretical understanding and practical implementation skills:

### Summary of Implementations:

1. **Stack (DS_Program_4.c)** - LIFO operations using array-based implementation
   - **Operations**: Push, Pop, Peek, Display
   - **Principle**: Last In First Out
   - **Complexity**: All operations O(1) except display O(n)
   - **Applications**: Function calls, expression evaluation, undo operations

2. **Queue (DS_Program_5.c)** - FIFO operations using array-based implementation
   - **Operations**: Enqueue, Dequeue, Peek, Display
   - **Principle**: First In First Out
   - **Complexity**: All operations O(1) except display O(n)
   - **Applications**: CPU scheduling, print queues, breadth-first search

3. **Circular Queue (DS_Program_6.c)** - Efficient space utilization with circular array
   - **Operations**: Enqueue, Dequeue, Peek, Display
   - **Advantage**: Eliminates space wastage of linear queue
   - **Technique**: Modular arithmetic for circular indexing
   - **Applications**: Ring buffers, round-robin scheduling

4. **Single Linked List (DS_Program_7.c)** - Dynamic memory allocation with special features
   - **Operations**: Insert, Delete, Display, Count Nodes, Sum Elements
   - **Advantage**: Dynamic size, efficient memory usage
   - **Features**: Node counting and sum calculation as requested
   - **Applications**: Dynamic arrays, stack/queue implementation

### Key Learning Outcomes:

1. **Data Structure Concepts**: Understanding of fundamental linear data structures and their characteristics
2. **Algorithm Implementation**: Successful translation of theoretical algorithms into working C code
3. **Memory Management**: Proper handling of both static arrays and dynamic memory allocation
4. **Error Handling**: Comprehensive overflow, underflow, and boundary condition management
5. **Menu-Driven Design**: User-friendly interfaces for interactive program testing
6. **Time/Space Analysis**: Understanding of computational complexity for each operation

### Technical Achievements:

- **Robust Implementation**: All programs handle edge cases and error conditions properly
- **Modular Design**: Well-structured code with separate functions for each operation
- **Memory Safety**: Proper memory management with no memory leaks in linked list implementation
- **Performance Optimization**: Efficient algorithms with optimal time complexity
- **Documentation**: Comprehensive README with theory, algorithms, and analysis

### Practical Applications Demonstrated:

The implemented data structures form the foundation for numerous real-world applications including operating system design, compiler construction, database management, networking protocols, and algorithm development. Each structure showcases different trade-offs between memory usage, access patterns, and operational efficiency.

This comprehensive implementation successfully bridges the gap between theoretical computer science concepts and practical programming skills, providing a solid foundation for advanced data structure and algorithm study.

---

## Program 8: Complete Single Linked List Operations

### Aim
To implement a comprehensive single linked list program with creation, multiple insertion operations (at beginning, end, and specific position), multiple deletion operations (from beginning, end, and specific position), and traversal functionality.

### Theory
A Single Linked List is a dynamic data structure where each node contains data and a pointer to the next node. This program demonstrates complete linked list operations including positional insertions and deletions.

**Key Operations:**
- **Creation**: Initialize empty list with head = NULL
- **Insertion**: Add nodes at beginning, end, or any position
- **Deletion**: Remove nodes from beginning, end, or any position
- **Traversal**: Visit and display all nodes sequentially

**Time Complexity:**
- Insert/Delete at Beginning: O(1)
- Insert/Delete at End: O(n)
- Insert/Delete at Position: O(n)
- Traversal: O(n)

### Algorithm

**Insert at Position:**
```
INSERT_AT_POS(data, pos)
1. Create new node
2. IF pos == 1, insert at beginning
3. ELSE traverse to (pos-1)th node
4. Link new node between nodes
END
```

**Delete from Position:**
```
DELETE_FROM_POS(pos)
1. IF pos == 1, delete from beginning
2. ELSE traverse to (pos-1)th node
3. Update links and free node
END
```

### Code
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning\n", data);
}

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
    printf("Inserted %d at end\n", data);
}

void insertAtPos(int data, int pos) {
    if (pos == 1) {
        insertAtBeg(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, pos);
}

void deleteFromBeg() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteFromPos(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        deleteFromBeg();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted %d from position %d\n", nodeToDelete->data, pos);
    free(nodeToDelete);
}

void traversal() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, pos;
    
    printf("=== LINKED LIST OPERATIONS ===\n");
    
    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n");
        printf("7. Traversal\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeg(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPos(data, pos);
                break;
            case 4:
                deleteFromBeg();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPos(pos);
                break;
            case 7:
                traversal();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
```

### Output
```
=== LINKED LIST OPERATIONS ===

1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Traversal
8. Exit
Enter choice: 2
Enter data: 10
Inserted 10 at end

Enter choice: 2
Enter data: 20
Inserted 20 at end

Enter choice: 1
Enter data: 5
Inserted 5 at beginning

Enter choice: 3
Enter data and position: 15 3
Inserted 15 at position 3

Enter choice: 7
List: 5 -> 10 -> 15 -> 20 -> NULL

Enter choice: 4
Deleted 5 from beginning

Enter choice: 6
Enter position: 2
Deleted 15 from position 2

Enter choice: 7
List: 10 -> 20 -> NULL

Enter choice: 8
Exiting...
```

### Result
The program successfully demonstrates complete linked list operations including creation, insertion at three positions (beginning, end, specific position), deletion from three positions, and traversal. All operations work correctly with proper error handling.

---

## Program 9: Binary Search Tree Implementation

### Aim
To implement a Binary Search Tree (BST) with insertion operation and display its inorder, preorder, and postorder traversals.

### Theory
A Binary Search Tree is a hierarchical data structure where each node has at most two children (left and right). For every node, all values in left subtree are smaller and all values in right subtree are greater.

**Properties:**
- Left subtree < Root < Right subtree
- Inorder gives sorted sequence
- Efficient searching: O(log n) average case

**Traversal Types:**
- **Inorder (LNR)**: Left → Node → Right (gives sorted order)
- **Preorder (NLR)**: Node → Left → Right (used for copying tree)
- **Postorder (LRN)**: Left → Right → Node (used for deleting tree)

### Algorithm

**Insert Node:**
```
INSERT(root, data)
1. IF root == NULL, create new node
2. IF data < root->data, insert in left subtree
3. ELSE insert in right subtree
4. RETURN root
END
```

**Inorder Traversal:**
```
INORDER(root)
1. IF root != NULL
2.   INORDER(root->left)
3.   Print root->data
4.   INORDER(root->right)
END
```

### Code
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    printf("=== BINARY SEARCH TREE ===\n");
    
    while (1) {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d\n", data);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
```

### Output
```
=== BINARY SEARCH TREE ===

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter choice: 1
Enter data: 50
Inserted 50

Enter choice: 1
Enter data: 30
Inserted 30

Enter choice: 1
Enter data: 70
Inserted 70

Enter choice: 1
Enter data: 20
Inserted 20

Enter choice: 1
Enter data: 40
Inserted 40

Enter choice: 2
Inorder: 20 30 40 50 70

Enter choice: 3
Preorder: 50 30 20 40 70

Enter choice: 4
Postorder: 20 40 30 70 50

Enter choice: 5
Exiting...
```

### Result
The BST implementation successfully creates a binary search tree and performs all three traversals correctly. Inorder traversal produces sorted sequence (20, 30, 40, 50, 70), confirming proper BST structure.

---

## Program 10: Graph Traversal - DFS and BFS

### Aim
To implement Depth First Search (DFS) and Breadth First Search (BFS) traversal techniques on a graph using adjacency matrix representation.

### Theory
Graph traversal algorithms visit all vertices of a graph systematically.

**Depth First Search (DFS):**
- Uses stack (or recursion)
- Explores as deep as possible before backtracking
- Applications: Cycle detection, topological sorting, maze solving

**Breadth First Search (BFS):**
- Uses queue
- Explores level by level
- Applications: Shortest path, web crawling, social networks

**Time Complexity:** O(V + E) where V = vertices, E = edges  
**Space Complexity:** O(V) for visited array and stack/queue

### Algorithm

**DFS Algorithm:**
```
DFS(vertex, visited)
1. Mark vertex as visited
2. Print vertex
3. FOR each adjacent vertex
4.   IF not visited, call DFS(adjacent)
END
```

**BFS Algorithm:**
```
BFS(start)
1. Create queue and enqueue start
2. Mark start as visited
3. WHILE queue not empty
4.   Dequeue vertex and print
5.   FOR each adjacent vertex
6.     IF not visited, mark and enqueue
END
```

### Code
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX], n;

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("%d ", start);
    visited[start] = 1;
    queue[rear++] = start;
    
    while (front < rear) {
        int vertex = queue[front++];
        
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int edges, u, v, choice, start;
    
    printf("=== GRAPH TRAVERSAL (DFS & BFS) ===\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }
    
    while (1) {
        printf("\n1. DFS Traversal\n2. BFS Traversal\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                for (int i = 0; i < n; i++) {
                    visited[i] = 0;
                }
                printf("DFS Traversal: ");
                DFS(start);
                printf("\n");
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                printf("BFS Traversal: ");
                BFS(start);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
```

### Output
```
=== GRAPH TRAVERSAL (DFS & BFS) ===
Enter number of vertices: 5
Enter number of edges: 6
Enter edges (u v):
0 1
0 2
1 3
1 4
2 4
3 4

1. DFS Traversal
2. BFS Traversal
3. Exit
Enter choice: 1
Enter starting vertex: 0
DFS Traversal: 0 1 3 4 2

1. DFS Traversal
2. BFS Traversal
3. Exit
Enter choice: 2
Enter starting vertex: 0
BFS Traversal: 0 1 2 3 4

1. DFS Traversal
2. BFS Traversal
3. Exit
Enter choice: 3
Exiting...
```

### Result
The program successfully implements both DFS and BFS graph traversal algorithms. DFS explores deeply (0→1→3→4→2) while BFS explores level-wise (0→1→2→3→4). Both algorithms correctly traverse all reachable vertices from the starting vertex.

---

## Overall Summary (Programs 8-10)

These three programs complete the essential data structures curriculum:

1. **Program 8 (Complete Linked List)**: Demonstrates comprehensive linked list operations with positional insertions and deletions, providing full control over list manipulation.

2. **Program 9 (Binary Search Tree)**: Implements hierarchical data structure with efficient searching and demonstrates three fundamental tree traversal techniques.

3. **Program 10 (Graph Traversal)**: Covers both major graph traversal algorithms (DFS and BFS), essential for graph-based problem solving.

**Key Concepts Covered:**
- Dynamic memory allocation and pointer manipulation
- Recursive algorithms (DFS, tree traversals)
- Queue-based algorithms (BFS)
- Tree and graph data structures
- Time and space complexity analysis

These implementations provide a solid foundation for advanced algorithms and data structure applications in computer science.
