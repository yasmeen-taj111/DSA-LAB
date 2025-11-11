//1 b.Implement Queues using Arrays: 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;

void insert();
void delete();
void display();

void main() {
    int choice;
    clrscr();

    while (1) {
        printf("\nQUEUE OPERATIONS\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    getch();
                    clrscr();
                    break;
            case 2: delete();
                    getch();
                    clrscr();
                    break;
            case 3: display();
                    getch();
                    clrscr();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void insert() {
    int num;
    if (rear == SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &num);
    if (front == -1)
        front = 0;
    queue[++rear] = num;
    printf("%d inserted successfully.\n", num);
}

void delete() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1; 
    } else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = front; i <= rear; i++)
        printf("%d\t", queue[i]);
    printf("\n");
}
