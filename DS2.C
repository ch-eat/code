#include <stdio.h>
int stack[100];
int top = -1; // Initially, the stack is empty
int isFull() {
	return top == 99; // Since the array has a fixed size of 100
}
int isEmpty() {
	return top == -1;
}
void push(int value) {
	if (isFull()) {
		printf("Stack is full! Cannot push %d\n", value);
	} else {
		stack[++top] = value;
		printf("%d pushed onto stack.\n", value);
	}
}
void pop() {
	if (isEmpty()) {
		printf("Stack is empty! Cannot pop.\n");
	} else {
		printf("%d popped from stack.\n", stack[top--]);
	}
}
void display() {
	if (isEmpty()) {
		printf("Stack is empty!\n");
	} else {
		printf("Stack elements: ");
		for (int i = 0; i <= top; i++) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}
int main() {
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
			push(value);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
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