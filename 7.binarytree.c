//7. Create binary tree and traverse inrorder, preorder and postorder:

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

NODE create();
void preorder(NODE root);
void inorder(NODE root);
void postorder(NODE root);

void main()
{
    NODE root = NULL;
    clrscr();

    printf("---- BINARY TREE CREATION AND TRAVERSALS ----\n");
    printf("Create the root node:\n");
    root = create();

    printf("\nPreorder traversal:\n");
    preorder(root);

    printf("\n\nInorder traversal:\n");
    inorder(root);

    printf("\n\nPostorder traversal:\n");
    postorder(root);

    getch();
}

NODE create()
{
    NODE newnode;
    int x;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = x;

    printf("Enter left child of %d:\n", x);
    newnode->left = create();

    printf("Enter right child of %d:\n", x);
    newnode->right = create();

    return newnode;
}

// Preorder: ROOT → LEFT → RIGHT
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d=>", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder: LEFT → ROOT → RIGHT
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d=>", root->data);
        inorder(root->right);
    }
}

// Postorder: LEFT → RIGHT → ROOT
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d=>", root->data);
    }
}
