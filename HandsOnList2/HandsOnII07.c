#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Thread ID: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}