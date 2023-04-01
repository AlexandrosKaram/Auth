#include <stdio.h>
#include <string.h>

void read(char s[],int N){
    fgets(s,N,stdin);
    s[strcspn(s,"\n")] = '\0';
}

void mostInRow(char s[],int *t,char *k){
    int i,N,cnt;

    N = strlen(s);
    cnt = 1;
    *t = 1;
    *k = s[1];
    for (i=1;i<N;i++){
        if (s[i]==s[i-1]){
            cnt ++;
            if (cnt>*t){
                *t = cnt;
                *k = s[i];}
        }else
            cnt = 1;
    }
}