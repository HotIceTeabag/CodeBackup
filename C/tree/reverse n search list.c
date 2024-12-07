/*
12.9 (Creating a Linked List, Then Reversing Its Elements)

리스트를 뒤집기 위해 뒤집은 리스트를 저장할 REVERSE라는 리스트를 사용했습니다.
copyL함수를 이용해 원본 리스트인 L1을 복사합니다.
L1을 복사할 때에는 노드 포인터를 계속 자신의 next를 참조하게 만든 뒤, NULL에 도달하기 전까지 L1의 원소를 참조하여 insert연산을 합니다.

리스트의 복사가 끝난 뒤에는 reverse함수를 이용해 리스트를 뒤집습니다.
이전 노드, 현재 노드, 다음 노드를 가리키는 포인터 셋을 이용하여 포인터 링크의 방향을 반전시켜 순서를 바꾸었습니다.

12.18 (Recursively Search a List)

search함수를 통해 검색을 구현했습니다.
노드에 대한 포인터인 seeker를 선언하여 while문을 이용해 seeker가 계속 자신의 next를 참조하게 만듭니다.
seeker이동 후 인자로 주어진 chr과 노드의 data를 비교하여 동일한 값을 발견한 경우에 seeker를 반환해 일치하는 노드의 주소를 알아냅니다.
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
void instructions();
void printL(LNodeptr list);
int EmptyL(LNodeptr sPtr);
LNodeptr search(char chr, LNodeptr list);
LNodeptr copyL(LNodeptr list);
LNodeptr reverseL(LNodeptr list);

int main() {
	LNodeptr L1 = NULL;
	LNodeptr REVERSE = NULL;
	char item = '\0';

	instructions();
	printf("%s", "?");
	int choice = 0;
	scanf("%d", &choice);
	getchar();

	while(choice != 5) {
		switch(choice) {
			case 1:
				printf("%s", "Enter a charater of list: ");
				scanf("%c", &item);
				insert(&L1, item);
				break;

			case 2:
				printf("%s", "reverse list: ");
				REVERSE = copyL(L1);
				REVERSE = reverseL(REVERSE);
				printL(REVERSE);
				break;

			case 3:
				printf("list is: ");
				printL(L1);
				break;

			case 4:
				scanf("%c", &item);
				LNodeptr output = search(item, L1);

				if (output != NULL) {
					printf("%c is in list, address is %p\n", item, (void*)output);
				}else printf("%c is not in list!\n", item);

				break;
		}
		printf("order: ");

		scanf("%d", &choice);
		getchar();
	}
}

void instructions(void) {
	puts("1 to insert an element into the list.\n"
		"2 to reversing list.\n"
		"3 to print list.\n"
		"4 to search an element in original list.\n"
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

int EmptyL(LNodeptr sPtr) {
	if (sPtr == NULL)return 1;
	return 0;
}

void printL(LNodeptr list) {
	LNodeptr talker = list;
	
	if (EmptyL(list)) printf("This list is empty!\n");
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

LNodeptr search(char chr, LNodeptr list) {
	LNodeptr seeker = list;

	while (seeker != NULL) {
		if (seeker->data == chr)return seeker;
		seeker = seeker->next;
	}

	return NULL;
}

LNodeptr copyL(LNodeptr list) {
	if (list == NULL) {
		return NULL;
	}

	LNodeptr newlist = NULL;
	LNodeptr seeker = list;

	while (seeker != NULL) {
		insert(&newlist, seeker->data);
		seeker = seeker->next;
	}

	return newlist;
}

LNodeptr reverseL(LNodeptr list) {
	LNodeptr back = NULL;
	LNodeptr current = list;
	LNodeptr next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		back = current;
		current = next;
	}

	return prev;
}