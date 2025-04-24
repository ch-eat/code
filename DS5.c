#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
int isEmpty(struct Node* top) {
	return top == NULL;
}
void push(struct Node** top, int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = *top;
	*top = newNode;
	printf("%d pushed onto the stack.\n", value);
}
void pop(struct Node** top) {
	if (isEmpty(*top)) {
		printf("Stack is empty! Cannot pop.\n");
	} else {
		struct Node* temp = *top;
		*top = (*top)->next;
		printf("%d popped from the stack.\n", temp->data);
		free(temp);
	}
}
void display(struct Node* top) {
	if (isEmpty(top)) {
		printf("Stack is empty!\n");
	} else {
		struct Node* temp = top;
		printf("Stack elements: ");
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
int main() {
	struct Node* top = NULL;
	int choice, value;
	while (1) {
		printf("\nStack Operations Menu:\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display Stack\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter value to push: ");
			scanf("%d", &value);
			push(&top, value);
			break;
		case 2:
			pop(&top);
			break;
		case 3:
			display(top);
			break;
		case 4:
			printf("Exiting program.\n");
			return 0;
		default:
			printf("Invalid choice! Please try again.\n");
		}
	}
	return 0;
}