#include <stdio.h>
#include <pthread.h>
#define MAX_NUM 20
void *printEven(void *args) {
    for (int i = 2; i <= MAX_NUM; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}
void *printOdd(void *args) {
    for (int i = 1; i <= MAX_NUM; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t evenThread, oddThread;
    pthread_create(&evenThread, NULL, printEven, NULL);
    pthread_create(&oddThread, NULL, printOdd, NULL);
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    return 0;
}

