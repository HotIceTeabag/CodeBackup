#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

#define SIZE 20

char* inputstr() {			//함수 시작
	int index = 0, arr_size = 20;	//index(문자열 위치 확인용), arr_size(문자열 길이, 부족하면 초기값 20에서 20만큼 계속 늘어남.)

	char* strnow = (char*)malloc(sizeof(char) * arr_size);	//문자열 초기선언
	char a;

	while ((a = getchar()) != EOF) {		//받은 문자가 EOF가 아니면 유지
		strnow[index] = a;				//문자열의 index번째 원소에 입력받은 a 할당
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

treeP bind(tree* Left, tree* Right) {
    treeP newleaf = (treeP)malloc(sizeof(tree));
    
    newleaf->chr = '\0';
    newleaf->num = Left->num + Right->num;
    newleaf->left = Left;
    newleaf->right = Right;

    return newleaf;
}

int ascendingTree(const void* a, const void* b) {
	const treeP A = *(const treeP*)a;
	const treeP B = *(const treeP*)b;
	return A->num - B->num;
}

treeP huffman(treeP* treearr, int size) {
	int leng = size;

	while (leng > 1) {
		treeP temp = bind(treearr[0], treearr[1]);		//가장 작은 노드들 둘이 묶기

		for (int i = 2; i < leng; i++) {					//2개씩 배열 요소 앞당김
			treearr[i - 2] = treearr[i];
		}
		leng -= 1;											//원소 개수 하나 줄이고 맨 뒤에 묶어낸  노드 추가
		treearr[leng - 1] = temp;

		qsort(treearr, leng, sizeof(treeP), ascendingTree);	//작은것끼리 묶고, 배열에 추가하고, 길이 줄이기 반복
	}

	return treearr[0];
}

void fillTable(treeP root, pair* table, char* code, int depth, int* codeIndex) {
	if (root == NULL) return;

	// 리프 노드에 도달한 경우
	if (root->left == NULL && root->right == NULL) {
		code[depth] = '\0';					//문자열 끝내기
		table[*codeIndex].chr = root->chr;	// 문자 저장
		strcpy(table[*codeIndex].code, code); // 코드 저장
		(*codeIndex)++;
		return;
	}
	//왼쪽 리프에는 0
	code[depth] = '0';
	fillTable(root->left, table, code, depth + 1, codeIndex);

	//오른쪽 리프에는 1
	code[depth] = '1';
	fillTable(root->right, table, code, depth + 1, codeIndex);
}

pair* makeTable(treeP theTree, int count) {
	int depth = dive(theTree);
	pair* table = (pair*)malloc(sizeof(pair) * count);

	char code[depth + 1]; // 현재 코드 저장
	int codeIndex = 0;    // 테이블 인덱스 추적

	fillTable(theTree, table, code, 0, &codeIndex);

	return table;
}

char* huffmanEncoding(char* str, pair* table, int charcount) {
	int len = strlen(str), code_max = 0;

	for (int i = 0; i < charcount; i++)if (code_max < strlen(table[i].code))code_max = strlen(table[i].code);	//가장 길이가 긴 허프만 코드 찾기

	char* encoding = (char*)malloc(sizeof(char) * (len * code_max + 1));	//허프만 코드를 저장할 배열

	encoding[0] = '\0';
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < charcount; j++) {
			if (str[i] == table[j].chr) {					//테이블에서 문자에 맞는 코드를 찾음
				strcat(encoding, table[j].code);
				break;
			}
		}
	}

	return encoding;
}


char* huffmanDecoding(char* str, treeP theTree, int len) {

	int codelen = strlen(str), index = 0;
	char* decoding = (char*)malloc(sizeof(char) * (len + 1));
	treeP diver = theTree;

	for (int i = 0; i < codelen; i++) {

		if (str[i] == '1') {
			diver = diver->right;
		}
		else if (str[i] == '0') {
			diver = diver->left;
		}

		if (diver->left == NULL && diver->right == NULL) {
			decoding[index] = diver->chr;
			diver = theTree;
			index++;
		}
	}
	decoding[len] = '\0';

	return decoding;
}