#include <stdio.h>
int isPerfectSquare(long long n) {
    if (n < 0) {
        return 0; 
    }
    if (n == 0 || n == 1) {
        return 1; 
    }

    long long left = 1;
    long long right = n / 2; 

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid == n / mid && n % mid == 0) {
            return 1; 
        } else if (mid < n / mid) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return 0;
}
int main() {
    long long n;
    if (scanf("%lld", &n) != 1) {
        return 1; 
    }
    printf("%d\n", isPerfectSquare(n));
    return 0;
}