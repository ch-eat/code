#include <stdio.h>
#include <stdlib.h>

// Stack node structure
struct Stack {
    int data;
    struct Stack* next;
};

// Push function
void push(struct Stack** top, int value) {
    struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = *top;
    *top = new_node;
}

// Pop function
int pop(struct Stack** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Stack* temp = *top;
    int popped_value = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped_value;
}

// Evaluate postfix expression
int evaluate_postfix(char* expression) {
    struct Stack* stack = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (c >= '0' && c <= '9') {
            push(&stack, c - '0');  // Convert char to int
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}

// Main function
int main() {
    char postfix[100];
    printf("Enter a postfix expression (e.g. 23*54*+9-): ");
    scanf("%s", postfix);

    int result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
