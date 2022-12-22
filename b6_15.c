#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
    long long int x = n - 1, s=0, r;
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
int testMiller_Rabin(long long int n, long long int t){
    long long int a=2, check=0;
    while(t-->0){
        int r = Miller_Rabin(a,n);
        if(r!=1)
            return 0;
        else 
            check = 1;
        a++;
    }
    if(check==1)
        return 1;
}
int isPrime(long long int n){
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long int i = 5; i <= sqrt(n); i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
long long int RANDOMSEARCH(long long int k, long long int t){
    long long int n, snt;
    long long int tmp = pow(2,k)-1;
    while(1){      
        n = 2 + rand()%(tmp+1-2);
        long long int B= 2 + rand()%(n+1-2);
        while (1){
            snt = 2 + rand()%(B+1-2);
            if(isPrime(snt)==1)
                break;
        }    
        while (n%snt==0 || n%2==0){
            n = 2 + rand()%(tmp+1-2);
            while (1){
                snt = 2 + rand()%(B+1-2);
                if(isPrime(snt)==1)
                    break;
            }
        }     
        if(testMiller_Rabin(n,t)==1)
            break;    
    }
    return n;
}
int main() {
    srand((int)time(0));
    long long int k, t,tmp;
    scanf("%lld%lld", &k, &t);
    printf("%lld ",RANDOMSEARCH(k,t));
    return 0;
}


