#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
 char *s = malloc (1000*sizeof(char));
 char *s2;
 char mostSeen, lessSeen;
 fgets(s,1000,stdin);
 s[strcspn(s,"\n")] = '\0';
 chars(s,&mostSeen, &lessSeen);
 s2 = reverse(s);
 printf("%s\n",s);
 printf("%s\n",s2);
 printf("%c\n%c\n",mostSeen,lessSeen);
 return 0;
}