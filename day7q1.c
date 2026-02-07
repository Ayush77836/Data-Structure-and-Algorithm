#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        // Recursive call
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    // Input
    scanf("%d", &n);

    // Output
    printf("%d", fib(n));

    return 0;
}
