#include <stdio.h>
#include <stdlib.h>

// Define a Job structure
struct Job {
    int arrival_time;
    int execution_time;
};

// Define a Node structure for the Queue
struct Node {
    struct Job data;
    struct Node* next;
};

// Define a Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new Node
struct Node* newNode(struct Job job) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = job;
    temp->next = NULL;
    return temp;
}

// Function to create an empty Queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a job
void enqueue(struct Queue* queue, struct Job job) {
    struct Node* temp = newNode(job);
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to dequeue a job
struct Job dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    struct Node* temp = queue->front;
    struct Job job = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return job;
}

// Function to execute jobs using FCFS scheduling
void executeJobs(struct Queue* queue) {
    while (queue->front != NULL) {
        struct Job current_job = dequeue(queue);
        printf("Executing job with arrival time %d and execution time %d\n", current_job.arrival_time, current_job.execution_time);
        // Simulate execution time
        // Sleep(current_job.execution_time);
    }
}

int main() {
    // Create an empty queue
    struct Queue* queue = createQueue();
int n;
printf("Enter total no. of jobs:");
scanf("%d",&n);
int arr[n];
printf("\nListout the jobs:\n");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
enqueue(queue, (struct Job){i, arr[i]});
executeJobs(queue);
}
    // Execute jobs using FCFS scheduling

    return 0;
}
