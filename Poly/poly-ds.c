#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "poly.h"

//������ § insert �ڵ�(insert �� �ڵ����� �������� ��������)->������������ �ٲ㼭 ���׽Ŀ� �̿� ����
//������ �� ����ü �̸� ���� �ʿ�!
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