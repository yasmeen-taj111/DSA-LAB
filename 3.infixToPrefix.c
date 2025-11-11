//3. Write a program to convert a given infix expression to prefix:
#include <stdio.h>
#include <conio.h>
#include <string.h>

char stack[20], infix[20], postfix[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[]) {
    int i, j = 0;
    char symbol, temp;
    push('#');

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if (symbol == '(')
            push(symbol);
        else if (symbol == ')') {
            temp = pop();
            while (temp != '(') {
                postfix[j++] = temp;
                temp = pop();
            }
        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') {
            while (precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        } else {
            postfix[j++] = symbol;
        }
    }

    while (top > 0)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

void main() {
    int len, i;
    char temp;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    len = strlen(infix);
    for (i = 0; i < len / 2; i++) {
        temp = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = temp;
    }

    for (i = 0; i < len; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    infixToPostfix(infix);

    printf("Prefix expression: ");
    for (i = strlen(postfix) - 1; i >= 0; i--)
        printf("%c", postfix[i]);

    getch();
}
