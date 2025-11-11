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

NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    return temp;
}

NODE insert_rear(NODE first)
{
    NODE temp, ptr;
    temp = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    printf("%d is successfully inserted\n", temp->data);
    temp->next = temp->prev = NULL;

    if (first == NULL)
    {
        first = temp;
        return first;
    }

    ptr = first;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;
    return first;
}

NODE insert_pos(NODE first)
{
    int pos, count = 1;
    NODE temp, ptr;
    temp = getnode();
    temp->prev = temp->next = NULL;

    if (first == NULL)
    {
        printf("Enter the data: ");
        scanf("%d", &temp->data);
        printf("%d is successfully inserted\n", temp->data);
        first = temp;
        return first;
    }

    printf("Enter the position: ");
    scanf("%d", &pos);

    ptr = first;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    if (pos > count + 1 || pos <= 0)
    {
        printf("Invalid position\n");
        free(temp);
        return first;
    }

    printf("Enter the data: ");
    scanf("%d", &temp->data);
    printf("%d is successfully inserted\n", temp->data);

    if (pos == 1)
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
        return first;
    }

    ptr = first;
    count = 1;
    while (count < pos - 1 && ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    temp->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = temp;
    temp->prev = ptr;
    ptr->next = temp;

    return first;
}

NODE delete_front(NODE first)
{
    NODE ptr;
    if (first == NULL)
    {
        printf("No node to delete\n");
        return NULL;
    }

    ptr = first;
    printf("%d is successfully deleted\n", ptr->data);

    if (first->next == NULL)
    {
        free(ptr);
        return NULL;
    }

    first = first->next;
    first->prev = NULL;
    free(ptr);
    return first;
}

NODE delete_pos(NODE first)
{
    int pos, count = 0;
    NODE ptr;

    if (first == NULL)
    {
        printf("No node\n");
        return first;
    }

    ptr = first;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > count)
    {
        printf("Invalid position\n");
        return first;
    }

    if (pos == 1)
    {
        first = delete_front(first);
        return first;
    }

    ptr = first;
    for (int i = 1; i < pos; i++)
        ptr = ptr->next;

    printf("%d is successfully deleted\n", ptr->data);

    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    free(ptr);
    return first;
}

void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("No nodes\n");
        return;
    }

    printf("List elements: ");
    for (temp = first; temp != NULL; temp = temp->next)
        printf("%d=>", temp->data);
    printf("NULL\n");
}

void main()
{
    NODE first = NULL;
    int option;
    clrscr();

    while (1)
    {
        printf("\nDOUBLY LINKED LIST OPERATIONS\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("1. Insert rear\n2. Insert position\nEnter your choice: ");
            scanf("%d", &option);
            if (option == 1)
                first = insert_rear(first);
            else if (option == 2)
                first = insert_pos(first);
            else
                printf("Invalid choice\n");
            break;

        case 2:
            first = delete_pos(first);
            break;

        case 3:
            display(first);
            break;

        case 4:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }

        getch();
        clrscr();
    }
}
