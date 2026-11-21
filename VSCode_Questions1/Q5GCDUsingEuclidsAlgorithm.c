#include <stdio.h>

static unsigned long long safe_abs(long long x) {
    return (x < 0) ? (0ULL - (unsigned long long)x) : (unsigned long long)x;
}

unsigned long long gcd(long long a, long long b) {
    unsigned long long x = safe_abs(a);
    unsigned long long y = safe_abs(b);

    while (y != 0) {
        unsigned long long rem = x % y;
        x = y;
        y = rem;
    }
    return x;
}

int main(void) {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) != 2) {
        return 1;
    }

    printf("%llu\n", gcd(a, b));
    return 0;
}