#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long target;

    if (scanf("%d %lld", &n, &target) != 2) {
        return 1; // Handle invalid or missing input
    }

    if (n < 2) {
        // Consume any single remaining element if n == 1, then output 0
        printf("0\n");
        return 0;
    }

    long long *arr = malloc((size_t)n * sizeof(long long));
    if (arr == NULL) {
        return 1; // Handle allocation failure
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    long long count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                count++;
            }
        }
    }

    printf("%lld\n", count);

    free(arr);
    return 0;
}