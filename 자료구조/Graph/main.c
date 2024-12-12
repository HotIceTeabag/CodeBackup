#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"


int main() {
	srand(time(NULL));

	Graph theGraph;

	int edge_count, node_count;
	int edges = 9, order;
	printf("Order: ");
	scanf_s("%d", &order);

	while (1) {
		printf("Order: ");
		scanf_s("%d", &order);
		if (order == 0)break;
		if (order == 1) {
			printf("number of nodes: ");
			scanf_s("%d", &node_count);

			printf("number of edges: ");
			scanf_s("%d", &edge_count);

			theGraph = NULL

			int (*edge_arr)[3] = (int(*)[3])malloc((edge_count) * sizeof(int[3]));
			makeGraph(theGraph, node_count, edge_count, edge_arr);

		}
		if (order == 2) {
			int edge_count, node_count;
			printf("number of nodes: 7\n");
			printf("number of edges: 9\n");

			theGraph = NULL;

			int (*edge_arr)[3] = (int(*)[3])malloc((edges) * sizeof(int[3]));

			int* ptr = edge_arr;
			makeSampleGraph(Graph * theGraph, int* arr)
		}
	}

	Graph theGraph = NULL;
	makeSampleGraph(&theGraph);


	primMST(theGraph, edges);




	return 0;
}
