#include <xinu.h>
#include <string.h>
#include <stdio.h>


shellcmd xsh_hello(int nargs ,char *args[]){
  if(2 < nargs ){
    printf("Error: Too few arguments \n");
  }else if(nargs > 2){
    printf("Error: Too many arguments\n");
  }else{
    printf("Hello %s, Welcome to the world of Xinu!!\n", args[1]);
  }
  return 0;
}
