#include <stdio.h>
#include <unistd.h>

static __inline__ unsigned long long rdtsc(void) {
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)lo) | (((unsigned long long)hi) << 32);
}

int main() {
    unsigned long long start = rdtsc();
    for (int i = 0; i < 100; i++) {
        getppid();
    }
    unsigned long long end = rdtsc();
    printf("Cycles taken for 100 getppid() calls: %llu\n", end - start);
    return 0;
}