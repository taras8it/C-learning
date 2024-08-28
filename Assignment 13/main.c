/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 13.1 – Grade administration system
 * Date: 3-12-2021
 *****************************************/
#define SIZE 10

#include <stdio.h>


double read_double_input(int i) {
    /**
     * Read a single input. The function validates it to be a double.
     * @param int i - the student's number to be printed in a prompt.
     * @return the value a user entered.
     */
    double scan_return, value;

    scan_return = scanf("%lf", &value);

    // If no character matched the scanf mask
    while (scan_return == 0) {
        // Clear the buffer
        while (getchar() != '\n');

        printf("...You entered non-digit value.\n");
        printf("Print the grade for the student №%d again: ", i + 1);

        // Scan a value again
        scan_return = scanf("%lf", &value);
    }

    return value;
}


double read_input(int i) {
    /**
     * Read and validate the input. The input must be >= 1 and <= 10.
     * @param int i - the student's number to be printed in a prompt.
     * @return the value a user entered.
     */
    double input = read_double_input(i);

    // Checking the limits
    while (input < 1.0 || input > 10.0) {
        printf("...The value is not in the range 1.0-10.0.\n");
        printf("Print the grade for the student №%d again: ", i + 1);

        input = read_double_input(i);
    }

    return input;
}


int dialog_again() {
    /**
     * Make a console dialog with a user if he wants to enter the grades again.
     * "y" for yes, "n" for no. If input doesn't match, it asks for the input again.
     * @return 0 for quit, 1 for entering the grades again.
     */
    printf("Do you want to enter the grades again? [y/n] ");

    char resp;
    scanf(" %c", &resp);

    if (resp == 'y') {
        return 1;
    } else if (resp == 'n'){
        return 0;
    } else {
        printf("Please enter your response [y/n]. ");
        return dialog_again();
    }
}


int dialog_correct() {
    /**
     * Make a console dialog with a user if he entered the grades correctly.
     * "y" for yes, "n" for no. If input doesn't match, it asks for the input again.
     * @return 2 for continuation of the main program. Also returns the value of dialog_correct.
     */
    printf("Is everything correct? [y/n] ");

    char resp;
    scanf(" %c", &resp);

    if (resp == 'y') {
        return 2;
    } else if (resp == 'n'){
        return dialog_again();
    } else {
        printf("Please enter your response [y/n]. ");
        return dialog_correct();
    }
}


double count_average(const double *data, int size) {
    /**
     * Count the average for the array.
     * @param const double *data - the array of values.
     * @param int size - the size of the array.
     * @return the average value of the array.
     */
    double avg = 0;

    for (int i = 0; i < size; i++) {
        avg += data[i];
    }

    avg = avg / size;

    return avg;
}


int count_pass(const double *data, int size) {
    /**
     * Count the number of students who got a passing mark (>=5.5).
     * @param const double *data - the array of values.
     * @param int size - the size of the array.
     * @return the number of elements >= 5.5.
     */
    int number = 0;

    for (int i = 0; i < size; i++) {
        if (data[i] >= 5.5) {
            number++;
        }
    }

    return number;
}


void store_grades(double * grades, int size) {
    /*
     * Stores the grades entered by the user.
     */
    double input;

    for (int i = 0; i < size; i++) {
        printf("Print the grade for the student №%d: ", i + 1);
        input = read_input(i);
        *(grades + i) = input;
    }
}

void print_grades(double * grades, int size) {
    /*
     * Prints all grades.
     */
    for (int i = 0; i < size; i++) {
        printf("The grade you have entered for the student №%d: %.1lf\n", i+1, grades[i]);
    }
}


void print_everything(double * grades, int size) {
    /*
     * Prints all the results (all grades, the average and the number of students that have passed) to the console
     */
    print_grades(grades, size);

    // Print the average value of the array
    double avg = count_average(grades, size);
    printf("The average grade of the class: %.1lf.\n", avg);

    // Print the number of students who passed
    int number = count_pass(grades, size);
    printf("The number of students that passed: %d.\n", number);
}


int main() {
    /**
     * The main function.
     */
    double grades[SIZE];

    store_grades(grades, SIZE);

    // Print all grades
    printf("Check if the printed marks are correct:\n");
    print_grades(grades, SIZE);

    // Ask if the user entered them correctly
    int res = dialog_correct();

    if (res == 0) {
        // Quit the program
        printf("...Quit");
        return 0;
    } else if (res == 1) {
        // Start the program again
        printf("Enter the grades again.\n");
        return main();
    } else if (res == 2) {
        print_everything(grades, SIZE);
    }

    return 0;
}
