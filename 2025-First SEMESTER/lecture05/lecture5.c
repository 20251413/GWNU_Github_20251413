#include <stdio.h>

int main() {
    if (1) {
        int i = 1, j;
        while (i <= 6) 
        {
            j = 0;
            while (j < i) 
            {
                printf("*");
                j++;
            }
            printf("\n");
            i++;
        }
    }
    return 0;
}