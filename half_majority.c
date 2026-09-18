#include <stdio.h>

int findMajority(int arr[], int n) {
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    }

    return -1;
}

int main(void) {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements: \\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int majority = findMajority(arr, n);

    if (majority == -1) {
        printf("No majority element exists.\n");
    } else {
        printf("Majority element is: %d\n", majority);
    }

    return 0;
}