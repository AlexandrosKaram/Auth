#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int cnt,N,k,i;
    char c;
    FILE *in,*out;

    scanf("%d",&k);
   
    in = fopen("a.txt","r");
    if (in==NULL)
        printf("Sagma");
    else{
        out = fopen("o.txt","w");    
        
        cnt = 0;
        for(c=getc(in);c!=EOF;c=getc(in)){   
            if (c=='\n') cnt++;  // counting lines
        }
        N=cnt+1;
        in = fopen("a.txt","r");

        char strings[N][1000];

        for (i=0;i<N;i++){
            fgets(strings[i],1000,in);
            strings[i][strcspn(strings[i],"\n")] = '\0';

            for (int j=0;j<strlen(strings[i]);j++){
                strings[i][j] = strings[i][j]+k;
            }

            fprintf(out,"%s",strings[i]);
            if (i<N-1) fprintf(out,"\n");
            printf("%s\n",strings[i]);
        }

        fclose(out);
    }

    fclose(in);

    return 0;
}