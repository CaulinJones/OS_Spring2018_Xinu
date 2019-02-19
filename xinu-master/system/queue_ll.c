#include <xinu.h>
#include <stdio.h>


struct qentry_ll{
  int32 qkey;
  int pid;
  struct  qentry_ll *qnext;
  struct qentry_ll *qprev;

};

struct qentry_ll *queuehead;

int insert_ll(struct qentry_ll *q, int pid, int32 key){
  queuehead = q;
  struct qentry_ll *cur = queuehead;
  struct qentry_ll* new = (struct qentry_ll *) getmem(sizeof(struct qentry_ll));
  struct qentry_ll *ptNew = &new;
  new->qkey = key;
  new->pid = pid;
  while(cur->qkey <= new->qkey ){
    cur = cur->qnext;
  }
  new->qnext = cur->qnext;
  new->qprev = cur;
  cur->qnext = ptNew;
  return new->pid;
}

int pop_ll(struct qentry_ll *q){
  queuehead = q;
  int out = queuehead->pid;
  freemem(queuehead,sizeof(struct qentry_ll ));
    return out;


}
