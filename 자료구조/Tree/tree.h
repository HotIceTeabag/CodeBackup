#ifndef TREE_H
#define TREE_H

typedef struct Bintree {
	int num;
	char chr;
	struct tree* left;
	struct tree* right;
}tree;

typedef struct {
	char chr;
	char code[256];
} pair;

typedef struct Bintree* treeP;
typedef treeP Tree;

void huffmancoding();

void printTree(treeP root, int depth);
int dive(treeP theTree);

treeP leaf(int num, char chr);
char* inputstr();
treeP bind(treeP lft, treeP rht);
int ascendingTree(const void* a, const void* b);
pair* makeTable(treeP theTree, int count);

treeP huffmanE(treeP* treearr, int size);

#endif