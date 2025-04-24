#include <stdio.h>

int main() {
    int list[100], stack[100];
    int n, i, top = -1;

    // Input list size
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Input list elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    // Push each element of the list onto the stack
    for (i = 0; i < n; i++) {
        stack[++top] = list[i];
    }

    // Pop elements from the stack back into the list (reverses the list)
    for (i = 0; i < n; i++) {
        list[i] = stack[top--];
    }

    // Output the reversed list
    printf("Reversed list: ");
    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
