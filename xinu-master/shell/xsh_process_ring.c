#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>




/* When the last value has been acknowledged produce a new value by
   incrementing the last value and putting it in the produce
   location. */
process polling_producer(volatile int32 consume[],int32 prosPos,int32 nextPos){
  int32 last = consume[prosPos];
  printf("this thing ran %d \n",consume[prosPos]);
  while (last > 0){
    /* Polling to see if the consumer has consumed the last value*/ 
    int32 tmp = consume[prosPos];
    if (last != tmp){
      printf("produced: %d\n", tmp - 1);
      last = tmp - 1;
      consume[nextPos] = tmp - 1;
    }
  }
  return OK;
}


shellcmd xsh_process_ring(int nargs, char *argsv[]){
  int32 numIn = atoi(argsv[2]);
  uint32 roundsIn= atoi(argsv[1]);
  int i;
  //int32 produce[roundsIn];
  volatile int32 consume[numIn];
  consume[0] = (numIn * roundsIn)-1;
  
  printf("%d\n",consume[0]);
  for(i = 0;i < numIn; i++){
    if(i == numIn-1){
      resume(create(polling_producer, 1024,20,"producer",3, consume,i,0));
    }else {
      //printf("for loop started");
      resume(create(polling_producer, 1024, 20, "producer", 3, consume, i, i+1));
      // printf("created %d",i);
    }
  }
  /* Polling to see if both producer and consumer are done */
  while (consume[1] != 0);
  return SHELL_OK;

  


}
