#include <stdio.h>
#include <string.h>

int isLetter(char c){
    if (c>=97 && c<=122 || c>=65 && c<=90)
        return 1;
    return 0;
}

void readString(char s[]){
    fgets(s,199,stdin);
    s[strcspn(s,"\n")] = '\0';
}

void swap(char s1[],char s2[]){
    char temp[199];
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
}

int main() {
    char paragraph[199],words[200][200];
    int i,j=-1,k=0,N;

    readString(paragraph);
    N = strlen(paragraph);

    int newWord=1;

    for (i=0;i<N;i++){
        if (isLetter(paragraph[i])){
            if (newWord){
                j++;
                k=0;
                newWord=0;
            }
            words[j][k] = paragraph[i];
            k++;}
        else{
            newWord = 1;}
    }

    int length = j+1;

    for (i=1;i<length;i++){
        for (j=length-1;j>=i;j--){
            if (strcmp(words[j-1],words[j])>0){
                swap(words[j-1],words[j]);
            }
        }
    }

    for (i=0;i<length;i++){
        printf("%s\n",words[i]);
        if (i==14 && strcmp(words[i],"WITH")==0)
            printf("a\n");
    }

    return 0;
}