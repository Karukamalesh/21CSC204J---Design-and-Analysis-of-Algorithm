#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void insertMinHeap(int arr[], int *n, int key) {
    (*n)++;
    arr[*n - 1] = key;
    int i = *n - 1;

    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(int arr[], int *n) {
    if (*n <= 0)
        return -1;

    if (*n == 1) {
        (*n)--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;

    heapify(arr, *n, 0);

    return root;
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMinHeap(arr, n);

    printf("Extracted Min: %d\n", extractMin(arr, &n));
    insertMinHeap(arr, &n, 4);
    printf("Extracted Min after insertion: %d\n", extractMin(arr, &n));

    return 0;
}
