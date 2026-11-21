#include <stdio.h>

int main(void) {
    int prev = EOF;
    long long count = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch == '\r') {
            continue; // Ignore Windows carriage return
        }

        if (ch == prev) {
            count++;
        } else {
            if (prev != EOF) {
                printf("%c%lld", prev, count);
            }
            prev = ch;
            count = 1;
        }
    }

    if (prev != EOF) {
        printf("%c%lld", prev, count);
    }
    putchar('\n');

    return 0;
}