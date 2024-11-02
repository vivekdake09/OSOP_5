#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void bubble_asc(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nArray in ascending order: ");
    for (i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide numbers to sort.\n");
        return 1;
    }

    int n = argc - 1; // Number of integers provided
    int a[n];
    pid_t pid;

    // Convert arguments to integers
    for (int i = 1; i <= n; i++) {
        a[i - 1] = atoi(argv[i]); // Store the integers in array
    }

    bubble_asc(a, n); // Sort in ascending order

    // Prepare arguments for child process
    char *args[n + 2]; // +2 for program name and NULL termination
    args[0] = "./child"; // Assume the child executable is named "child"
    for (int i = 0; i < n; i++) {
        args[i + 1] = argv[i + 1]; // Pass sorted values
    }
    args[n + 1] = NULL; // NULL terminate the argument list

    pid = fork();
    if (pid == 0) { // Child process
        printf("\nI am Child Process, my pid is %d \n", getpid());
        execve("./child", args, NULL); // Execute child program
        perror("execve failed"); // Only reached if execve fails
        exit(1);
    } else if (pid > 0) { // Parent process
        wait(NULL); // Wait for child process to finish
        printf("\nI am Parent Process, my pid is %d \n", getpid());
    } else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}
