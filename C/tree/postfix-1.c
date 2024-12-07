/*
12.12 (Infix-to-Postfix Converter)

자료구조 학습을 하며 배운 이진트리를 이용해 infix식을 입력받아 postfix로 변환하는 알고리즘입니다.
infix문자열을 입력받은 뒤, nodes 스택에 트리 노드를 저장하고, operators 스택에 연산자와 괄호를 저장합니다.
isalnum함수를 이용해 피연산자임을 확인하여 nodes스택에 push하며, 문제에는 없지만 구현해두었던 괄호에 대한 연산도 진행합니다.
열린 괄호를 push한 이후에 닫힌 괄호를 탐색할 경우, 열린 괄호가 나올 때까지 operators스택을 pop하여 트리를 만듭니다.
infix식을 탐색하며 연산자가 나올 경우엔, operators스택에서 peek(최상단)연산자와 비교해 우선순위에 따라 연산자를 pop하여 사용하거나 operator스택이 push연산을 합니다.
operator를 하나씩 꺼내 nodes의 요소를을 트리로 묶어가면서 이진트리를 완성합니다.

이후 트리를 순회하는 순서에 따라 infix, postfix뿐 아니라 prefix도 구현 가능합니다.

infix의 경우 왼쪽 서브트리부터 순회하여 left node > 연산자 > right node순서로 출력해 구현 가능합니다.
postfix의 경우 left node > right node > 연산자 순서로 트리를 순회하여 구현했습니다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//이진트리 노드 구조체 정의
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

//스택 구조체 정의
typedef struct Stack {
    Node* data[100];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, Node* node) {
    stack->data[++(stack->top)] = node;
}

Node* pop(Stack* stack) {
    return stack->data[(stack->top)--];
}

Node* peek(Stack* stack) {
    return stack->data[stack->top];
}


Node* createNode(char data);
void infix(Node* root);
void postfix(Node* root);
int precedence(char op);
Node* buildTree(const char* sik);

int main() {
    char sik[100];

    printf("Enter an infix expression: ");
    fgets(sik, sizeof(sik), stdin);
    sik[strlen(sik)-1] = '\0'; // 줄바꿈 제거
    

    Node* root = buildTree(sik);

    printf("Infix Order: ");
    infix(root);
    printf("\nPostfix Order: ");
    postfix(root);
    printf("\n");

    return 0;
}

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 연산자 우선순위 확인 함수
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 이진 트리 생성 함수
Node* buildTree(const char* sik) {
    Stack nodes, operators;
    initStack(&nodes);
    initStack(&operators);

    for (int i = 0; i < strlen(sik); i++) {
        char ch = sik[i];

        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            push(&nodes, createNode(ch));
        }
        else if (ch == '(') {
            push(&operators, createNode(ch));
        }
        else if (ch == ')') {
            while (!isEmpty(&operators) && peek(&operators)->data != '(') {
                Node* opNode = pop(&operators);

                opNode->right = pop(&nodes);
                opNode->left = pop(&nodes);

                push(&nodes, opNode);
            }
            pop(&operators);
        }
        else {
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

void infix(Node* root) {
    if (root == NULL) return;
    if (root->left) printf("(");
    infix(root->left);
    printf("%c", root->data);
    infix(root->right);
    if (root->right) printf(")");
}

void postfix(Node* root) {
    if (root == NULL) return;
    postfix(root->left);
    postfix(root->right);
    printf("%c", root->data);
}