#include <stdio.h>
long long calculateArea(long long length, long long width) {
    return length * width;
}
int main() {
    long long length, width;
    if (scanf("%lld %lld", &length, &width) != 2) {
        return 1; 
    }
    long long area = calculateArea(length, width);
    printf("%lld\n", area);
    return 0;
}