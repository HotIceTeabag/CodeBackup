#ifndef POLY_H
#define POLY_H

typedef struct poly* nodeP;
typedef nodeP polyList;


typedef struct poly {
	int dim;
	int val;
	nodeP next;
}poly;

void insert(nodeP* sPtr, int dimm, int vall);
void prt_poly(polyList p);
void add_poly(nodeP* sPtr, polyList p1, polyList p2);
void free_list(polyList list);
#endif