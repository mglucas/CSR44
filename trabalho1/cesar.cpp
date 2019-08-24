#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";


int char_valido(char c){
  char* ptr = strchr(chars,c);
  
  if(ptr == NULL) return -1;
  else
  return ptr-chars;
}


int main(int argc,char *argv[]){
  
  // encrypt signal
  char c; 
  // k = chave  
  int k;
  // Tamanho do vetor de chars 
  int tam_chars = sizeof(chars)/sizeof(chars[0]) - 1;
  // char position returned as int
  signed int pos;
 
  // key 
  if(!strcmp(argv[2],"-k")) k = atoi(argv[3]);

  // encrypt
  if(!strcmp(argv[1],"-c")){
    while((c=getchar())!= EOF){
      pos = char_valido(c);
      
      if(pos == -1){  
        if(c=='\n') putchar('\n');
        else
        if(isspace(c)) putchar(' ');
      } 
      else
      printf("%c",chars[(pos+k)%tam_chars]);
      
    }
    putchar('\n'); 
  }
  // decrypt
  else
  if(!strcmp(argv[1],"-d")){
    while((c=getchar())!= EOF){
      pos = char_valido(c);
      
      if(pos == -1){  
        if(c=='\n') putchar('\n');
        else
        if(isspace(c)) putchar(' ');
      } 
      else
      printf("%c",chars[(pos-k)%tam_chars]);
      
    }
    putchar('\n'); 
  }


  return 0;
}
