#include <stdio.h>

int main(){
    int i,N,cnt;

    scanf("%d",&N);

    if (N>=0){
        cnt = 0;
        for (i=1;i<=N;i++){
            if (N%i==0) cnt++;}
        printf("%d",cnt);
    }else
        printf("Wrong Input");
}