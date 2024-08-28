/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 14.1 – Caesar’s cipher
 * Date: 3-12-2021
 *****************************************/
#include <stdio.h>
#include <string.h>


void decrypt(char * line, int shift) {
    char c;
    char * p;
    for (int i = 0; i < strlen(line); i++) {
        c = line[i];
        p = line + i;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c >= 'z' - shift + 1) {
                *p = c + shift - 26;
            } else {
                *p = c + shift;
            }
        } else {
            *p = c;
        }
    }
}


int main() {
    char ciphertext[] = "Qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald.";

    printf("The encrypted Caesar's cipher:\n%s\n\n", ciphertext);

    decrypt(ciphertext, 3);

    printf("Result after decryption:\n%s", ciphertext);

    return 0;
}
