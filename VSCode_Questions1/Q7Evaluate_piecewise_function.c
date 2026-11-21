#include <stdio.h>

int main(void) {
    long long x;
    long long result;

    if (scanf("%lld", &x) != 1) {
        return 1; // Handle invalid or missing input
    }

    if (x < 0) {
        result = x * x + 2 * x + 1;
    } else if (x < 10) {
        result = 3 * x + 2;
    } else {
        result = 5 * x - 7;
    }

    printf("%lld\n", result);

    return 0;
}