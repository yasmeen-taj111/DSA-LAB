//10. Create Right in threaded binary tree:
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
    int rt; // 1 -> right is thread, 0 -> right is child
};
typedef struct node* NODE;

NODE createNode(int val) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->rt = 1; 
    return temp;
}

NODE insert(NODE root, int val, NODE head) {
    NODE cur, parent;
    cur = root;
    parent = NULL;

    while(cur != NULL && cur != head) {
        parent = cur;
        if(val < cur->data) {
            cur = cur->left;
        } else {
            if(cur->rt == 0)
                cur = cur->right;
            else
                break;
        }
    }

    NODE newnode = createNode(val);

    if(parent == NULL) {
        root = newnode;
        newnode->right = head;
        return root;
    }

    if(val < parent->data) {
        parent->left = newnode;
        newnode->right = parent;
    } else {
        newnode->right = parent->right;
        parent->right = newnode;
        parent->rt = 0;
    }

    return root;
}

NODE inorderSuccessor(NODE ptr) {
    NODE temp = ptr->right;

    if(ptr->rt == 1)
        return temp;

    while(temp->left != NULL)
        temp = temp->left;
    return temp;
}

void inorder(NODE root, NODE head) {
    NODE temp;

    if(root == NULL) {
        printf("\nTree is Empty!");
        return;
    }

    temp = root;
    while(temp->left != NULL)
        temp = temp->left;

    while(temp != head) {
        printf("%d ", temp->data);
        temp = inorderSuccessor(temp);
    }
}

void main() {
    int ch, val, n, i;
    NODE root = NULL, head;

    clrscr();

    head = createNode(-1); 
    head->right = head;
    head->left = NULL;
    head->rt = 0;

    while(1) {
        printf("\n\n--- Right Threaded Binary Tree ---");
        printf("\n1. Create Tree");
        printf("\n2. Display Inorder");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                for(i = 1; i <= n; i++) {
                    printf("Enter value %d: ", i);
                    scanf("%d", &val);
                    root = insert(root, val, head);
                    head->left = root;
                }
                break;

            case 2:
                printf("\nInorder Traversal: ");
                inorder(root, head);
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }

        getch();
        clrscr();
    }
}
