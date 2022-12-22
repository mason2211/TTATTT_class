#include <stdio.h>
#include <math.h>
long long int gcd(long long int a, long long int b) {
    if (a==b)
        return 1;
    else if (b == 0)
        return a;
    else return gcd(b, a % b);
}
int main() {
    long long int x, y, t;
    scanf("%lld", &t);
    while (t-- > 0){
        scanf("%lld%lld", &x, &y);
        printf("GCD(a,b) = %lld\n", gcd(x, y));
    }
}
