#include <stdio.h>
#include <string.h>

// Function to reverse a string using stack
int main() {
    char str[100];       // Original string
    char stack[100];     // Stack for storing characters
    int i, top = -1;     // Stack top index

    // Input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Push each character of the string onto the stack
    for (i = 0; str[i] != '\0'; i++) {
        stack[++top] = str[i];  // Push character onto stack
    }

    // Pop characters from the stack and store them back in the string
    for (i = 0; top >= 0; i++) {
        str[i] = stack[top--];  // Pop character from stack
    }
    str[i] = '\0';  // Null-terminate the reversed string

    // Output the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
