#include <stdio.h>
#include <math.h>
int check[100000];
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
void Eratosthenes(long long int n){
    for(int i = 2 ; i <= n ; i++){
        check[i]=1;
    }
    for(int i = 2; i <= n; i++){
        if(check[i]==1){
            for(int j = 2*i; j<=n; j+=i){
                check[j]=0;
            }
        }
    }
}
void phanDoan(long long int n){
    long long int bot, top, delta=5,d,m,dem=1,x=1;
    bot = delta+2;    top = bot+delta-1;    d =delta+1;
    Eratosthenes(d);
    while(bot<=n && top <=n){
        dem++;
        m = sqrt(top);
        for(int i = 2 ; i <= top ; i++){
            if(check[i]==1 && i<=m){
                for(int j = bot ; j <= top ;j++){
                    if(check[j]==1){
                        for(int h = 2*i ; h <= top ;h+=i){
                            if(j==h){
                                check[j]=0;
                            }
                        }
                        }}}}
        top+=delta; bot+=delta;
        if(top>n){
            top=n;
        }
    }
}
void in(long long int n){
    for(int i = 2 ; i<=n; i++){
        if(check[i]==1){
            printf("%d ",i);
        }
    }
}
int main(){
    long long int n;
    scanf("%lld",&n);
    printf("Cach thong thuong: ");
    for(long long int i=2;i<=n;i++){
        if(isPrime(i)==1)
            printf("%lld ",i);
    }
    printf("\nSang Eratosthenes: ");
    Eratosthenes(n);
    in(n);
    printf("\nSang phan doan:    ");
    in(n);
    return 0;
}