#include <stdio.h>
long long countMultiples(long long n, long long k) {
    if (k <= 0 || n <= 0) {
        return 0;
    }
    return n / k;
}

int main() {
    long long n, k;
    if (scanf("%lld %lld", &n, &k) != 2) {
        return 1; 
    }
    long long result = countMultiples(n, k);
    printf("%lld\n", result);

    return 0;
}