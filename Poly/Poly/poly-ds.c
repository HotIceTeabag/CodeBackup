#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "poly.h"

//과제때 짠 insert 코드(insert 후 자동으로 오름차순 정렬해줌)->내림차순으로 바꿔서 다항식에 이용 가능
//변수명 및 구조체 이름 수정 필요!

void insert(nodeP* sPtr, int dimm, int vall) {
	nodeP newP = malloc(sizeof(poly));

	if (newP != NULL) {						//newP타입 할당 성공
		newP->dim = dimm;
		newP->val = vall;
		newP->next = NULL;

		nodeP prevP = NULL;					//이전의 노드
		nodeP currP = *sPtr;				//현재 비교중인 노드
		
		while (currP != NULL && dimm < currP->dim) {	//기존 입력받은 리스트가 not_Null이고, 새로 입력받은 차원이 비교중인 차원보다 작음.
			prevP = currP;								//지금 비교중인 노드를 prev에 넘겨주고
			currP = currP->next;						//노드를 한 단계 전진
		}

		if (prevP == NULL) {							//리스트가 비어있음
			newP->next = *sPtr;							//
			*sPtr = newP;
		}
		else {
			prevP->next = newP;
			newP->next = currP;
		}
	}
	else {
		printf("동적할당 실패!\n");
	}
}

void prt_poly(polyList p) {
	nodeP currP = p;
	if (currP == NULL) {
		printf("다항식이 비어있음.");
		return;
	}
	while (currP != NULL) {
		printf("   %+d*x^%d", currP->val, currP->dim);
		currP = currP->next;
	}
	printf("\n");
}

int count_list(polyList p) {
	nodeP now = p;
	int index = 0;
	while (now != NULL) {
		index++;
		now = now->next;
	}
	return index;
}

void add_poly(nodeP* sPtr, polyList p1, polyList p2) {

	polyList answer = NULL;								//반환할 answer

	while (p1 != NULL && p2 != NULL) {					//둘 다 NULL이 아닐때....즉, 비교해야할 경우
		if (p1->dim == p2->dim) {						//차수가 같을 때
			if ((p1->val + p2->val) != 0) {
				insert(&answer, p1->dim, p1->val + p2->val);
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->dim > p2->dim) {					//p1의 차수가 더 클 때
			insert(&answer, p1->dim, p1->val);
			p1 = p1->next;
		}
		else {											//p2의 차수가 더 클 때
			insert(&answer, p2->dim, p2->val);
			p2 = p2->next;
		}
	}

	while (p1 != NULL) {
		insert(&answer, p1->dim, p1->val);
		p1 = p1->next;
	}

	while (p2 != NULL) {
		insert(&answer, p2->dim, p2->val);
		p2 = p2->next;
	}

	*sPtr = answer;
}

void free_list(polyList list) {
	nodeP killer = list, next;

	while (killer != NULL) {
		next = killer->next;
		free(killer);
		killer = next;
	}
}
