/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 3.1 – Rectangle
 * Date: 9-9-2021
 *****************************************/
#include <stdio.h>

int main() {
    int width = 0, height = 0;

    // Asking user for an input for height
    printf("Enter the height [4-20]: ");
    scanf("%d", &height);

    // Checking the limits
    while (height < 4 || height > 20) {
        printf("Not in range [4-20].\n");
        printf("Enter the height [4-20]: ");
        scanf("%d", &height);
    }

    // Asking user for an input for width
    printf("Enter the width [4-20]: ");
    scanf("%d", &width);

    // Checking the limits
    while (width < 4 || width > 20) {
        printf("Not in range [4-20].\n");
        printf("Enter the width [4-20]: ");
        scanf("%d", &width);
    }

    // Writing the first row
    for (int i = 0; i < width; i++) {
        printf("*");
    }

    printf("\n");

    // Writing the middle rows
    for (int i = 0; i < height - 2; i++) {
        printf("*");
        for (int j = 0; j < width - 2; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    // Writing the last row
    for (int i = 0; i < width; i++) {
        printf("*");
    }

    return 0;
}
