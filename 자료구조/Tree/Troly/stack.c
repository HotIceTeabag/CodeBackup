#include "stack.h"

// 스택 초기화
void initStack(Stack* stack) {
    stack->top = -1;
}

// 스택이 비어 있는지 확인
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 스택에 푸시
void push(Stack* stack, Node* node) {
    stack->data[++(stack->top)] = node;
}

// 스택에서 팝
Node* pop(Stack* stack) {
    return stack->data[(stack->top)--];
}

// 스택의 최상단 요소 확인
Node* peek(Stack* stack) {
    return stack->data[stack->top];
}

