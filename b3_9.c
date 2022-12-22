#include <stdio.h>
#include <math.h>
long long int mod(long long int a, long long int b, long long int n){
    return ((a%n)*(b%n))%n;
}
long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n) {
    long long int b = 1, A = a;
    if (k % 2 == 1)
        b = a;
    k /= 2;
    while (k > 0) {
        A = mod(A, A, n);
        if (k % 2 == 1)
            b = mod(b, A, n);
        k /= 2;
    }
    return b;
}
int main(){
    long long int n, a, k;
    scanf("%lld%lld%lld", &n, &a, &k);
    printf("%lld^%lld mod %lld = %lld",a,k,n,nhanBinhPhuongCoLap(a,k,n));
    return 0;
}