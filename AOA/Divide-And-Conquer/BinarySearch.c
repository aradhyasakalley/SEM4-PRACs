#include <stdio.h>

int binarySearch(int arr[], int key, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array (sorted): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the number you want to search: ");
    scanf("%d", &key);
    int index = binarySearch(arr, key, 0, n - 1);
    if (index == -1) {
        printf("Element not found in array\n");
    } else {
        printf("Element found at index %d\n", index);
    }
    return 0;
}
