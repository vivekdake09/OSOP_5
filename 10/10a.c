
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a unique key
    key_t key = ftok("shmfile", 65); // Ensure "shmfile" exists in the directory
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a shared memory segment with a size of 1024 bytes
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the server's address space
    char *str = (char *) shmat(shmid, NULL, 0); // Corrected type to char*
    if (str == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Write Data: ");
    fgets(str, 100, stdin);  // Write data to shared memory

    // Detach the shared memory segment
    if (shmdt(str) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
