#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Deque {
	struct Node* front;
	struct Node* rear;
};
void initDeque(struct Deque* deque) {
	deque->front = deque->rear = NULL;
}
void insertFront(struct Deque* deque, int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = deque->front;
	newNode->prev = NULL;
	if (deque->front) deque->front->prev = newNode;
	deque->front = newNode;
	if (!deque->rear) deque->rear = newNode;
}
void insertRear(struct Deque* deque, int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = deque->rear;
	if (deque->rear) deque->rear->next = newNode;
	deque->rear = newNode;
	if (!deque->front) deque->front = newNode;
}
int deleteFront(struct Deque* deque) {
	if (!deque->front) {
		printf("Deque is empty!\n");
		return -1;
	}
	struct Node* temp = deque->front;
	int value = temp->data;
	deque->front = deque->front->next;
	if (deque->front) deque->front->prev = NULL;
	else deque->rear = NULL;
	free(temp);
	return value;
}
int deleteRear(struct Deque* deque) {
	if (!deque->rear) {
		printf("Deque is empty!\n");
		return -1;
	}
	struct Node* temp = deque->rear;
	int value = temp->data;
	deque->rear = deque->rear->prev;
	if (deque->rear) deque->rear->next = NULL;
	else deque->front = NULL;
	free(temp);
	return value;
}
void displayDeque(struct Deque* deque) {
	struct Node* temp = deque->front;
	printf("Deque: ");
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	struct Deque deque;
	initDeque(&deque);
	insertFront(&deque, 10);
	insertRear(&deque, 20);
	insertFront(&deque, 5);
	insertRear(&deque, 30);
	displayDeque(&deque);
	printf("Deleted from front: %d\n", deleteFront(&deque));
	displayDeque(&deque);
	printf("Deleted from rear: %d\n", deleteRear(&deque));
	displayDeque(&deque);
	return 0;
}