#include <stdio.h>

void minMaxSubarray(int arr[], int n) {
    int minVal, maxVal;

    // Brute-force: Check every subarray
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            minVal = arr[start];
            maxVal = arr[start];
            // Find min and max in the subarray arr[start..end]
            for (int i = start + 1; i <= end; i++) {
                if (arr[i] < minVal) {
                    minVal = arr[i];
                }
                if (arr[i] > maxVal) {
                    maxVal = arr[i];
                }
            }
            printf("Subarray arr[%d..%d] has Min: %d and Max: %d\n", start, end, minVal, maxVal);
        }
    }
}

int main() {
    int arr[] = {2, 3, 1, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    minMaxSubarray(arr, n);
    
    return 0;
}
