#ifndef TREE_H
#define TREE_H


typedef struct tree {
	int num;
	char chr;
	struct tree* left;
	struct tree* right;
}tree;

typedef struct {
	char chr;
	char code[256];
} pair;

typedef tree* treeP;

void huffmancoding();

void printTree(treeP root, int depth);
int dive(treeP theTree);

treeP leaf(int num, char chr);
char* inputstr();
treeP bind(treeP lft, treeP rht);
int ascendingTree(const void* a, const void* b);
pair* makeTable(treeP theTree, int count);

treeP huffman(treeP* treearr, int size);
char* huffmanEncoding(char* str, pair* table, int charcount);
char* huffmanDecoding(char* str, treeP theTree, int len);

#endif