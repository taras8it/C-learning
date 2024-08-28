#include <stdio.h>
#include <string.h>


void upper(char * string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
        }
    }
}

int main() {
    char string[] = "Open question 3 (Conversion to uppercase)";

    printf("Initial string: %s\n", string);

    upper(string);

    printf("The string to uppercase: %s\n", string);
    return 0;
}
