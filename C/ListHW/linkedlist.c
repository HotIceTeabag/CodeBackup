/*
12.6 (Concatenating Lists)와 12.7 (Merging Ordered Lists)를 한 코드에 묶어서 풀었습니다.
기존에 코드로 주어진 insert함수는 sorted_insert함수로 이름을 바꾸어 두 번째 문제를 풀 때 사용했습니다.
그리고, insert함수를 바꾸어 입력값을 자동으로 정렬하던 기존의 함수와는 달리 리스트가 NULL인 경우엔 리스트에 바로 할당하고,
리스트가 비어있지 않은 경우에 리스트를 읽어갈 temp를 이용해 리스트의 마지막을 확인한 후에 새로 할당한 노드를 이어줍니다.

프로그램에서 링크드 리스트를 총 3개 이용합니다. 자료를 저장할 L1, L2와 두 리스트를 합친 결과물을 저장할 Ans(answer)리스트입니다.
메인 함수 역시, 기존에 코드로 주어진 함수를 변형하여 만들었습니다.
메뉴에서 1을 선택시 insert함수를 이용해 입력받은 값을 그대로 L1에 쌓아올립니다.
2를 입력한 경우 L2에 입력받은 char형 자료를 쌓아올립니다.

3의 경우가 Concatenating Lists로, Concatenating Lists에 사용되는 concateL함수에 대해 설명하겠습니다.
먼저 Ans리스트에 노드를 추가할 예정이기 때문에, Ans리스트가 비어있지 않은 경우 freeL함수를 통해 메모리를 초기화합니다.
freeL함수의 끝부분엔 배열의 시작주소를 NULL로 설정해두는 코드가 있습니다.
L1과 L2, Ans를 인자로 받아 L1과 L2의 값을 while문을 통해 순서대로 탐색하며 Ans배열에 insert함수를 통해 정렬하지 않고 이어붙입니다.
흐름상 L1의 시작주소를 복사한 l1이 l1 = l1->next연산을 통해 리스트를 순회하다가, l1이 NULL값을 갖게되며 while문을 탈출합니다.
이후 L2의 시작주소를 복사한 l2가 같은 과정을 통해 Ans리스트에 노드를 추가합니다.
따라서 L1의 노드들 -> L2의 노드들 순서로 Ans리스트가 채워지게 됩니다.

메인 메뉴에서 4를 입력할 경우 Merging Ordered Lists를 수행합니다.
Merging Ordered Lists에 사용되는 mergeL함수는 concateL함수와 구조적으로 동일합니다.
같은 인자를 받아서, 동일하게 초기에 Ans리스트가 비어있는지 검사한 후, 메모리를 초기화합니다.
똑같이 while문을 통해 L2과 L2를 순회하지만, insert함수 대신 기존에 이름을 sorted_insert로 바꾼 함수를 사용합니다.
따라서, Ans리스트에 노드를 추가하는 과정에서 자동적으로 기존의 값들과 순서를 비교하여 정렬된 상태로 리스트에 노드를 추가합니다.
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	char data;
	struct Node* next;
}listNode;

typedef listNode* list;
typedef listNode* LNodeptr;

void insert(LNodeptr* sPtr, char value);
void sorted_insert(LNodeptr* sPtr, char value);
void instructions();
void printL(LNodeptr list);
int EmptyL(LNodeptr sPtr);
void concateL(LNodeptr list1, LNodeptr list2, LNodeptr* newlist);
void mergeL(LNodeptr list1, LNodeptr list2, LNodeptr* newlist);

int main() {
	LNodeptr L1 = NULL;
	LNodeptr L2 = NULL;
	LNodeptr Ans = NULL;
	char item = '\0';

	instructions();
	printf("%s", "?");
	int choice = 0;
	scanf_s("%d", &choice);

	while(choice != 5) {
		switch(choice) {
			case 1:
				printf("%s", "Enter a charater of first list: ");
				scanf_s("%c", &item);
				insert(&L1, item);
				break;

			case 2:
				printf("%s", "Enter a charater of second list: ");
				scanf_s("%c", &item);
				insert(&L2, item);
				break;

			case 3:
				printf("First list: ");
				printL(L1);
				printf("Second list: ");
				printL(L2);

				concateL(L1, L2, &Ans);
				printf("Concatenated list: ");
				printL(Ans);
				break;

			case 4:
				printf("First list: ");
				printL(L1);
				printf("Second list: ");
				printL(L2);

				mergeL(L1, L2, &Ans);
				printf("Merged and sorted list: ");
				printL(Ans);
		}
		printf("order: ");

		scanf_s("%d", &choice);
	}
}

void instructions(void) {
	puts("1 to insert an element into the first list.\n"
		"2 to insert an element into the second list.\n"
		"3 to concatenate lists.\n"
		"4 to make ordered list.\n"
		"5 to End.\n");
}

void insert(LNodeptr* sPtr, char value) {
	LNodeptr newP = malloc(sizeof(listNode));

	if (newP != NULL) {

		newP->data = value;
		newP->next = NULL;

		if (*sPtr == NULL) {
			*sPtr = newP;
			return;
		}
		LNodeptr temp = *sPtr;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newP;
	}
	else {
		printf("%c not inserted, No memory available.\n", value);
	}
}

void sorted_insert(LNodeptr *sPtr, char value) {
	LNodeptr newP = malloc(sizeof(listNode));

	if (newP != NULL) {
		newP->data = value;
		newP->next = NULL;

		LNodeptr prevP = NULL;
		LNodeptr currP = *sPtr;

		while (currP != NULL && value > currP->data) {
			prevP = currP;
			currP = currP->next;
		}
		
		if (prevP == NULL) {
			newP->next = *sPtr;
			*sPtr = newP;
		}
		else {
			prevP->next = newP;
			newP->next = currP;
		}
	}
	else {
		printf("%c not inserted, No memory available.\n", value);
	}
}

int EmptyL(LNodeptr sPtr) {
	if (sPtr == NULL)return 1;
	return 0;
}

void printL(LNodeptr list) {
	LNodeptr talker = list;
	
	if (EmptyL(list)) printf("This list is empty!");
	else {
		while (talker != NULL) {
			printf("%c ", talker->data);
			talker = talker->next;
		}
	}
	printf("\n\n");
}

void freeL(LNodeptr* list) {
	LNodeptr killer = *list, next;

	while (killer != NULL) {
		next = killer->next;
		free(killer);
		killer = next;
	}

	*list = NULL;
}

void concateL(LNodeptr list1, LNodeptr list2, LNodeptr* newlist) {
	if (*newlist != NULL)freeL(newlist);

	LNodeptr l1 = list1;
	LNodeptr l2 = list2;

	while (l1 != NULL) {
		insert(newlist, l1->data);
		l1 = l1->next;
	}

	while (l2 != NULL) {
		insert(newlist, l2->data);
		l2 = l2->next;
	}
}

void mergeL(LNodeptr list1, LNodeptr list2, LNodeptr* newlist) {
	if (*newlist != NULL)freeL(newlist);

	LNodeptr l1 = list1;
	LNodeptr l2 = list2;

	while (l1 != NULL) {
		sorted_insert(newlist, l1->data);
		l1 = l1->next;
	}

	while (l2 != NULL) {
		sorted_insert(newlist, l2->data);
		l2 = l2->next;
	}
}