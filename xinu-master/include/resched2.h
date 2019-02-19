/* resched.h */

/* Constants and variables related to deferred rescheduling */

#defineDEFER_START1/* Start deferred rescehduling*/
#defineDEFER_STOP2/* Stop  deferred rescehduling*/

/* Structure that collects items related to deferred rescheduling*/

structdefer{
  int32ndefers;/* Number of outstanding defers */
  bool8attempt;/* Was resched called during the*/
  /*   deferral period?*/
};

externstructdeferDefer;
