#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>

using namespace std;

char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
char key[100];


int char_valido(char c){
  char* ptr = strchr(chars,c);
  
  if(ptr == NULL) return -1;
  else
  return ptr-chars;
}


int main(int argc,char *argv[]){
  srand(time(NULL));

  int i=0;
  char c;  
  // Zera a memoria
  memset(key,0,sizeof(key));  

  // Generating verman key.dat 
  while((c=getchar())!= EOF){
	key[i++] = (char)(90-rand()%25);
//	printf("%d\n",i);
//	printf("%c\n",key[i-1]);
	printf("Char codificado:%c\n",(char)((c+key[i-1])%26+65));	
  }
 

  return 0;
}
