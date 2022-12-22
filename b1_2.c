#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void chuyenSoNguyenLon(int arr[100],long long int p ,int W,long long int a, int t){
    for(int i=t-1;i>=0;i--){
        int x = pow(2,i*W);
        arr[i] = a/x;
        a%=x;
    }
}
void congSoNguyenLon(int ar[], int br[], int cr[], int W, int t){
    int epsilon = 0, h = pow(2,W);
    for(int i=0;i<t;i++){
        cr[i] = ar[i] + br[i] + epsilon;
        if(cr[i]>=h){
            epsilon = 1;
            cr[i]%=h;
        }  
        else epsilon = 0;
    }
    printf ("A+B=(%d, [",epsilon);
    for(int i=t-1;i>=0;i--){
        printf("%d",cr[i]);
        if(i!=0)
            printf("   ");
        else printf ("])");
    }
    long long int a=0;
    for(int i=t-1; i>=0;i--){
        a+=pow(2,i*W)*cr[i];
    }
    printf("\nC = %lld",a);
}
void truSoNguyenLon(int ar[], int br[], int cr[], int W, int t){
    int epsilon=0, h=pow(2,W);
    for(int i=0;i<t;i++){
        cr[i] = ar[i] - br[i] - epsilon;
        if(cr[i]<0){
            cr[i]+=h;
            epsilon = 1; 
        }
        else if(cr[i]>=h){
            epsilon = 0;
            cr[i]%=h;
        }
        else epsilon=0;
    }
    printf("C=A-B=(%d, [",epsilon);
    for (int i=t-1;i>=0;i--)
    {
        printf("%d ",cr[i]);
    }
    printf("])");
    long long int a=0;
    for(int i=t-1; i>=0;i--){
        a+=pow(2,i*W)*cr[i];
    }
    printf("\nC = %lld",a);
}
void in(int arr[100], int t){
    printf ("[");
    for(int i=t-1;i>=0;i--){
        printf("%d",arr[i]);
        if(i!=0)
            printf("   ");
        else printf ("]");
    }
}
void show(){
    printf("1. Nhap a, b\n");
    printf("2. In a, b\n");
    printf("3. Cong \n");
    printf("4. Tru\n");
    printf("5. Thoat\n");
    printf("Chon: ");
}
int main(){
    long long int p=2147483647, a, b;
    int W=8, arr[100], brr[100], crr[100], choice, check=0;
    //printf("Nhap p va W = ");
    //scanf("%lld%d", &p, &W);
    int m = ceil(log(p)/log(2));
    int t = ceil((float)m/W);
    while(1){
        show();
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Nhap so nguyen lon a = ");
            scanf("%lld",&a);
            printf("Nhap so nguyen lon b = ");
            scanf("%lld",&b);
            printf("Nhap thanh cong!");
            check=1;
            system("cls");
            break;
        case 2:
            if(check==1){
                chuyenSoNguyenLon(arr,p,W,a,t);
                printf("Mang A = "); in(arr,t);
                chuyenSoNguyenLon(brr,p,W,b,t);
                printf("\nMang B = "); in(brr,t);
            }
            else printf("\nNhap a va b truoc!!");
            break;
        case 3:
            if(check==1){
                chuyenSoNguyenLon(arr,p,W,a,t);
                chuyenSoNguyenLon(brr,p,W,b,t);
                congSoNguyenLon(arr,brr,crr,W,t);
            }
            else printf("\nNhap a va b truoc!!");
            check=1;
            break;
        case 4:
            if(check==1){
                chuyenSoNguyenLon(arr,p,W,a,t);
                chuyenSoNguyenLon(brr,p,W,b,t);
                truSoNguyenLon(arr,brr,crr,W,t);
            }
            else printf("Nhap a va b truoc!!");
            break;
        case 5:
            fflush(stdin);
            printf("See u again!");
            exit(0);
            break;
        default: printf("Khong co lua chon!");
        }
        printf("\nAn phim bat ki de quay ve menu!\n");
        fflush(stdin);
        getch();
        system("cls");
    }
    return 0;
}

