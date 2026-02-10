#include <stdio.h>
#include <string.h>

int main() {
    char s[50];
    int i,j,flag = 1;
    scanf("%s", s);
    for (j = 0; s[j] != '\0'; j++) {
        i = 0;
        j = j - 1;
        while (i < j) {
            if (s[i] != s[j])
            flag = 0;
            break;

            
        }
        i++;
        j--;
     
    }
       if (flag == 1) 
        printf("yes");
        else
        printf("no");

       
       return 0;

}