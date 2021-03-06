#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
This command is used to demonstrate my queue_ll implementation for assignment 3 for p436
input:integer
this command adds the integers counting down to 0 into a queue, then dequeues the elements in order.

*/
struct qentry_ll{
  int32 qkey;
  int pid;
  struct  qentry_ll *qnext;
  struct qentry_ll *qprev;

};
shellcmd xsh_queuetest(int nargs, char* vargs[]){

  if(nargs == 2){
    if(strncmp(vargs[1], "--help",7) == 1){
      printf("This command is used to test a linkedlist implementation of a queue for assignmetn 3\n This function take a single int as its argument \n");
    }else {
      int count = atoi(vargs[1]);
      printf("Queue Number: %d\n",count);
      struct qentry_ll* head = (struct qentry_ll *) getmem(sizeof(struct qentry_ll));
      int i;
      for(i = 0; i <= count; i++){
	int out =  insert_ll(head,i,count);
      printf("insert: %d\n",out);
      }
      for(i=0; i<=count; i++){
	int out = pop_ll(head);
	printf("pop: %d\n",out);
      }
      printf("Queue Demo is Over!");
    }
    
  }else{
    printf("Invalide Arguments for: Queuetest");
  }


}
