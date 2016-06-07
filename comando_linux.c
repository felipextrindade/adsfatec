#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
  char comando[20], path[20], parametro[20];
  gets(comando);
  
  while(strcmp(comando,"exit")) {
    gets(parametro);
    strcpy(path, "/bin");
    strcat(path, comando);
    int coderet=fork();
      if(coderet == 0) {
        int retorno = execl(path, comando, NULL, NULL);
        exit(retorno);
      }
      gets(comando);
  }
}
