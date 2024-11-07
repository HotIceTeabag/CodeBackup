#ifndef POLY_H
#define POLY_H

typedef struct poly* nodeP;
typedef nodeP polyList;


typedef struct poly {
	int dim;
	int val;
	nodeP next;
}poly;


#endif