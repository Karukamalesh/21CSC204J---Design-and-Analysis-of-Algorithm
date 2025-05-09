#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the target element
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int arr[] = {2, 4, 5, 6, 8, 10, 12, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Element %d is present at index %d\n", target, result);
    } else {
        printf("Element %d is not present in the array\n", target);
    }

    return 0;
}
