#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "poly.h"

//과제때 짠 insert 코드(insert 후 자동으로 오름차순 정렬해줌)->내림차순으로 바꿔서 다항식에 이용 가능
//변수명 및 구조체 이름 수정 필요!
/*
void insert(nodeP* sPtr, char value) {
	nodeP newP = malloc(sizeof(Node));

	if (newP != NULL) {
		newP->data = value;
		newP->next = NULL;

		Nodeptr prevP = NULL;
		Nodeptr currP = *sPtr;

		while (currP != NULL && value < currP->data) {
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
*/