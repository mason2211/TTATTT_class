#include <stdio.h>
#include <math.h>
int isPrime(long long int n){
    if(n<2)
        return 0;
    if(n<=3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    for(long long int i=5;i<=sqrt(n);i+=6){
        if(n%i==0 || n%(i+2)==0)      
            return 0;
    }
    return 1;
}
int main(){
    long long int n;
    scanf("%lld",&n);
    if(isPrime(n)==1)
        printf("%lld la so nguyen to",n);
    else printf("%lld khong la so nguyen to",n);
}