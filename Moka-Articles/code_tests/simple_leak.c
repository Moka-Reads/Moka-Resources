#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *num = (int *)malloc(sizeof(int));

    if (num == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Assign a value to the integer
    *num = 42;

    // Simulate some operations with the allocated memory
    // ...

    // Forget to free the allocated memory
    // free(num);

    return 0;
}