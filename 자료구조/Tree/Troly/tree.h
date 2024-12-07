#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "stack.h"

// 연산자 우선순위 함수
int precedence(char op);

// 이진 트리 생성 함수
Node* buildTree(const char* expression);

// 트리 순회 함수
void infix(Node* root);
void prefix(Node* root);
void postfix(Node* root);
void levelOrder(Node* root);

#endif
