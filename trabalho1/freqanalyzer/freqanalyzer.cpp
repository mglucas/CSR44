#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
int char_ct[26];
int num_ct[10];

int main(int argc,char *argv[]){
  
  char c; 
  memset(char_ct,0,26*sizeof(int));
  memset(num_ct,0,10*sizeof(int));
  
  while((c=getchar())!= EOF){
    printf("%c",c);
  
    if(isalpha(c)){
      c = toupper(c);
      char_ct[65-(int)c]++;
    }
    else
    if(isdigit(c)) num_ct[48-(int)c];

  }

  for(int i=0;i<26;i++)
    printf("%c - %d\n",(char)65+i,char_ct[i]);
     
  for(int i=0;i<10;i++)
    printf("%c - %d\n",(char)48+i,num_ct[i]);

  return 0;
}
