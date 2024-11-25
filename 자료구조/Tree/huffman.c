#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

#define SIZE 20

char* inputstr() {			//�Լ� ����
	int index = 0, arr_size = 20;	//index(���ڿ� ��ġ Ȯ�ο�), arr_size(���ڿ� ����, �����ϸ� �ʱⰪ 20���� 20��ŭ ��� �þ.)

	char* strnow = (char*)malloc(sizeof(char) * arr_size);	//���ڿ� �ʱ⼱��
	char a;

	while ((a = getchar()) != EOF) {		//���� ���ڰ� EOF�� �ƴϸ� ����
		strnow[index] = a;				//���ڿ��� index��° ���ҿ� �Է¹��� a �Ҵ�
		index++;

		if (index >= arr_size) {
			arr_size += SIZE;
			char* temp = (char*)realloc(strnow, sizeof(char) * arr_size);

			if (temp == NULL) {
				free(strnow);
				printf("ERROR!\n");
				return NULL;
			}

			strnow = temp;
		}

	}
	strnow[index - 1] = '\0';

	return strnow;
}

treeP bind(treeP lft, treeP rht) {
    treeP newleaf = (treeP)malloc(sizeof(tree));
    
    newleaf->chr = '\0';
    newleaf->num = lft->num + rht->num;
    newleaf->left = lft;
    newleaf->right = rht;

    return newleaf;
}

int ascendingTree(const void* a, const void* b) {
	const treeP A = *(const treeP*)a;
	const treeP B = *(const treeP*)b;
	return A->num - B->num;
}

treeP huffmanE(treeP* treearr, int size) {
	int leng = size;

	while (leng > 1) {
		treeP temp = bind(treearr[0], treearr[1]);		//���� ���� ���� ���� ����

		for (int i = 2; i < leng; i++) {					//2���� �迭 ��� �մ��
			treearr[i - 2] = treearr[i];
		}
		leng -= 1;											//���� ���� �ϳ� ���̰� �� �ڿ� ���  ��� �߰�
		treearr[leng - 1] = temp;

		qsort(treearr, leng, sizeof(treeP), ascendingTree);	//�����ͳ��� ����, �迭�� �߰��ϰ�, ���� ���̱� �ݺ�
	}

	return treearr[0];
}

void fillTable(treeP root, pair* table, char* code, int depth, int* codeIndex) {
	if (root == NULL) return;

	// ���� ��忡 ������ ���
	if (root->left == NULL && root->right == NULL) {
		code[depth] = '\0';               // ���ڿ� ����
		table[*codeIndex].chr = root->chr; // ���� ����
		strcpy(table[*codeIndex].code, code); // �ڵ� ����
		(*codeIndex)++;
		return;
	}

	code[depth] = '0';
	fillTable(root->left, table, code, depth + 1, codeIndex);

	// ������ �ڽ�: 1 �߰�
	code[depth] = '1';
	fillTable(root->right, table, code, depth + 1, codeIndex);
}

pair* makeTable(treeP theTree, int count) {
	int depth = dive(theTree);
	printf("���̴� %d...", depth);
	pair* table = (pair*)malloc(sizeof(pair) * count);

	char code[depth + 1]; // ���� �ڵ� ����
	int codeIndex = 0;    // ���̺� �ε��� ����

	fillTable(theTree, table, code, 0, &codeIndex);

	return table;
}