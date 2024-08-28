#include <stdio.h>

#define ARRAY_SIZE 5


void selection_sort(int *data, int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i; j < size; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }

        // Swap
        if (i != min) {
            data[i] = data[i] - data[min];
            data[min] = data[i] + data[min];
            data[i] = data[min] - data[i];
        }
    }
}


void bubble_sort(int * data, const int size) {
    for (int j = 0; j < size - 1; j++) {
        for (int i = 0; i < size - 1; i++) {
            if (data[i] > data[i + 1]) {
                // Swap
                data[i] = data[i] - data[i + 1];
                data[i + 1] = data[i] + data[i + 1];
                data[i] = data[i + 1] - data[i];
            }
            for (int k = 0; k < size; k++) {
                printf("%d ", data[k]);
            }
            printf("\n");
        }
    }
}


void heapify(int * data, const int size, const int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && data[largest] < data[l]) {
        largest = l;
    }
    if (r < size && data[largest] < data[r]) {
        largest = r;
    }

    if (largest != i) {
        data[i] = data[i] - data[largest];
        data[largest] = data[i] + data[largest];
        data[i] = data[largest] - data[i];

        heapify(data, size, largest);
    }
}


void heap_sort(int * data, const int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(data, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        data[i] = data[i] - data[0];
        data[0] = data[i] + data[0];
        data[i] = data[0] - data[i];

        heapify(data, i, 0);
    }
}


int main() {
    int values[ARRAY_SIZE] = {9, -5, 3, -2, 0};

    heap_sort(values, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", values[i]);
    }
}
