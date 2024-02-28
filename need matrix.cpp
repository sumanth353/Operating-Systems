#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

void calculateNeed(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int main() {
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {1, 1, 2},
        {2, 1, 2},
        {3, 0, 1},
        {0, 2, 0},
        {1, 1, 2}
    };

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {5, 4, 4},
        {4, 3, 3},
        {9, 1, 3},
        {8, 6, 4},
        {2, 2, 3}
    };

    int available[MAX_RESOURCES] = {3, 2, 1};

    int need[MAX_PROCESSES][MAX_RESOURCES];

    int numProcesses = sizeof(allocation) / sizeof(allocation[0]);
    int numResources = sizeof(available) / sizeof(available[0]);

    calculateNeed(need, max, allocation, numProcesses, numResources);

    // Printing the Need Matrix
    printf("Need Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d:\t", i);
        for (int j = 0; j < numResources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }


}
