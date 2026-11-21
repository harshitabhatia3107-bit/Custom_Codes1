#include <stdio.h>

long long abs_diff(long long a, long long b) {
    return (a > b) ? (a - b) : (b - a);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) {
        return 1;
    }

    long long arr[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &arr[i]) != 1) {
            return 1;
        }
    }

    long long min_diff = abs_diff(arr[0], arr[1]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = abs_diff(arr[i], arr[j]);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
    }

    printf("%lld\n", min_diff);
    return 0;
}