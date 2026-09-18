#include <stdio.h>
#include <unistd.h>

static __inline__ unsigned long long rdtsc(void) {
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

int main() {
    unsigned long long start = rdtsc();
    getpid();
    unsigned long long end = rdtsc();
    printf("Cycles taken by getpid(): %llu\n", end - start);
    return 0;
}