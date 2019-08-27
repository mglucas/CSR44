#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
int char_ct[26];
int num_ct[10];
int count=0;

int main(int argc,char *argv[]){
  
  char c; 
  memset(char_ct,0,sizeof(char_ct));
  memset(num_ct,0,sizeof(num_ct));
  
  while((c=getchar())!= EOF){
  
    if(isalpha(c)){
      count++;
      c = toupper(c);
     //printf("%c - %d\n",c,int(c));
      char_ct[(int)c-65]++;
    }
    else
    if(isdigit(c)){
       count++;
       num_ct[(int)c-48]++;
    }
  }

  printf("Total chars: %d\n",count);
  
  for(int i=0;i<26;i++)
    printf("%c - %.2f%\n",(char)65+i,100*(float)char_ct[i]/count);
     
  for(int i=0;i<10;i++)
    printf("%c - %.2f%\n",(char)48+i,100*(float)num_ct[i]/count);

  return 0;
}
