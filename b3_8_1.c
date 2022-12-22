#include <stdio.h>
#include <math.h>
long long int mod(long long int x1, long long int p) {
    if (x1 >= 0) return x1 % p;
    else return x1 + p;
}
long long int gcd(long long int a, long long int b) {
    if (a == b)
        return 1;
    else if (b == 0)
        return a;
    else return gcd(b, a % b);
}
int main() {
    long long int a, p, x, q, r;
    scanf("%lld%lld", &p, &a);
    long long int x1 = 1, x2 = 0, m = p, n = a;
    if (gcd(a, p) == 1) {
        while (n != 1) {
            q = m / n;
            r = m % n;
            x = x2 - q * x1;
            m = n; n = r; x2 = x1; x1 = x;
        }
    }
    printf("%lld^-1 mod %lld = %lld", a, p, mod(x1, p));
}
