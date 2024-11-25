#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

treeP leaf(int num, char chr) {
	treeP newleaf = (treeP)malloc(sizeof(tree) * 1);
	newleaf->chr = chr;
	newleaf->num = num;

	newleaf->left = NULL;
	newleaf->right = NULL;

	return newleaf;
}


void insertree(int alpha, int beta) {

}

int dive(treeP theTree) {
    if (theTree == NULL) return 0;

    int leftDepth = dive(theTree->left);
    int rightDepth = dive(theTree->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}


void printTree(treeP root, int depth) {
	if (root == NULL) return;

	for (int i = 0; i < depth; i++) printf("  ");
	if (root->chr != '\0') {
		printf("'%c' (%d)\n", root->chr, root->num);
	}
	else {
		printf("* (%d)\n", root->num);
	}

	printTree(root->left, depth + 1);
	printTree(root->right, depth + 1);
}