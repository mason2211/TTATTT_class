#include<stdio.h>
#include<math.h>
long long int mod(long long int x1, long long int p) {
    long long int k = x1 / p;
    if (x1 >= 0) {
        if (k == 0) {
            return x1;
        }
        else return x1 % p;
    }
    else {
        while (x1 < 0) {
            x1 += p;
        }
        return x1;
    }
}
void tinh(long long int p, long long int a) {
    long long int u = a, v = p;
    int x1 = 1, x2 = 0, x, q, r;
    while (u != 1) {
        q = v / u;
        r = v - q * u;
        x = x2 - q * x1;
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }
    printf("%lld^-1 mod %lld = %lld\n", a, p, mod(x1, p));
}
long long int gcd(long long int a, long long int b) {
    if (a == b)
        return 1;
    else if (b == 0)
        return a;
    else return gcd(b, a % b);
}
int main() {
    int x, x1, x2, q, v, u, r;
    long long int p, a;
    scanf("%lld%lld", &p, &a);
    printf("GCD(%lld,%lld) = %lld\n", p, a, gcd(p, a));
    if (gcd(p, a) == 1) {
        tinh(a, p);
        tinh(p, a);
    }
}
