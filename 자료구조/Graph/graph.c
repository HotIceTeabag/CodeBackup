#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"

void waypush(list** ways, nodeP dest, int dist) {	//포인터에 대한 포인터-> 함수 내에서 포인터 수정
	list* newway = (list*)malloc(sizeof(list));
	newway->next = NULL;
	newway->way = dest;
	newway->far = (rand() % 30) + 1;
	if (dist != 0)newway->far = dist;
	
	if (*ways == NULL)*ways = newway;
	else {
		List worker = *ways;
		while (worker->next != NULL) {
			worker = worker->next;
		}
		worker->next = newway;
	}
}

static void linkingNode(nodeP nodeA, nodeP nodeB, int dist, int* edgep) {
	if (dist == 0) dist = (rand() % 30) + 1;
	waypush(&nodeA->ways, nodeB, dist);
	waypush(&nodeB->ways, nodeA, dist);
	edgep[0] = nodeA->num;
	edgep[1] = nodeB->num;
	edgep[2] = dist;
}


static void nodepush(Graph* theGraph, int initial) {
	nodeP newnode = (nodeP)malloc(sizeof(node));
	newnode->num = initial;
	newnode->ways = NULL;
	newnode->next = NULL;

	if (*theGraph == NULL) {
		*theGraph = newnode;
		return;
	}

	nodeP worker = *theGraph;
	while (worker->next != NULL) { // 마지막 노드까지 순회
		worker = worker->next;
	}
	worker->next = newnode;
}

void makeGraph(Graph* theGraph, int node_count, int link_count, int** edgearr) {
	int i;
	if (node_count == 1) {
		nodepush(theGraph, 1);
		return;
	}

	for (i = 1; i <= node_count - 1; i += 2) {
		nodepush(theGraph, i);
		nodepush(theGraph, i + 1);
	}
	if (node_count % 2 == 1) {
		nodepush(theGraph, node_count);
	}

	int* edgep = *edgearr;
	int links = 0;
	while (links < link_count) {
		int numA, numB;
		do {
			numA = (rand() % node_count) + 1;
			numB = (rand() % node_count) + 1;
		}while(numA == numB);

		nodeP nodeA = *theGraph, nodeB = *theGraph;
		while (nodeA->num != numA) nodeA = nodeA->next;
		while (nodeB->num != numB) nodeB = nodeB->next;

		List ways = nodeA->ways;
		int is_connected = 0;

		while (ways != NULL) {
			if (ways->way == nodeB) {
				is_connected = 1;
				break;
			}
			ways = ways->next;
		}

		if (is_connected) continue;

		linkingNode(nodeA, nodeB, 0, edgep);
		edgep += 3;
		links++;
	}
}

void makeSampleGraph(Graph* theGraph, int* arr) {

	int arr[] = { 1, 2, 28, 2, 3, 16, 3, 4, 12, 4, 5, 22, 5, 6, 25, 
		6, 1, 10, 2, 7, 14, 4, 7, 18, 5, 7, 24 };

	for (int i = 1; i <= 7; i++) {
		nodepush(theGraph, i);
	}

	int* numa = arr, * numb = arr+1, * distp = arr+2;

	for (int i = 0; i < 9; i++) {
		nodeP nodeA = *theGraph, nodeB = *theGraph;
		while (nodeA->num != *numa) nodeA = nodeA->next;
		while (nodeB->num != *numb) nodeB = nodeB->next;

		linkingNode(nodeA, nodeB, *distp);

		numa += 3, numb += 3, distp += 3;
	}
}