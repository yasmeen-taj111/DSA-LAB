// 8. Perform insert and delete operations in binary search tree:
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

typedef struct node* NODE;

NODE createNode(int val) {
    NODE newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

NODE insert(NODE root, int val) {
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}

NODE findMin(NODE root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

NODE deleteNode(NODE root, int val) {
    if(root == NULL) {
        printf("Element not found\n");
        return root;
    }

    if(val < root->data)
        root->left = deleteNode(root->left, val);

    else if(val > root->data)
        root->right = deleteNode(root->right, val);

    else {
        if(root->left == NULL) {
            NODE temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            NODE temp = root->left;
            free(root);
            return temp;
        }

        NODE temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(NODE root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main() {
    int ch, val;
    NODE root = NULL;
    clrscr();

    while(1) {
        printf("\n\n1.Insert\n2.Delete\n3.Display(Inorder)\n4.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Inserted Successfully!");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                break;

            case 4:
                exit(0);

            default: 
                printf("Invalid Choice!");
        }
        getch();
        clrscr();
    }
}
