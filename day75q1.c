#include <stdio.h>

#define MAX 1000

int longestZeroSumSubarray(int arr[], int n) {
    int prefix_sum = 0;
    int max_len = 0;

    
    int sum[MAX];
    int index[MAX];

    int size = 0; 

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        
        if (prefix_sum == 0) {
            max_len = i + 1;
        }

        int found = 0;

        
        for (int j = 0; j < size; j++) {
            if (sum[j] == prefix_sum) {
                found = 1;
                int len = i - index[j];
                if (len > max_len) {
                    max_len = len;
                }
                break;
            }
        }

        
        if (!found) {
            sum[size] = prefix_sum;
            index[size] = i;
            size++;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", longestZeroSumSubarray(arr, n));

    return 0;
}
