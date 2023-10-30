#include <stdio.h>

#define size 10
int arr[size], front = -1, rear = -1;

int isempty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if ((rear + 1) % size == front)
        return 1;
    else
        return 0;
}

void insertQ(int item) {
    if (isfull())
        printf("Queue is full!\n");
    else if (isempty())
        front = rear = 0;
    else
        rear = (rear + 1) % size;

    arr[rear] = item;
}

void delete() {
    if (isempty())
        printf("Queue is Empty!\n");
    else if (front == rear) {
        printf("The deleted element is: %d\n", arr[front]);
        rear = front = -1;
    } else {
        printf("The deleted element is: %d\n", arr[front]);
        front = (front + 1) % size;
    }
}

void display(int front, int rear) {
    printf("\nThe Current Queue is:\n");
    if (front > rear) {
        for (int i = front; i < size; i++) {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int ch;
    do {
        printf("\nEnter your choice:\n1. Insert into Queue\n2. Delete from Queue\n3. Display Queue\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (isfull())
                    printf("Queue is full.\n");
                else {
                    printf("Enter the element to push: ");
                    int key;
                    scanf("%d", &key);
                    insertQ(key);
                    printf("Element pushed successfully.\n");
                }
                break;
            case 2:
                if (isempty())
                    printf("The Queue is Empty.\n");
                else
                    delete();
                break;
            case 3:
                display(front, rear);
                break;
            case 4:
                printf("Exited successfully...\n");
                return 0;
            default:
                printf("Wrong Choice!\n");
        }
    } while (1);

    return 0;
}
