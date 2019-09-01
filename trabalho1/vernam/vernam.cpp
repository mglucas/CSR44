#include<bits/stdc++.h>
using namespace std;

char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
int key[1000];
char keyc[1000];
char cf[1000];

int char_valido(char c){ 
  char* ptr = strchr(chars,c);
  
  if(ptr == NULL) return -1; 
  else return ptr-chars;
}

int main(int argc,char *argv[]){
  srand(time(NULL));

  int tam = sizeof(chars)/sizeof(chars[0]) - 1;

  int pos;
  int rnd;
  int i=0;
  char c;  
  
  // Zera a memoria
  memset(key,0,sizeof(key));  
  memset(keyc,0,sizeof(keyc));  
  memset(cf,0,sizeof(cf));  
 
  // Key Generating
  if(!strcmp(argv[1],"-g")){
 
 	FILE *file = fopen("chave.dat","w");
    	if(file==NULL) {printf("error\n"); return 0;}
    
    // Generating verman key.dat 
    while((c=getchar())!= EOF){
      pos = char_valido(c);
	          
      if(pos == -1){
      	putchar(c);
      	key[i]=200;
        keyc[i]=c;
      	//printf("%d",key[i]);
        i++;   	
      }
      else{
        rnd = rand()%tam;
        keyc[i]= chars[rnd];
        putchar(chars[(pos+rnd)%tam]);
        i++;
      }
    }
    putchar('\n');

    int max = i;
    
    for(i=0;i<max;i++)
      	fputc(keyc[i],file);

    fclose(file);
  } 
  else

  // Decrypting
  if(!strcmp(argv[1],"-d")){
    
  int a;
  int pos,key;
  i = 0;
  char txt[1000];
  memset(txt,0,sizeof(txt));

  FILE *file = fopen("chave.dat","r");
    if(file==NULL) {printf("error\n"); return 0;}
	
	i = 0;
    while((c=getchar())!= EOF){
      pos = char_valido(c);
      a = fgetc(file);
      key = char_valido(a);
      
      if(pos == -1){
      	putchar(c);   	
      }   
      else{
      	
       if(pos-key>0)
          printf("%c",chars[(pos-key)%tam]); 
        else
          printf("%c",chars[tam-abs(pos-key)%tam]); 
      }
      i++;   
    
    }
   fclose(file);
  }

  
  return 0;
}
