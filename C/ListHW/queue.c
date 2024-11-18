/*
기존의 예제에서 주어진 queue관련 코드 및 함수를 이용했습니다. enqueue 및 dequeue, isEmpty함수 모두 수정 없이 이용했습니다.
프로그램의 흐름을 설명하겠습니다.
H1, T1으로 첫 번째 큐와 H2, T2로 두 번째 큐를 구현했습니다.
이후 fgets함수를 통해 팰린드롬인지 확인할 문자열을 입력받습니다.
직접 추가한 goodstr함수를 통해 문자열의 공백, 구두점 등을 제거해 알파벳과 숫자만을 남깁니다.

goodstr함수의 구조로는, 문자열 str을 인자로 받아 변수 i로 문자열을 탐색합니다.
변수 j는 문자열의 값을 입력하기위해 사용한 변수로, i가 하나씩 올라가며 배열을 탐색할 때 if문을 통해 알파벳과 숫자를 걸러냅니다.
알파벳과 숫자가 나올 때에는 i와 j가 같이 올라가지만, 다른 문자가 나올 경우엔 i의 값만 올라가며 유효한 문자를 탐색합니다.
i가 널 문자를 만나 문자열 끝에 도달한 경우 j는 지금까지 입력해온 문자들 뒤에 널 문자를 삽입해 문자열을 정제합니다.

goodstr함수로 문자열을 바꾸었다면, for문을 통해 첫 번째 큐에 문자열의 절반을 enqueue함수를 통해 순서대로 집어넣습니다.
두 번째 큐에는, 문자열의 끝부분부터 문자열의 절반까지 역순으로 enqueue합니다.

문자열의 길이를 절반으로 나눈 조건문 때문에 문자열의 길이가 짝수인, 12344321같은 경우엔 두 큐 모두 1234라는 값을 갖습니다.
문자열의 길이가 홀수인 123454321같은 경우엔, 첫 번째 큐에는 1234가, 두 번째 큐에는 12345가 들어있게 됩니다.

while문을 통해 첫 번째 큐가 NULL값이 됄 때까지 두 큐 모두 dequeue를 하며 반환값이 같은지 조사합니다.
계속 dequeue를 하여 첫 번째 큐가 널값을 가질 때까지 dequeue를 했다면, 두 번째 큐도 널값을 갖거나 한 가지 노드만을 가진 상태가 됩니다.
전자의 경우는 길이가 짝수인 팰린드롬 문자열이고, 후자의 경우는 길이가 홀수인 팰린드롬 문자열입니다.
이후 첫 번째 큐가 널값을 갖는지 조사하여 맞다면 팰린드롬임을 알리는 문자열을 printf함수를 통해 출력하고 프로그램을 종료합니다.
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