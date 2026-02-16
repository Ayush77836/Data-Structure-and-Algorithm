#include <stdio.h>

int main()
{
    int n, i, j;
    
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    int visited[n];   // to mark counted elements

    // Initialize visited array to 0
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // Input array elements
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for(i = 0; i < n; i++)
    {
        if(visited[i] == 1)
            continue;

        int count = 1;

        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;   // mark as counted
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
