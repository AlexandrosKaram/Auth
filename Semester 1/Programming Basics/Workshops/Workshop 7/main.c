#include <stdio.h>
#include <string.h>

struct person{
    char name[30];
    char rank;
    int num;
};

void readString(char *s){
    fgets(s,30,stdin);
    s[strcspn(s,"\n")] = '\0';
}

int main() {
    int i,N;
    char string[30]; 
    
    scanf("%d ",&N);

    struct person info[N];

    for (i=0;i<N-1;i++){
        readString(info[i].name);
        scanf(" %c %d ",&info[i].rank,&info[i].num);
    }
    readString(info[N-1].name);
    scanf(" %c %d",&info[N-1].rank,&info[N-1].num);
    

    int BS[100000];

    for (i=0;i<100000;i++) BS[i] = -1;
    
    for (i=0;i<N;i++){
        BS[info[i].num] = i;
    }

    for (i=1;i<100000;i++){
        if (BS[i] != -1){
            int k = BS[i];
            printf("%s, %c, %d",info[k].name, info[k].rank, info[k].num);
            if (BS[i]<N) printf("\n");
        }
    }

    return 0;
}