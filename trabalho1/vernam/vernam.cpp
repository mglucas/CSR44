#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>

using namespace std;

char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
char key[100];

int main(int argc,char *argv[]){
  srand(time(NULL));

  int tam = sizeof(chars)/sizeof(chars[0]) - 1;

  FILE *file = fopen("chave.dat","w");
  if(file==NULL) {printf("error\n"); return 0;}

  int i=0;
  char c;  
  // Zera a memoria
  memset(key,0,sizeof(key));  
 
  if(!strcmp(argv[1],"-g")){
    // Generating verman key.dat 
    while((c=getchar())!= EOF){
      key[i++] = chars[rand()%tam];
      printf("%c",chars[(int)(c+key[i-1])%tam]);
    }
    putchar('\n');

    i = 0;
    
    while(key[i]!=0)
      fputc(key[i++],file);

    fclose(file);
  } 
  else
  if(!strcmp(argv[1],"-d")){
    
  int pos;
  i = 0;
    while((c=getchar())!= EOF){
      
      pos = strchr(chars,c) - chars;  

      if(pos-(int)key[i]>0)
        printf("%c",chars[(pos-(int)key[i++])%tam]); 
      else
        printf("%c",chars[tam- abs(pos-(int)key[i++])%tam]); 

    }

  }

  
  return 0;
}
