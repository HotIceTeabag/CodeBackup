#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"



int ascending(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);		//오름차순 정렬
}


int main() {
	int order;

	printf("1 입력시 다항식, 2 입력시 허프만 코딩\n선택: ");
	scanf("%d", &order);

	
	if (order == 1) {

	}
	else if (order == 2) {
		huffmancoding();
	}

	return 0;
}


void huffmancoding() {
	char* str;
	int leng, index = 0, count = 1;
	printf("문자열 입력: ");
	getchar();
	str = inputstr();					//입력을 종료할땐 엔터로 줄바꿈 이후 EOF로 종료할 것!

	printf("\n입력된 내용: %s\n", str);

	char* copy = (char*)malloc(strlen(str) + 1);
	strcpy(copy, str);

	leng = strlen(str);
	qsort(copy, strlen(str), sizeof(char), ascending);

	for (int i = 1; i < leng; i++) {
		if (copy[i] != copy[i - 1])count++;
	}

	treeP* treearr = (treeP*)malloc(sizeof(treeP) * count);
	for (int i = 0; i < count; i++) {
		treearr[i] = (treeP)malloc(sizeof(tree));
		treearr[i]->left = NULL;
		treearr[i]->right = NULL;
	}


	treearr[index]->chr = copy[0];
	treearr[index]->num = 1;
	for (int i = 1; i < leng; i++) {

		if (copy[i] != copy[i - 1]) {
			index++;
			treearr[index]->chr = copy[i];
			treearr[index]->num = 1;
		}
		else treearr[index]->num++;
	}

	printf("정렬: %s\n", copy);
	qsort(treearr, count, sizeof(treeP), ascendingTree);

	for (int i = 0; i < count; i++) {
		printf("문자 :%c, 빈도 :%d\n", treearr[i]->chr, treearr[i]->num);
	}

	treeP theTree = huffman(treearr, count);

	pair* huffmanTable = makeTable(theTree, count);

	printf("문자별 코드:\n");
	for (int i = 0; i < count; i++) {
		printf("'%c': %s\n", huffmanTable[i].chr, huffmanTable[i].code);
	}

	char* encoded = huffmanEncoding(str, huffmanTable, count);

	printf("\n%s\n", encoded);

	char* decoded = huffmanDecoding(encoded, theTree, leng);

	printf("\n%s\n", decoded);

	for (int i = 0; i < count; i++) {				//할당 해제
		free(treearr[i]);
	}

	free(str);
	free(copy);
	free(treearr);

	return;
}