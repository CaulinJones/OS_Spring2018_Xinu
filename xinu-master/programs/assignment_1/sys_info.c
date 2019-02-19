//Sys_info.c
//course: p436
//author: Caulin Jones
//date create: 1/16/2018
//date modified: 1/19/2018
//#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int nargs, char *argv[]){
  int  fd[2];
  pid_t childpid;
  //  char output[80];
  char  string[] = "Hello, world! \n";
  char readbuffer[80];
  pipe(fd);
  //input error test
  if(nargs != 2){
    printf("Invalid number of arguments");
  }else if((childpid = fork()) == -1){
    perror("fork");
    exit(1);
  }else if(childpid > 0){
    //writing argument from parent
    write(fd[1],argv[1] , (strlen(argv[1])+1));
    //waiting for response
    
    printf("Parent PID = %d \n",getpid());
    printf("Child PID = %d \n", childpid);
    wait(NULL);
    
    exit(0);
   
  }else {
    //parent proc closes output side of pipe
    close(fd[1]);
    //read in string of pipe for child
    char echo[] = "/bin/echo";
    read(fd[0], readbuffer, sizeof(readbuffer));
    //executing child process from piped in argument
    if(readbuffer == echo){
      execl(readbuffer,"echo",string,(char*) NULL);
    }else {
      
    execl(readbuffer,string,(char*) NULL);
    }
    //    printf("%s \n", readbuffer);
  }
  return(0);
}
