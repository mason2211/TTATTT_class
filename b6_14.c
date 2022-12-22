#include <stdio.h>
long long int mod(long long int a, long long int b, long long int c) {
    return ((a % c) * (b % c)) % c;
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
int Miller_Rabin(long long int a, long long int n) {
    long long int x = n - 1,s=0,r;
    while (x % 2 == 0) {
        s += 1;
        x /= 2;
    }
    r = x;
    long long int y = nhanBinhPhuongCoLap(a, r, n);
    if (y != 1 && y != n - 1) {
        int j = 1;
        while (j <= s - 1 && y != n - 1) {
            y = mod(y, y, n);
            if (y == 1) 
                return 0;
            j++;
        }
        if (y != n - 1) 
            return 0;
    }
    return 1;
}
int main() {
    long long int n, t, a = 2, check = 0;
    scanf("%lld%lld", &n, &t);
    printf("Kiem tra so nguyen n=%lld trong %lld lan:\n",n,t);
    while(a<t-1){
        int r = Miller_Rabin(a,n);
        if(r!=1){
            printf("Co so a=%d: Hop so\n",a);
            break;
        } 
        else {
            printf("Co so a=%d: Nguyen to\n",a);
            check = 1;
        }
        a++;
    }
    if(check==1)
        printf("%d co the la nguyen to",n);
    else printf("%d la hop so",n);
    return 0;
}

