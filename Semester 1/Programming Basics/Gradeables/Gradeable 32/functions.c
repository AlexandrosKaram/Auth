#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chars(char *s, char *most, char *least){
    int i,n,j,ascii[128];    

    n = strlen(s);

    for (i=0;i<128;i++) ascii[i] = 0;
    for (i=0;i<n;i++) ascii[s[i]]++;

    *most = *least = s[0];

    for (i=1;i<n;i++){
        if (ascii[s[i]]>ascii[*most])
            *most = s[i];
        else if (ascii[s[i]]==ascii[*most]){
            for (j=0;j<n;j++){
                if (s[j]==*most)
                    break;
                else if (s[j]==s[i])
                    *most = s[i];
            }
        }
        
        if (ascii[s[i]]<ascii[*least])
            *least = s[i];
        else if (ascii[s[i]]==ascii[*least]){
            for (j=0;j<n;j++){
                if (s[j]==*least)
                    break;
                else if (s[j]==s[i])
                    *least = s[i];
            }
        }
        
    }
}

char *reverse (char *s){
    char *ns;
    int i,n;

    n = strlen(s);
    ns = (char*)malloc(n*sizeof(char)+1);

    for (i=0;i<n;i++)
        ns[i] = s[n-i-1];
    ns[i] = '\0';

    return ns;
}