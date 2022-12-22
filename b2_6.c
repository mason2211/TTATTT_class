#include <stdio.h>
#include <math.h>
void chuyenSoNguyenLon(int ar[100],long long int a, int W, int t){
    for (int i=t-1;i>=0;i--){
        int h = pow(2,W*i);
        ar[i] = a/h;
        a %= h;
    }
}
int dec2Bin(int x, int a[100], int W){
    int i = 0;
    for (i=0;x>0;i++){
        a[i]=x%2;
        x/=2;
    }
    while (i<2*W){
        a[i++] = 0;
    }
}
int bin2Dec(int n, int a[100]){
    int x = 0;
    for (int i=0;i<n;i++){
        x += a[i]*pow(2,i);
    }
    return x;
}
void in(int arr[100], int t) {
    printf("[");
    for (int i = t - 1;i >= 0;i--) {
        printf("%d", arr[i]);
        if (i != 0)
            printf("   ");
        else printf("]\n");
    }
}
long long int mangThanhSo(int arr[100],int W,int t){
    long long int p=0;
    for(int i=0;i<t;i++){
        long long int h=pow(2,W*i);
        p+= (h*arr[i]);
    }
    return p;
}
int main(){
    long long int p, a, b;
    int W, ar[100], br[100], cr[100], uvr[100], ur[100], vr[100], U, V, UV ;
    //p=2147483647; W=8; a=2348762; b= 98637
    scanf("%lld%d%lld%lld",&p,&W,&a,&b);
    int t = ceil((float)ceil(log(p)/log(2))/W);
    chuyenSoNguyenLon(ar,a,W,t); in(ar,t);
    chuyenSoNguyenLon(br,b,W,t); in(br,t);
    for (int i=0;i<t;i++){
        cr[i] = 0;
    }
    for (int i=0;i<t;i++){
        U = 0;
        for (int j=0;j<t;j++){
            UV = cr[i+j] + ar[i]*br[j] + U;
            dec2Bin(UV,uvr,W);
            for(int i=0;i<W;i++){
                vr[i]=uvr[i];
                ur[i]=uvr[i+W];
            }
            V = bin2Dec(W,vr);  U = bin2Dec(W,ur);
            cr[i+j]=V;
        }
        cr[i+t]=U;
    }
    printf("c=a.b=[%d",cr[W-1]);
    for(int i=W-2;i>=0;i--){
        printf("   %d", cr[i]);
    }
    printf("]");
    printf("\nC = %lld", mangThanhSo(cr,W,2*t));
    return 0;
}