//1 a. Implement stacks using arrays:

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 3

int stack[SIZE];
int top = -1;

void push();
void pop();
void display();

void main() {
    int choice;
    clrscr();

    while (1) {
        printf("\nSTACK OPERATIONS\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push();
                    getch();
                    clrscr();
                    break;
            case 2: pop();
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

void push() {
    int item;
    if (top == SIZE - 1) {
        printf("Stack is full.\n");
        return;
    }
    printf("Enter the item to push: ");
    scanf("%d", &item);
    stack[++top] = item;
    printf("%d successfully pushed.\n", item);
}

void pop() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%d successfully popped.\n", stack[top--]);
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
