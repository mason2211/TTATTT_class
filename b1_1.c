#include <stdio.h>
#include <math.h>
void chuyenSoNguyenLon(int arr[100],long long int p ,int W,long long int a, int t){
    for(int i=t-1;i>=0;i--){
        int x = pow(2,i*W);
        arr[i] = a/x;
        a%=x;
    }
    printf ("A= [");
    for(int i=t-1;i>=0;i--){
        printf("%d",arr[i]);
        if(i!=0)
            printf("   ");
        else printf ("]");
    }
}
long long int chuyenMangThanhSoNguyenLon(int arr[100],long long int p ,int W, int t){
    
    long long int a=0;
    for(int i=t-1; i>=0;i--){
        a+=pow(2,i*W)*arr[i];
    }
    return a;
}
int main(){
    long long int p=2147483647, a;
    int W=8, arr[100];
    //scanf("%lld%d", &p, &W);
    // Ý a.
    printf("Nhap so nguyen lon a = ");
    scanf("%lld",&a);
    int m = ceil(log(p)/log(2));
    int t = ceil((float)m/W);
    chuyenSoNguyenLon(arr,p,W,a,t);
    //Ý b.
    printf("\nNhap lan luot cac tu %d-bit: ",W);
    for(int i=t-1;i>=0;i--){
        scanf("%d",&arr[i]);
    }
    printf("\nGia tri cua mang trong Fp la: %lld",chuyenMangThanhSoNguyenLon(arr,p,W,t));
    return 0;
}
