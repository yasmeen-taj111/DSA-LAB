//9. Evaluation expression tree using binary tree

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include<conio.h>

struct node {
    char data;
    struct node *lchild, *rchild;
};
typedef struct node* NODE;

NODE create_tree(char postfix[]){
     NODE stack[20], temp;
    int i, top = -1;

    for(i = 0; postfix[i] != '\0'; i++) {
        temp = (NODE)malloc(sizeof(struct node));
        temp->data = postfix[i];
        temp->lchild = temp->rchild = NULL;

        if(isalnum(postfix[i])) {
            stack[++top] = temp;
        } else {
            temp->rchild = stack[top--];
            temp->lchild = stack[top--];
            stack[++top] = temp;
        }
    }
    return stack[top];
    
}
float eval(NODE root){
    float num;

    if(isdigit(root->data))
        return (root->data - '0');

    if(isalpha(root->data)) {
        printf("Enter value of %c: ", root->data);
        scanf("%f", &num);
        return num;
    }

    switch(root->data) {
        case '+': return eval(root->lchild) + eval(root->rchild);
        case '-': return eval(root->lchild) - eval(root->rchild);
        case '*': return eval(root->lchild) * eval(root->rchild);
        case '/': return eval(root->lchild) / eval(root->rchild);
        case '^': return pow(eval(root->lchild), eval(root->rchild));
        default : return 0;
    }
    
}

int main() {
    char postfix[20];
    clrscr();
    float result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    NODE root = create_tree(postfix);
    result = eval(root);

    printf("Result = %f\n", result);
    getch();
    return 0;
}


