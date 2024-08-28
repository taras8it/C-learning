/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 3.1 – Rectangle
 * Date: 9-9-2021
 *****************************************/
#include <stdio.h>


void print_label(char t) {
    switch (t) {
        case 'h':
            printf("Enter the height [4-20]: ");
            break;
        case 'w':
            printf("Enter the width [4-20]: ");
            break;
        default:
            printf("Incorrect param.\n");
            break;
    }
}


int read_input(char t) {
    int scan_return, value;

    print_label(t);
    scan_return = scanf("%d", &value);

    while (scan_return == 0) {
        while (getchar() != '\n');

        printf("You entered non-digit value.\n");

        print_label(t);
        scan_return = scanf("%d", &value);

        if (scan_return == 0) continue;
    }

    return value;
}


int main() {

    int height = read_input('h');

    // Checking the limits
    while (height < 4 || height > 20) {
        printf("Not in range [4-20].\n");
        height = read_input('h');
    }

    int width = read_input('w');

    // Checking the limits
    while (width < 4 || width > 20) {
        printf("Not in range [4-20].\n");
        width = read_input('w');
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

