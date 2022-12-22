#include<stdio.h>
#include<string.h>
int main(){
    char T[1000],P[1000];
    gets(T); gets(P); 
    int lengthofText = strlen(T);
    int lengthofPattern = strlen(P);
    for(int i = 0 ; i <lengthofText; i++){
        int j=0;
        while(j<lengthofPattern && T[i+j]== P[j])
            j++; 
        if(j == lengthofPattern){
            printf("P co xuat hien trong T, co vi tri bat dau la %d",i);
            break;
        }
        if(i == lengthofText-lengthofPattern){
            printf("P khong xuat hien trong T!");
            break;
        }
    }
}

