#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
}Node;

Node* root = NULL;

Node* addNode(Node* parent, int data);
void initTree(int data);
void preOrder(Node* node);
void inOrder(Node* node);
void postOrder(Node* node);
void freeNode(Node* node);

int main()
{
	initTree(1);
	Node* L = addNode(root, 2);
	Node* R = addNode(root, 3);

	addNode(L, 4);
	addNode(L, 5);
	addNode(R, 6);
	addNode(R, 7);

	preOrder(root);

	freeNode(root);
}

Node* addNode(Node* parent, int data) {
	if ((parent->left != NULL) && (parent->right != NULL)) {
		printf("insert fail\n");
		return 0; // node is full
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	if (parent->left == NULL) {
		parent->left = newNode;
	}
	else if (parent->right == NULL) {
		parent->right = newNode;
	}

	return newNode;
}

void initTree(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	root = newNode;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
}

void preOrder(Node* node) {
	printf("%d ", node->data);
	if (node->left)preOrder(node->left);
	if (node->right)preOrder(node->right);
}

void inOrder(Node* node) {
	if (node != NULL) {
		inOrder(node->left);
		printf("%d ", node->data);
		inOrder(node->right);
	}
}

void postOrder(Node* node) {
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		printf("%d ", node->data);
	}
}

void freeNode(Node* node) { // have to start free in leaf node
	if (node != NULL) {
		freeNode(node->left);
		freeNode(node->right);
		free(node);
	}
}