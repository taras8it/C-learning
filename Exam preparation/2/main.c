#define SIZE 10

#include <stdio.h>


double avg(const double * data, int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    return sum / size;
}

int main() {
    double data[SIZE] = {6.3, 8.4, 5.8, 8.3, 7.8, 6.7, 8.8, 6.4, 7.0, 8.2};

    double result = avg(data, SIZE);

    printf("The average: %.1lf", result);

    return 0;
}
