#ifndef STACK_H
#define STACK_H

#include "node.h"

// 스택 구조체 정의
typedef struct Stack {
    Node* data[100];
    int top;
} Stack;

// 스택 함수 선언
void initStack(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, Node* node);
Node* pop(Stack* stack);
Node* peek(Stack* stack);

#endif
