/******************************************************************************
 *                                                                            *
 *   Author: Oleksandr Kuprii 510190                                          *
 *   Description: Assignment 16 - Birthday Calendar                           *
 *   Date: 8-1-2022                                                           *
 *                                                                            *
 *****************************************************************************/
#define NAME_LENGTH 30
#define LIST_LENGTH 100

#include <stdio.h>
#include <string.h>


typedef enum
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

typedef struct
{
    int day;
    Month month;
    int year;
} DateOfBirth;

typedef struct
{
    char name[NAME_LENGTH + 1];
    DateOfBirth dateOfBirth;
} Person;


void enter_string(char * s, int sizeof_s) {
    if (fgets(s, sizeof_s, stdin) != NULL)
    {
        char * newline;
        if ((newline = strchr(s, '\n')) != NULL)
        {
            *newline = '\0';
        }
        else
        {
            // no newline found
            // this means the input was larger than the string size
            // flush the buffer
            char c;
            while((c = getchar()) != '\n' && c != EOF);
        }
    }
}

int enter_integer(void) {
    int input_integer;
    int conversions;
    do
    {
        conversions = scanf("%d", &input_integer);
        // flush the buffer
        char c;
        while((c = getchar()) != '\n' && c != EOF);
    }
    while (conversions != 1);
    return input_integer;
}

Person enter_person() {
    Person person;

    printf("Name: ");
    enter_string(person.name, NAME_LENGTH + 1);

    printf("Day: ");
    person.dateOfBirth.day = enter_integer();
    printf("Month: ");
    person.dateOfBirth.month = enter_integer();
    printf("Year: ");
    person.dateOfBirth.year = enter_integer();

    return person;
}

char * month_to_string(int month) {
    switch (month) {
        case JANUARY:
            return "January";
        case FEBRUARY:
            return "February";
        case MARCH:
            return "March";
        case APRIL:
            return "April";
        case MAY:
            return "May";
        case JUNE:
            return "June";
        case JULY:
            return "July";
        case AUGUST:
            return "August";
        case SEPTEMBER:
            return "September";
        case OCTOBER:
            return "October";
        case NOVEMBER:
            return "November";
        case DECEMBER:
            return "December";
        default:
            return "Undefined";
    }
}

void print_person(Person person) {
    printf("%s  %d %s %d\n", person.name, person.dateOfBirth.day,
           month_to_string(person.dateOfBirth.month),person.dateOfBirth.year);
}

void print_list(Person * person, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d. ", i + 1);
        print_person(person[i]);
    }
}

void print_menu() {
    printf("MENU\n"
           "1: Enter a person\n"
           "2: Display all birth dates\n"
           "3: Display the youngest person\n"
           "4: Display birthdays in a month\n"
           "0: Quit\n");
}

Person find_the_youngest_person(Person * people, int length) {
    Person youngest = {"", {0,0,0}};

    for (int i = 0; i < length; i++) {
        if (people[i].dateOfBirth.year > youngest.dateOfBirth.year) {
            youngest = people[i];
        } else if (people[i].dateOfBirth.year == youngest.dateOfBirth.year) {
            if (people[i].dateOfBirth.month > youngest.dateOfBirth.month) {
                youngest = people[i];
            } else if (people[i].dateOfBirth.month == youngest.dateOfBirth.month) {
                if (people[i].dateOfBirth.day > youngest.dateOfBirth.day) {
                    youngest = people[i];
                }
            }
        }
    }

    return youngest;
}

void print_people_in_month(Person * people, int length, int month) {
    Person people_in_month[LIST_LENGTH];
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (people[i].dateOfBirth.month == month) {
            people_in_month[count] = people[i];
            count++;
        }
    }

    printf("\nPeople born in %s:\n", month_to_string(month));

    print_list(people_in_month, count);
}


int main() {
    Person list[LIST_LENGTH];
    int number_of_people = 0;

    int choice;

    while (1) {
        printf("\n");

        print_menu();
        printf("Type command: ");
        choice = enter_integer();

        printf("\n");

        switch (choice) {
            case 0:
                return 0;
            case 1:
                printf("Add new person:\n");
                list[number_of_people] = enter_person();
                number_of_people++;
                printf("You added a new person.\n");
                break;
            case 2:
                printf("Your list:\n");
                print_list(list, number_of_people);
                break;
            case 3:
                printf("The youngest person:\n");
                print_person(find_the_youngest_person(list, number_of_people));
                break;
            case 4:
                printf("Birthdays in a month:\n"
                       "Print month (1-12): ");
                int month = enter_integer();

                print_people_in_month(list, number_of_people, month);
                break;
            default:
                printf("Unknown command. Try again.\n");
                break;
        }
    }
}
