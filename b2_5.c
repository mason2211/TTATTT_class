#include<stdio.h>
#include<math.h>
void chuyenSoNguyenLon(int arr[100],int W,long long int a,int t){
    for(int i = t-1 ; i>=0; i--){
        int z = pow(2,W*i);
        arr[i]=a/z;
        a = a%z;
    }
}
int cong(int a[100],int b[100],int c[100],int t,int W){
    int e = 0;
    for(int i =0; i<t; i++){
        int w=a[i]+b[i]+e;
        int h = pow(2,W);
        if(w>=h){
            e=1;
            c[i]=w%h;
        }
        else{
            e=0;
            c[i]=w%h;
        }
    }
    return e;
}
int tru(int a[100],int b[100],int c[100],int t,int W){
    int e = 0;
    for(int i =0; i<t; i++){
        int w=a[i]-b[i]-e;
        int h = pow(2,W);
        if(w<0){
            c[i]=h+w;
            e=1;
        }
        else if(w>=h){
            c[i] =w%h;
            e=1;
        }
        else{
            e=0;
            c[i]=w%h;
        }
    }
    return e;
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
    long long int p,a1,a2,m,t,e,i;
    int a[100],b[100],c[100],P[100],W;
    /*p=2147483647; W=8; a1=2147483646; a2= 2147483643;        p, W, a, b
    //p=479001599; W=8; a= 347483646 ; b= 474836419;
    2971215073 8 2147483645 2971215070*/
    scanf("%lld%d%lld%lld",&p,&W,&a1,&a2);
    m = ceil(log(p)/log(2));
    t = ceil((float)m/W);
    chuyenSoNguyenLon(a,W,a1,t);
    chuyenSoNguyenLon(b,W,a2,t);
    tru(a,b,c,t,W);
    e = tru(a,b,c,t,W);
    printf ("\nC= A-B =(%d, [",e);
    for(int i=t-1;i>=0;i--){
        printf("%d",c[i]);
        if(i!=0)
            printf("   ");
        else printf ("])");
    }
    if(e==1){
        chuyenSoNguyenLon(P,W,p,t);
        e = cong(c,P,c,t,W);
    }
    printf("\nTren truong Fp: C = [");
    for(int i = t-1 ; i>=0; i--){
        printf("%d",c[i]);
        if(i!=0){
            printf("   ");
        }
        else{
            printf("]");
        }
    }
    printf("\nC = %lld",mangThanhSo(c,W,t));
}
