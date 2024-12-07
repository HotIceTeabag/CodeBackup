#include "tree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 연산자 우선순위 확인 함수
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 이진 트리 생성 함수
Node* buildTree(const char* expression) {
    Stack nodes, operators;
    initStack(&nodes);
    initStack(&operators);

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            push(&nodes, createNode(ch));
        } else if (ch == '(') {
            push(&operators, createNode(ch));
        } else if (ch == ')') {
            while (!isEmpty(&operators) && peek(&operators)->data != '(') {
                Node* opNode = pop(&operators);

                opNode->right = pop(&nodes);
                opNode->left = pop(&nodes);

                push(&nodes, opNode);
            }
            pop(&operators);
        } else {
            while (!isEmpty(&operators) && precedence(peek(&operators)->data) >= precedence(ch)) {
                Node* opNode = pop(&operators);

                opNode->right = pop(&nodes);
                opNode->left = pop(&nodes);

                push(&nodes, opNode);
            }
            push(&operators, createNode(ch));
        }
    }

    while (!isEmpty(&operators)) {
        Node* opNode = pop(&operators);

        opNode->right = pop(&nodes);
        opNode->left = pop(&nodes);

        push(&nodes, opNode);
    }

    return pop(&nodes);
}

// 순회 함수들
void infix(Node* root) {
    if (root == NULL) return;
    if (root->left) printf("(");
    infix(root->left);
    printf("%c", root->data);
    infix(root->right);
    if (root->right) printf(")");
}

void prefix(Node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    prefix(root->left);
    prefix(root->right);
}

void postfix(Node* root) {
    if (root == NULL) return;
    postfix(root->left);
    postfix(root->right);
    printf("%c", root->data);
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        printf("%c ", current->data);

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

