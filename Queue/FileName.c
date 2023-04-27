#include <stdio.h>

#define MAX_QUEUE_SIZE 5

void insert(int* queue, int* rear, int* count);
void delete(int* queue, int* front, int* count);
void display(int* queue, int* front, int* rear, int* count);
int is_full(int* count);
int is_empty(int* count);

int main()
{
    int queue[MAX_QUEUE_SIZE];
    int front = 0, rear = -1;
    int count = 0;
    int choice;

    do {
        printf("===== Menu =====\n");
        printf("\n1. Input data and Enqueue");
        printf("\n2. Dequeue and Print data");
        printf("\n3. Print Queue");
        printf("\n4. Exit");
        printf("\nSelect number: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            insert(queue, &rear, &count);
            break;
        case 2:
            delete(queue, &front, &count);
            break;
        case 3:
            display(queue, &front, &rear, &count);
            break;
        case 4:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice!");
        }
    } while (choice != 4);

    return 0;
}

void insert(int* queue, int* rear, int* count)
{
    if (is_full(count)) {
        printf("\nQueue is full!\n");
        return;
    }

    int data;
    printf("\nEnter data to be inserted: ");
    scanf_s("%d", &data);
    printf("\n");

    *rear = (*rear + 1) % MAX_QUEUE_SIZE;
    queue[*rear] = data;
    (*count)++;
}

void delete(int* queue, int* front, int* count)
{
    if (is_empty(count)) {
        printf("\nQueue is empty!");
        return;
    }

    int data = queue[*front];
    *front = (*front + 1) % MAX_QUEUE_SIZE;
    (*count)--;
    printf("\nDeleted item is %d", data);
}

void display(int* queue, int* front, int* rear, int* count)
{
    if (is_empty(count)) {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nQueue elements: ");
    int i;
    for (i = *front; i != *rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d", queue[*rear]);
}

int is_full(int* count)
{
    return *count == MAX_QUEUE_SIZE;
}

int is_empty(int* count)
{
    return *count == 0;
}
