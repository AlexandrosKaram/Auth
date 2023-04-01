#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void anonymize(char *s){
    int i,N;
    N = strlen(s);

    for (i=0;i<N;i++){
        s[i] = '*';
    }
}

void createString (int k,char a,char b,char *s){
    int i;

    for (i=0;i<k;i++){
        s[i] = i%2==0?a:b;
    }

    s[i] = '\0';
}