#include <stdio.h>
#include <limits.h>

int minimum(int a, int b) {
    return (a < b ? a : b);
}

int maximum(int a, int b) {
    return (a > b ? a : b);
}

void minMax(int arr[], int n, int low, int high, int *min, int *max) {
    if (low == high) {
        *min = *max = arr[low];
    } else if (low == high + 1) {
        if (arr[low] > arr[high]) {
            *min = arr[high];
            *max = arr[low];
        } else {
            *min = arr[low];
            *max = arr[high];
        }
    } else {
        int mid = (low + high) / 2;
        int min1, min2, max1, max2;
        minMax(arr, n, low, mid, &min1, &max1);
        minMax(arr, n, mid + 1, high, &min2, &max2);
        *min = minimum(min1, min2);
        *max = maximum(max1, max2);
    }
}

int main() {
    int n, i, min = INT_MAX, max = INT_MIN;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    minMax(arr, n, 0, n - 1, &min, &max);
    printf("The minimum and maximum elements are %d and %d, respectively.", min, max);
    return 0;
}
