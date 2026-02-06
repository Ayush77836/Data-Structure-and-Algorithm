#include <stdio.h>

int main() {
    int n, i;

    // Read number of elements
    scanf("%d", &n);

    int arr[n];

    // Read sorted array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // If array is empty, nothing to print
    if(n == 0) {
        return 0;
    }

    // Index for unique elements
    int j = 0;

    // Traverse the array
    for(i = 1; i < n; i++) {
        // If current element is different from last unique element
        if(arr[i] != arr[j]) {
            j++;              // move to next position
            arr[j] = arr[i];  // store unique element
        }
    }

    // Print unique elements
    for(i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
