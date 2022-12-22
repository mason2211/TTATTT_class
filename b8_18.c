#include<stdio.h>
#include<string.h>
void computeLPSarray(char* P,int M,int* lps){
    int len = 0;
    lps[0]=0;
    int i = 1;
    while(i<M) {
        if(P[i] == P[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if(len!=0)
                len = lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

int main()
{
    char T[1000]; char P[1000];
    gets(T); gets(P);
    int M = strlen(P);
    int N = strlen(T);
    int lps[M];
    computeLPSarray(P,M,lps);
    int i = 0, j = 0, check=0;
    while(i<N){
        if(P[j]==T[i]){
            i++;
            j++;
        }
        if(j==M){
            printf("P co xuat hien trong T, co vi tri bat dau la %d",i-j);
            j = lps[j-1];
            check=1;
            break;
        }
        else if(i<N && P[j]!=T[i]){
            if(j==0)
                i=i+1;
            else j=lps[j-1];
        }
    }
    if(check==0)
        printf("P co xuat hien trong T!");
}
