#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

int main() {
    // Create the same key used by the server
    key_t key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get the shared memory segment created by the server
    int shmid = shmget(key, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the client's address space
    char *str = (char *) shmat(shmid, NULL, 0); // Corrected type to char*
    if (str == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Read data from shared memory
    printf("Data read from memory: %s\n", str);

    // Detach the shared memory segment
    if (shmdt(str) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Destroy the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}

