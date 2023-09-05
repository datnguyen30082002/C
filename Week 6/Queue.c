#include <stdio.h>
#include <stdlib.h>

// Define a queue struct
struct Queue {
    int front, rear, size, capacity;
    int* array;
};

// Define a function to create queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        return NULL; // Cannot create a new queue
    }

    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    
    if (!queue->array) {
        return NULL; // Cannot create an array for queue
    }

    return queue;
}

// Define a function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Define a function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Define a function to add element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

// Define a function to remove element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return item;
}

int main() {
    struct Queue* queue = createQueue(5);

    // Add element to queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Remove element in queue and print out that element
    printf("\n%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    // Add new element to queue
    printf("\n");
    enqueue(queue, 50);

    // Print the first and last element of the queue
    printf("\nFront item is %d\n", queue->array[queue->front]);
    printf("Rear item is %d\n", queue->array[queue->rear]);

    // Clear memory
    free(queue->array);
    free(queue);

    return 0;
}