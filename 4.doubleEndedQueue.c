//4.Implement double ended queue using singly linked list:

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    return temp;
}

NODE insert_front(NODE first)
{
    NODE temp = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = first;
    first = temp;
    printf("%d is successfully inserted at front\n", temp->data);
    return first;
}

NODE insert_rear(NODE first)
{
    NODE temp = getnode(), ptr;
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (first == NULL)
    {
        first = temp;
        printf("%d is successfully inserted at rear\n", temp->data);
        return first;
    }

    ptr = first;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    printf("%d is successfully inserted at rear\n", temp->data);
    return first;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("No nodes present\n");
        return first;
    }

    temp = first;
    first = first->next;
    printf("%d is successfully deleted from front\n", temp->data);
    free(temp);
    return first;
}

NODE delete_rear(NODE first)
{
    NODE ptr, prev;
    if (first == NULL)
    {
        printf("No nodes present\n");
        return first;
    }

    if (first->next == NULL)
    {
        printf("%d is successfully deleted from rear\n", first->data);
        free(first);
        return NULL;
    }

    ptr = first;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    printf("%d is successfully deleted from rear\n", ptr->data);
    prev->next = NULL;
    free(ptr);
    return first;
}

void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("No nodes present\n");
        return;
    }

    printf("Queue elements: ");
    for (temp = first; temp != NULL; temp = temp->next)
        printf("%d=>", temp->data);
    printf("NULL\n");
}

void main()
{
    NODE first = NULL;
    int choice;
    clrscr();

    while (1)
    {
        printf("\n--- DOUBLE ENDED QUEUE OPERATIONS ---\n");
        printf("1. Entry Restricted Queue\n");
        printf("2. Exit Restricted Queue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n--- ENTRY RESTRICTED OPERATIONS ---\n");
            printf("1. Insert (Rear Only)\n2. Delete Front\n3. Delete Rear\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                first = insert_rear(first);
                break;
            case 2:
                first = delete_front(first);
                break;
            case 3:
                first = delete_rear(first);
                break;
            default:
                printf("Invalid choice\n");
            }
            break;

        case 2:
            printf("\n--- EXIT RESTRICTED OPERATIONS ---\n");
            printf("1. Delete Front\n2. Insert Front\n3. Insert Rear\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                first = delete_front(first);
                break;
            case 2:
                first = insert_front(first);
                break;
            case 3:
                first = insert_rear(first);
                break;
            default:
                printf("Invalid choice\n");
            }
            break;

        case 3:
            display(first);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }

        getch();
        clrscr();
    }
}
