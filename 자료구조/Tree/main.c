#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"



int ascending(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);		//�������� ����
}


int main() {
	int order;

	printf("1 �Է½� ���׽�, 2 �Է½� ������ �ڵ�");
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
	printf("���ڿ� �Է�: ");
	getchar();
	str = inputstr();					//�Է��� �����Ҷ� ���ͷ� �ٹٲ� ���� EOF�� ������ ��!

	printf("\n�Էµ� ����: %s\n", str);

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

	printf("����: %s\n", copy);
	qsort(treearr, count, sizeof(treeP), ascendingTree);

	for (int i = 0; i < count; i++) {
		printf("���� :%c, �� :%d\n", treearr[i]->chr, treearr[i]->num);
	}

	treeP theTree = huffmanE(treearr, count);

	pair* huffmanTable = makeTable(theTree, count);

	printf("Huffman Codes:\n");
	for (int i = 0; i < count; i++) {
		printf("'%c': %s\n", huffmanTable[i].chr, huffmanTable[i].code);
	}

	for (int i = 0; i < count; i++) {				//�Ҵ� ����
		free(treearr[i]);
	}
	free(str);
	free(copy);
	free(treearr);
}