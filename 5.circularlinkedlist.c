//5. Write a program to implement circular linked list using header node

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

NODE insert_front(NODE head)
{
    NODE temp = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = head->next;
    head->next = temp;
    printf("%d is successfully inserted\n", temp->data);
    return head;
}

NODE insert_rear(NODE head)
{
    NODE temp, ptr = head->next;
    while (ptr->next != head)
        ptr = ptr->next;
    temp = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    ptr->next = temp;
    temp->next = head;
    printf("%d is successfully inserted\n", temp->data);
    return head;
}

NODE delete_front(NODE head)
{
    NODE ptr;
    if (head->next == head)
    {
        printf("No nodes\n");
        return head;
    }
    ptr = head->next;
    printf("%d is successfully deleted\n", ptr->data);
    head->next = ptr->next;
    free(ptr);
    return head;
}

NODE delete_rear(NODE head)
{
    NODE ptr, prev;
    if (head->next == head)
    {
        printf("No nodes\n");
        return head;
    }
    ptr = head->next;
    while (ptr->next != head)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    printf("%d is successfully deleted\n", ptr->data);
    prev->next = head;
    free(ptr);
    return head;
}

void display(NODE head)
{
    NODE temp;
    if (head->next == head)
    {
        printf("No nodes\n");
        return;
    }
    printf("List elements: ");
    for (temp = head->next; temp->next != head; temp = temp->next)
        printf("%d=>", temp->data);
    printf("%d\n", temp->data);
}

void main()
{
    NODE head;
    int choice;
    clrscr();

    head = getnode();
    head->next = head;

    while (1)
    {
        printf("\n--- CIRCULAR LINKED LIST OPERATIONS ---\n");
        printf("1. Insert Rear\n2. Insert Front\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = insert_rear(head);
            break;
        case 2:
            head = insert_front(head);
            break;
        case 3:
            head = delete_front(head);
            break;
        case 4:
            head = delete_rear(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }

        getch();
        clrscr();
    }
}
