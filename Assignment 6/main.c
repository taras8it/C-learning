/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 6.2 – Simple calculator
 * Date: 02-10-2021
 *****************************************/
#include <stdio.h>


int read_int_input() {
    /**
     * Read a single integer input - the menu choice.
     * @return the value a user entered.
     */
    int scan_return, value;

    scan_return = scanf("%d", &value);

    // If no character matched the scanf mask
    while (scan_return == 0) {
        // Clear the buffer
        while (getchar() != '\n');

        printf("...You entered non-digit value.\n");
        printf("Print your choice again: ");

        // Scan a value again
        scan_return = scanf("%d", &value);
    }
    return value;
}


int read_input() {
    /**
     * Read and validate the input.
     * @return the value a user entered.
     */
    int input = read_int_input();

    // Checking the limits
    while (input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != 5) {
        printf("...The value must match the menu.\n");
        printf("Print your choice again: ");

        input = read_int_input();
    }

    return input;
}


double add(double a, double b) {
    return a + b;
}


double subtract(double a, double b) {
    return a - b;
}


double multiply(double a, double b) {
    return a * b;
}


double divide(double a, double b) {
    return a / b;
}


int modulus(int a, int b) {
    return a % b;
}


double read_operand(int i) {
    /**
     * Read a single double input - an operand.
     * @param int i - the number to print. 1 - first, 2 - second.
     * @return the value a user entered.
     */
    double scan_return, value;

    scan_return = scanf("%lf", &value);

    // If no character matched the scanf mask
    while (scan_return == 0) {
        // Clear the buffer
        while (getchar() != '\n');

        printf("...You entered non-digit value.\n");

        if (i == 1) {
            printf("Enter first operand again: ");
        } else if (i == 2) {
            printf("Enter second operand again: ");
        }

        // Scan a value again
        scan_return = scanf("%lf", &value);
    }
    return value;
}


void print_expression(double op1, double op2, char operator, double result) {
    /*
     * Print the result sentence.
     */
    printf("\nResult: %lf %c %lf = %lf\n\n", op1, operator, op2, result);
}


int main() {
    printf("MENU\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Modulus\n0. Exit\n\n");

    printf("Enter your choice: ");
    int choice = read_input();

    // Exit the program
    if (choice == 0) {
        return 0;
    }

    // Read operands
    printf("\nEnter first operand: ");
    double op1 = read_operand(1);
    printf("Enter second operand: ");
    double op2 = read_operand(2);

    switch (choice) {
        case 1:
            print_expression(op1, op2, '+', add(op1, op2));
            break;
        case 2:
            print_expression(op1, op2, '-', subtract(op1, op2));
            break;
        case 3:
            print_expression(op1, op2, '*', multiply(op1, op2));
            break;
        case 4:
            if (op2 == 0.0) {
                printf("Error: diving by zero.\n");
            } else {
                print_expression(op1, op2, '/', divide(op1, op2));
            }
            break;
        case 5:
            if (op2 == 0.0) {
                printf("Error: diving by zero.\n\n");
            } else {
                print_expression(op1, op2, '%', modulus((int) op1, (int) op2));
            }
            break;
    }

    return main();
}
