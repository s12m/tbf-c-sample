#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#define MAX_NUMBER 1000000
#define THREADS_COUNT 4

bool is_prime_number(const unsigned int number) {
    if (number == 0 || number == 1) {
        return false;
    } else {
        for (unsigned int n = 2; n < number; n++) {
            if (number % n == 0) {
                return false;
            }
        }
        return true;
    }
}

void *find_prime_numbers(void *arg) {
    const unsigned int start_number = *((unsigned int *)arg);

    for (unsigned int n = start_number; n < MAX_NUMBER; n += THREADS_COUNT) {
        if (is_prime_number(n)) {
            printf("%u\n", n);
        }
    }
}

int main() {
    unsigned int start_numbers[THREADS_COUNT];
    pthread_t threads[THREADS_COUNT];
    for (size_t i = 0; i < THREADS_COUNT; i++) {
        start_numbers[i] = i + 1;
        pthread_create(&threads[i], NULL, find_prime_numbers, &start_numbers[i]);
    }

    for (size_t i = 0; i < THREADS_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
