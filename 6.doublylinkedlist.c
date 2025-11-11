//6.Write a program to implement doubly linked list:

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

NODE createNode(int data)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

NODE insert_front(NODE first)
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    NODE newNode = createNode(data);
    if (first == NULL)
    {
        first = newNode;
        printf("%d inserted successfully.\n", data);
        return first;
    }
    newNode->next = first;
    first->prev = newNode;
    first = newNode;
    printf("%d inserted successfully at front.\n", data);
    return first;
}

NODE insert_rear(NODE first)
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    NODE newNode = createNode(data);
    if (first == NULL)
    {
        first = newNode;
        printf("%d inserted successfully.\n", data);
        return first;
    }
    NODE temp = first;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted successfully at rear.\n", data);
    return first;
}

NODE delete_front(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return first;
    }
    NODE temp = first;
    printf("%d deleted successfully from front.\n", temp->data);
    if (first->next == NULL)
    {
        free(temp);
        return NULL;
    }
    first = first->next;
    first->prev = NULL;
    free(temp);
    return first;
}

NODE delete_rear(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return first;
    }
    NODE temp = first;
    if (temp->next == NULL)
    {
        printf("%d deleted successfully from rear.\n", temp->data);
        free(temp);
        return NULL;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("%d deleted successfully from rear.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
    return first;
}

void display(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    NODE temp = first;
    printf("List elements: ");
    while (temp != NULL)
    {
        printf("%d=>", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    NODE first = NULL;
    int choice;
    clrscr();
    while (1)
    {
        printf("\n---- DOUBLY LINKED LIST OPERATIONS ----\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insert_front(first);
            break;
        case 2:
            first = insert_rear(first);
            break;
        case 3:
            first = delete_front(first);
            break;
        case 4:
            first = delete_rear(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
        getch();
        clrscr();
    }
}
