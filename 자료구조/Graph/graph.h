#ifndef GRAPH_H
#define GRAPH_H

struct node;
typedef struct node* nodeP;

typedef struct list {
	nodeP way;				//이어진 노드에 대한 포인터(중복X)
	int far;
	struct list* next;
}list;

typedef struct list* List;

typedef struct node {
	int num;				//노드번호
	List ways;				//노드와 이어진 다른 노드의 포인터를 담은 리스트
	struct node* next;		//또다른 노드(관계X)
}node;
typedef nodeP Graph;

void makeGraph(Graph* theGraph, int node_count, int link_count, int** edgearr);
void makeSampleGraph(Graph* theGraph);

void primMST(Graph theGraph, int node_count);
#endif