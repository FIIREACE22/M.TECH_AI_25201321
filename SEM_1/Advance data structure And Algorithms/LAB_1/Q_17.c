//Fibonacci Series using Recursion

#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series (using recursion):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }

    printf("\n");
    return 0;
}
