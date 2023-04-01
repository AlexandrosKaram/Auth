#include <stdio.h>
#include <string.h>

struct city{
  char name[29];
  double temperature;
  int cnt;
};

void readString(char s[]){
  scanf(" ");
  fgets(s,29,stdin);
  s[strcspn(s,"\n")] = '\0';
}

int main(){
  int i,last=0,pos=0;
  char c,unit,s[29];
  struct city cities[100];
  double t;

  for (i=0;i<100;i++){  // initializing
    cities[i].temperature = 0;
    cities[i].cnt = 0;
  }
  
  i=0;
  do{
    i++;
    readString(s);
    
    for (pos=0;pos<last;pos++){
      if (strcmp(cities[pos].name,s)==0)
        break;
    }
    
    scanf("%lf %c",&t,&unit);
    
    if (unit=='f') t = (t-32)*5.0/9;
    if (cities[pos].cnt == 0) strcpy(cities[pos].name,s);
    
    cities[pos].temperature += t;
    cities[pos].cnt ++;
    if (pos==last) last++;
    
    scanf(" %c",&c);
  }while (i<100 && c!=113);

  readString(s);
  scanf(" %c",&unit);
 
  for (pos=0;pos<last;pos++){
    if (strcmp(cities[pos].name,s)==0){
      double result;
      result = (double)cities[pos].temperature/cities[pos].cnt;
      if (unit=='f') result = result*9.0/5+32;
      printf("%.1lf",result);
      break;
    }
  }
  if (pos==last) printf("0.0");
  
  return 0;
}