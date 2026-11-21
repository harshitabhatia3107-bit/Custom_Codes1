#include <stdio.h>

int digitSum(long long x) {
    unsigned long long val = (x < 0) ? -(unsigned long long)x : (unsigned long long)x;
    int sum = 0;
    while (val > 0) {
        sum += (int)(val % 10);
        val /= 10;
    }
    return sum;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 1; // Handle invalid or missing input
    }

    if (n < 2) {
        printf("0\n");
        return 0;
    }

    // Maximum digit sum for a 64-bit integer (up to 19 digits) is 171
    long long freq[200] = {0};
    long long pairs = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        if (scanf("%lld", &x) != 1) {
            return 1;
        }
        int s = digitSum(x);
        pairs += freq[s];
        freq[s]++;
    }

    printf("%lld\n", pairs);

    return 0;
}