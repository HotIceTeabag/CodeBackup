/*
������ �������� �־��� queue���� �ڵ� �� �Լ��� �̿��߽��ϴ�. enqueue �� dequeue, isEmpty�Լ� ��� ���� ���� �̿��߽��ϴ�.
���α׷��� �帧�� �����ϰڽ��ϴ�.
H1, T1���� ù ��° ť�� H2, T2�� �� ��° ť�� �����߽��ϴ�.
���� fgets�Լ��� ���� �Ӹ�������� Ȯ���� ���ڿ��� �Է¹޽��ϴ�.
���� �߰��� goodstr�Լ��� ���� ���ڿ��� ����, ������ ���� ������ ���ĺ��� ���ڸ��� ����ϴ�.

goodstr�Լ��� �����δ�, ���ڿ� str�� ���ڷ� �޾� ���� i�� ���ڿ��� Ž���մϴ�.
���� j�� ���ڿ��� ���� �Է��ϱ����� ����� ������, i�� �ϳ��� �ö󰡸� �迭�� Ž���� �� if���� ���� ���ĺ��� ���ڸ� �ɷ����ϴ�.
���ĺ��� ���ڰ� ���� ������ i�� j�� ���� �ö�����, �ٸ� ���ڰ� ���� ��쿣 i�� ���� �ö󰡸� ��ȿ�� ���ڸ� Ž���մϴ�.
i�� �� ���ڸ� ���� ���ڿ� ���� ������ ��� j�� ���ݱ��� �Է��ؿ� ���ڵ� �ڿ� �� ���ڸ� ������ ���ڿ��� �����մϴ�.

goodstr�Լ��� ���ڿ��� �ٲپ��ٸ�, for���� ���� ù ��° ť�� ���ڿ��� ������ enqueue�Լ��� ���� ������� ����ֽ��ϴ�.
�� ��° ť����, ���ڿ��� ���κк��� ���ڿ��� ���ݱ��� �������� enqueue�մϴ�.

���ڿ��� ���̸� �������� ���� ���ǹ� ������ ���ڿ��� ���̰� ¦����, 12344321���� ��쿣 �� ť ��� 1234��� ���� �����ϴ�.
���ڿ��� ���̰� Ȧ���� 123454321���� ��쿣, ù ��° ť���� 1234��, �� ��° ť���� 12345�� ����ְ� �˴ϴ�.

while���� ���� ù ��° ť�� NULL���� �� ������ �� ť ��� dequeue�� �ϸ� ��ȯ���� ������ �����մϴ�.
��� dequeue�� �Ͽ� ù ��° ť�� �ΰ��� ���� ������ dequeue�� �ߴٸ�, �� ��° ť�� �ΰ��� ���ų� �� ���� ��常�� ���� ���°� �˴ϴ�.
������ ���� ���̰� ¦���� �Ӹ���� ���ڿ��̰�, ������ ���� ���̰� Ȧ���� �Ӹ���� ���ڿ��Դϴ�.
���� ù ��° ť�� �ΰ��� ������ �����Ͽ� �´ٸ� �Ӹ�������� �˸��� ���ڿ��� printf�Լ��� ���� ����ϰ� ���α׷��� �����մϴ�.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queueNode {
    char data;
    struct queueNode* next;
}qNode;

typedef qNode* qNodeP;

void printQueue(qNodeP currentPtr);
int isEmpty(qNodeP headPtr);
void enqueue(qNodeP* headPtr, qNodeP* tailPtr, char value);
char dequeue(qNodeP* headPtr, qNodeP* tailPtr);
void instructions(void);
void goodstr(char* str);

int main(void) {
    qNodeP H1 = NULL;
    qNodeP T1 = NULL;

    qNodeP H2 = NULL;
    qNodeP T2 = NULL;
    char str[201];

    printf("insert string: ");
    fgets(str, 200, stdin);
    str[strlen(str) - 1] = '\0';
    goodstr(str);

    int leng = strlen(str);

    for (int i = 0; i < leng / 2; i++) {
        enqueue(&H1, &T1, str[i]);
    }

    for (int i = leng - 1; i >= leng / 2; i--) {
        enqueue(&H2, &T2, str[i]);
    }

    while (!isEmpty(H1) && (dequeue(&H1, &T1) == dequeue(&H2, &T2)));

    if (isEmpty(H1)) {
        printf("\"%s\" this string is palindrome.\n", str);
    }
    else {
        printf("\"%s\" this string is NOT palindrome!\n", str);
    }
}

void enqueue(qNodeP* headPtr, qNodeP* tailPtr, char value) {
    qNodeP new = malloc(sizeof(qNode));

    if (new != NULL) {
        new->data = value;
        new->next = NULL;

        if (isEmpty(*headPtr)) {
            *headPtr = new;
        }
        else {
            (*tailPtr)->next = new;
        }

        *tailPtr = new;
    }
    else {
        printf("%c not inserted. No memory available.\n", value);
    }
}

char dequeue(qNodeP* headPtr, qNodeP* tailPtr) {
    char value = (*headPtr)->data;
    qNodeP tempPtr = *headPtr;
    *headPtr = (*headPtr)->next;

    if (*headPtr == NULL) {
        *tailPtr = NULL;
    }

    free(tempPtr);
    return value;
}

int isEmpty(qNodeP headPtr) {
    return headPtr == NULL;
}

void printQueue(qNodeP currentPtr) {
    if (currentPtr == NULL) {
        puts("Queue is empty.\n");
    }
    else {
        puts("The queue is:");

        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->next;
        }

        puts("NULL\n");
    }
}

void goodstr(char* str) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            str[j] = str[i];
            j++;
            i++;
        }
        else {
            i++;
        }
    }

    str[j] = '\0';
}