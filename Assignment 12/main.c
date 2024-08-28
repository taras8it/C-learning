/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 12.1 – Value rotation
 * Date: 25-11-2021
 *****************************************/
#include <stdio.h>


void read_input(int * a, int * b, int * c) {
    printf("Enter the first value: ");
    scanf("%d", a);

    printf("Enter the second value: ");
    scanf("%d", b);

    printf("Enter the third value: ");
    scanf("%d", c);
}


void swap(int * a, int * b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


void swap_value(int * a, int * b, int * c) {
    swap(a, b);
    swap(a, c);
}


void print_values(const int a, const int b, const int c) {
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
}


int main() {
    int a, b, c;

    read_input(&a, &b, &c);

    printf("Your values:\n");
    print_values(a, b, c);

    swap_value(&a, &b, &c);

    printf("Swapped values:\n");
    print_values(a, b, c);

    return 0;
}
