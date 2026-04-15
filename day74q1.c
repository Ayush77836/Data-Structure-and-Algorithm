#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char arr[n][50];  

    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    int max_votes = 0;
    char winner[50];

    for(int i = 0; i < n; i++) {
        int count = 1;

        for(int j = i + 1; j < n; j++) {
            if(strcmp(arr[i], arr[j]) == 0) {
                count++;
            }
        }

        if(count > max_votes) {
            max_votes = count;
            strcpy(winner, arr[i]);
        }
        else if(count == max_votes) {
            if(strcmp(arr[i], winner) < 0) {
                strcpy(winner, arr[i]);
            }
        }
    }

    printf("%s %d\n", winner, max_votes);

    return 0;
}