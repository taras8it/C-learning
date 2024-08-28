/*******************************************************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 2.2 – Box capacity and total surface area calculation
 * Date: 05-09-20211
 *
 *******************************************************************************/
#include <stdio.h>

int main() {
    float length, width, height;

    printf("Enter length: ");
    scanf("%f", &length);

    printf("Enter width: ");
    scanf("%f", &width);

    printf("Enter height: ");
    scanf("%f", &height);

    float capacity = length * width * height;
    float surface = 2 * (length * width + length * height + width * height);

    printf("Capacity: %.2f\n", capacity);
    printf("Total outside surface area: %.2f", surface);

    return 0;
}
