#include <stdio.h>
#include <stdlib.h>

// Define the structure of a BST node
struct Node {
	int data;
	struct Node *left, *right;
};

// Function to create a new BST node
struct Node* createNode(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
	if (root == NULL)
		return createNode(value);
	if (value < root->data)
		root->left = insert(root->left, value);
	else if (value > root->data)
		root->right = insert(root->right, value);
	return root;
}

// Function for postorder traversal
void postorder(struct Node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int main() {
	struct Node* root = NULL;
	int values[] = {20, 36, 80, 20, 40, 60, 55};
	int n = sizeof(values) / sizeof(values[0]);

	for (int i = 0; i < n; i++) {
		root = insert(root, values[i]);
	}

	printf("Postorder Traversal: ");
	postorder(root);
	printf("\n");

	return 0;
}
