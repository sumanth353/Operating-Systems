#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1)
        return 0; // Not prime
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return 0; // Not prime
    }
    return 1; // Prime
}

// Function to print prime numbers
void print_primes() {
    for (int i = 2; i <= 100; ++i) {
        if (is_prime(i))
            printf("%d ", i);
    }
    printf("\n");
}

// Function to generate Fibonacci series
void generate_fibonacci() {
    int first = 0, second = 1, next;

    printf("Fibonacci Series: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        generate_fibonacci();
    } else {
        // Parent process
        wait(NULL); // Wait for child process to finish
        print_primes();
    }

    return 0;
}

