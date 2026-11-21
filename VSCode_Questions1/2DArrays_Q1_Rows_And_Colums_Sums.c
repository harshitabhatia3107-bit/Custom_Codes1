#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2 || r < 0 || c < 0) {
        return 1;
    }

    if (r == 0 || c == 0) {
        printf("\n\n");
        return 0;
    }

    // Use calloc to zero-initialize column sums; long long prevents overflow
    long long *col_sums = calloc((size_t)c, sizeof(long long));
    if (col_sums == NULL) {
        return 1;
    }

    // Stream the matrix: compute and print row sums on the fly, accumulate column sums
    for (int i = 0; i < r; i++) {
        long long row_sum = 0;
        for (int j = 0; j < c; j++) {
            long long val;
            if (scanf("%lld", &val) != 1) {
                free(col_sums);
                return 1;
            }
            row_sum += val;
            col_sums[j] += val;
        }
        printf("%lld%c", row_sum, (i == r - 1) ? '\n' : ' ');
    }

    // Print column sums on the second line
    for (int j = 0; j < c; j++) {
        printf("%lld%c", col_sums[j], (j == c - 1) ? '\n' : ' ');
    }

    free(col_sums);
    return 0;
}