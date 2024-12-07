/*
이전에 자료구조 학습을 위해 만들어둔 이진트리를 이용해 infix식을 입력받아 postfix로 변환하는 알고리즘입니다.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int main() {
    char expression[100];

    printf("Enter an postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strlen(expression)-1] = '\0'; // 줄바꿈 제거
    

    return 0;
}

