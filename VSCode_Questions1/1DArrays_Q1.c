#include <stdio.h>
#include <stdlib.h>

int longestIncreasingRun(const long long *arr, int n) {
    if (n <= 0) {
        return 0;
    }

    int maxLen = 1;
    int curLen = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            curLen++;
            if (curLen > maxLen) {
                maxLen = curLen;
            }
        } else {
            curLen = 1;
        }
    }

    return maxLen;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    long long *arr = malloc((size_t)n * sizeof(long long));
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    printf("%d\n", longestIncreasingRun(arr, n));

    free(arr);
    return 0;
}