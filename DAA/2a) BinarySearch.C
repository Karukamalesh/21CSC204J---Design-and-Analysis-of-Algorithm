#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;  // Element found at index mid
        }
        
        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    return -1;  // Return -1 if the element is not found
}

int main() {
    int arr[] = {2, 4, 5, 6, 8, 10, 12, 15, 20};  // Array must be sorted
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element %d is present at index %d\n", target, result);
    } else {
        printf("Element %d is not present in the array\n", target);
    }

    return 0;
}
