#include <stdio.h>
#include <stdlib.h>
long long int gcd(long long int a,long long int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    long long int n, a=2, b=2, d;
    scanf("%lld",&n);
    printf("----------------------------------------------------------------\n");
    printf("|                   a|                   b|                   d|\n");
    printf("----------------------------------------------------------------\n");
    while(1){
        a = (a*a + 1)%n;
        b = (b*b + 1)%n;
        b = (b*b + 1)%n;
        long long int tmp = (a-b)>0?(a-b):(b-a);
        d = gcd(tmp,n);
        printf("|%20lld|%20lld|%20lld|\n",a,b,d);
        printf("----------------------------------------------------------------\n");
        if(1<d && d<n){
            printf("Thua so khong tam thuong cua %lld la %lld",n,d);         
            break;
        }
        else if (d==n){
            printf("Khong tim thay");
            break;
        }
    }   
}