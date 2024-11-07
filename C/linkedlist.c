#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	char data;
	struct Node* next;
}Node;

typedef Node* list;
typedef Node* Nodeptr;

void insert(Nodeptr* sPtr, char value);
void instructions();


int main() {
	Nodeptr start = NULL;
	char item = '\0';

	instructions();
	printf("%s", "?");
	int choice = 0;
	scanf_s("%d", &choice);

	while(choice != 3) {
		switch(choice) {
			case 1:
				printf("%s", "Enter a charater: ");
				scanf_s("\n%c", &item);
				insert(&start, item);
				//printList(start);
				break;
			case 2:
				if (1/*!isEmpty(start)*/) {
					printf("%s", "Enter character to be deletde: ");
					scanf_s("\n%c", &item);



					//제거 코드
				}
		}
	}
}

void instructions(void) {
	puts("1 to insert an element into the list.\n"
		"2 to delete an element from the list.\n"
		"3 to end.");
}

void insert(Nodeptr *sPtr, char value) {
	Nodeptr newP = malloc(sizeof(Node));

	if (newP != NULL) {
		newP->data = value;
		newP->next = NULL;

		Nodeptr prevP = NULL;
		Nodeptr currP = *sPtr;

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

//void printflist 