#include <stdio.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 20

void *producer(void *arg);
void *consumer(void *arg);

typedef struct {
    int buffer[BUFFER_SIZE];
    sem_t full, empty;
    int in, out;  // Indices for the buffer
} shared_data;

shared_data sh;

sem_t mutex;

int main() {
    pthread_t ptid1, ptid2, ctid1;
    sh.in = 0;
    sh.out = 0;
    sem_init(&sh.empty, 0, BUFFER_SIZE); // Initially, all slots are empty
    sem_init(&sh.full, 0, 0);            // Initially, no slots are filled
    sem_init(&mutex, 0, 1);              // Mutex for critical section

    // Create producer and consumer threads
    pthread_create(&ptid1, NULL, producer, NULL);
    pthread_create(&ptid2, NULL, producer, NULL);
    pthread_create(&ctid1, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(ptid1, NULL);
    pthread_join(ptid2, NULL);
    pthread_join(ctid1, NULL);

    return 0;
}

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100; // Produce a random item between 0 and 99
        sem_wait(&sh.empty);  // Wait for an empty slot
        sem_wait(&mutex);      // Lock the critical section

        // Insert item into buffer
        sh.buffer[sh.in] = item;
        printf("PRODUCER Thread id = %ld produced Item = %d at index %d\n", pthread_self(), item, sh.in);
        sh.in = (sh.in + 1) % BUFFER_SIZE; // Wrap around the index

        sem_post(&mutex);      // Unlock the critical section
        sem_post(&sh.full);    // Signal that a new item has been produced
        sleep(1);              // Simulate time taken to produce an item
    }
}

void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&sh.full);    // Wait for a filled slot
        sem_wait(&mutex);      // Lock the critical section

        // Remove item from buffer
        item = sh.buffer[sh.out];
        printf("\tCONSUMER Thread id = %ld consumed Item = %d from index %d\n", pthread_self(), item, sh.out);
        sh.out = (sh.out + 1) % BUFFER_SIZE; // Wrap around the index

        sem_post(&mutex);      // Unlock the critical section
        sem_post(&sh.empty);    // Signal that an item has been consumed
        sleep(2);              // Simulate time taken to consume an item
    }
}
	
