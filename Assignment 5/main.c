/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 5.2 – Prime number search
 * Date: 24-9-2021
 *****************************************/
#include <stdio.h>
#include <math.h>

int read_int_input() {
    /**
     * Read a single input. The function validates it to be aa integer.
     * @return the value a user entered.
     */
    int scan_return, value;

    scan_return = scanf("%d", &value);

    // If no character matched the scanf mask
    while (scan_return == 0) {
        // Clear the buffer
        while (getchar() != '\n');

        printf("...You entered non-digit value.\n");
        printf("Enter the number again: ");

        // Scan a value again
        scan_return = scanf("%d", &value);
    }

    return value;
}


int read_input() {
    /**
     * Read and validate the input. The input must be > 0.
     * @return the value a user entered.
     */
    int input = read_int_input();

    // Checking the limits
    while (input < 0) {
        printf("...The value must be higher than zero.\n");
        printf("Enter the number again: ");

        input = read_int_input();
    }

    return input;
}


int is_prime(unsigned int n) {
    /*
     * Check if the number is prime.
     * @param int n - the number to check.
     */
    if (n == 1) {
        return 0;
    }

    // If the number is even and it is 2 - it is prime, otherwise - compound
    if (n % 2 == 0) {
        return n == 2;
    }

    // Iterating over odd numbers until the square root of the number
    for (int i = 3; i < sqrt(n) + 1; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void ten_prime(unsigned int n) {
    /*
     * Print the first 10 consecutive prime numbers
     * @param unsigned int n - the number to check
     */
    int counter = 0;
    int add = 1;

    while (counter < 10) {
        n += add;

        if (is_prime(n)) {
            printf("%d ", n);
            add = 2;
            counter++;
        }
    }
}

int main() {
    printf("Enter the number: ");
    int input = read_input();

    ten_prime(input);

    return 0;
}
