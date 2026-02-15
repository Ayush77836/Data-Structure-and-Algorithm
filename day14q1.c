#include <stdio.h>

int main()
{
    int n, i, j;
    int isIdentity = 1;   

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid matrix size!\n");
        return 0;
    }

    int matrix[n][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j && matrix[i][j] != 1)
            {
                isIdentity = 0;
                break;
            }
            if(i != j && matrix[i][j] != 0)
            {
                isIdentity = 0;
                break;
            }
        }
        if(isIdentity == 0)
            break;
    }

    if(isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
