#include <stdio.h>
int main() {
    int m,n;
    scanf("%d %d", &m, &n);
    int matrix [m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", & matrix [i][j]);

        }
    }
    if ( m = n ) {
        printf("not a symmetric matrix")
        return 0;
    
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] = matrix [j][i]) {
                printf("not a symmetric matrix");
                return 0;

            }
        }
    }
    printf("symmetric matrix");
    return 0;
    
}