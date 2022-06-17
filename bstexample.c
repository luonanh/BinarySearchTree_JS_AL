#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _treenode {
	int val;
	struct _treenode* left;
	struct _treenode* right;
} treenode;

treenode* createnode(int val)
{
	treenode* result = malloc(sizeof(treenode));
	if (result != NULL) {
		result->val = val;
		result->left = NULL;
		result->right = NULL;
	}
	return result;
}

void printtabs(int numtabs)
{
	for (int i = 0; i < numtabs; i++) {
		printf("\t");
	}
}

void printtree_rec(treenode* root, int level)
{
	printtabs(level);
	if (root == NULL) {
		printf("Nothing\n");
		return;
	}

	printf("%d\n", root->val);

	printtabs(level);
	printf("left\n");
	printtree_rec(root->left, level + 1);

	printtabs(level);
	printf("right\n");
	printtree_rec(root->right, level + 1);

	printtabs(level);
	printf("done\n");
}

void printtree(treenode* root)
{
	printtree_rec(root, 0);
}

bool insertnumber(treenode** rootptr, int val)
{
	treenode* root = *rootptr;
	if (root == NULL) {
		*rootptr = createnode(val);
		return true;
	}

	if (val == root->val) {
		return false;
	}

	if (val < root->val) {
		return insertnumber(&(root->left), val);
	}
	else {
		return insertnumber(&(root->right), val);
	}
}

bool findnumber(treenode* root, int val)
{
	if (root == NULL) return false;

	if (val == root->val)
		return true;

	if (val < root->val)
		return findnumber(root->left, val);
	else
		return findnumber(root->right, val);
}

int main()
{
	treenode* root = NULL;
	insertnumber(&root, 15);
	insertnumber(&root, 11);
	insertnumber(&root, 24);
	insertnumber(&root, 5);
	insertnumber(&root, 19);
	insertnumber(&root, 16);

	printtree(root);

	printf("%d (%d)\n", 16, findnumber(root, 16));
	printf("%d (%d)\n", 15, findnumber(root, 15));
	printf("%d (%d)\n", 5, findnumber(root, 5));
	printf("%d (%d)\n", 115, findnumber(root, 115));
	printf("%d (%d)\n", 1, findnumber(root, 1));
	printf("%d (%d)\n", 7, findnumber(root, 7));

	return 0;
}
