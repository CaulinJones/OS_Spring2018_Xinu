#include <stdio.h>


void main(int argc, char *args[])
{

  if(argc == 1){
    printf("Hello %s, Welcome to the world of Xinu!!\n", *args);
    
  }else{
    printf("Invalid nubmer of Arguments!");
  }
}
