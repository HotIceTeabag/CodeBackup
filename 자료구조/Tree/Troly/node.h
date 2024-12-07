#ifndef NODE_H
#define NODE_H

// 노드 구조체 정의
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// 노드 생성 함수
Node* createNode(char data);

#endif
