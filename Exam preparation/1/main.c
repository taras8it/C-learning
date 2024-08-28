#include <stdio.h>


void swap(float * a, float * b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float a = (float) 1.5;
    float b = (float) 2.3;

    printf("Initial values: a = %.1f, b = %.1f\n", a, b);

    swap(&a, &b);

    printf("Values after swapping: a = %.1f, b = %.1f\n", a, b);

    return 0;
}
