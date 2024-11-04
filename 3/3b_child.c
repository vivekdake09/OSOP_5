#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void bubble_dsc(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nArray in descending order: ");
    for (i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No numbers provided.\n");
        return 1;
    }

    int n = argc - 1; // Number of integers
    int a[n];

    // Convert arguments to integers
    for (int i = 1; i <= n; i++) {
        a[i - 1] = atoi(argv[i]); // Store the integers in array
    }

    bubble_dsc(a, n); // Sort in descending order

    return 0;
}
