#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc,char *argv[]){

  char c; // encrypt signal
  int k; // k = chave  
  
  if(!strcmp(argv[2],"-k"))
  k = atoi(argv[3]);

  if(!strcmp(argv[1],"-c")){
    while((c=getchar())!= '\n'){
      if(isalpha(c)) printf("%c",c+k);
      if(isspace(c)) putchar(' ');
    }
    putchar('\n'); 
  }

 else
 if(!strcmp(argv[1],"-d")){
    while((c=getchar())!= '\n'){
      if(isalpha(c)) printf("%c",c-k);
      if(isspace(c)) putchar(' ');
    }
    putchar('\n'); 
  }


  return 0;
}
