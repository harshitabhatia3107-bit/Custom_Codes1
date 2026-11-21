#include <stdio.h>

int main(void) {
    long long n;

    if (scanf("%lld", &n) != 1) {
        return 1; // Handle invalid or missing input
    }

    int found = 0;

    for (long long a = 1; a <= n; a++) {
        long long c = a + 2;
        for (long long b = a + 1; b < n; b++) {
            long long sumSq = a * a + b * b;

            while (c <= n && c * c < sumSq) {
                c++;
            }

            if (c > n) {
                break; // Larger b will only produce larger c > n
            }

            if (c * c == sumSq) {
                printf("%lld %lld %lld\n", a, b, c);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("None\n");
    }

    return 0;
}