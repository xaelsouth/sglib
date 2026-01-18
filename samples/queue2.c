#include <stdio.h>
#include <stdlib.h>

#include "../sglib.h"

/* 
  an alternative level-0 interface to queues, 
  it will probably not be accepted to Sglib core, because
  its level-1 interface is doing the same level of abstraction.
*/

#define SGLIB_NQUEUE_TYPEDEF(type, dim, queuetype) \
  typedef struct queuetype { \
    type a[dim]; \
    int i,j; \
  } queuetype;

#define SGLIB_NQUEUE_INIT(type, q) SGLIB_QUEUE_INIT(type, (q).a, (q).i, (q).j)
#define SGLIB_NQUEUE_IS_EMPTY(type, q) SGLIB_QUEUE_IS_EMPTY(type, (q).a, (q).i, (q).j)
#define SGLIB_NQUEUE_IS_FULL(type, q) SGLIB_QUEUE_IS_FULL(type, (q).a, (q).i, (q).j, (int)(sizeof((q).a)/sizeof(type)))
#define SGLIB_NQUEUE_FIRST_ELEMENT(type, q) SGLIB_QUEUE_FIRST_ELEMENT(type, (q).a, (q).i, (q).j)
#define SGLIB_NQUEUE_ADD(type, q, elem) SGLIB_QUEUE_ADD(type, (q).a, elem, (q).i, (q).j, (int)(sizeof((q).a)/sizeof(type))) 
#define SGLIB_NQUEUE_DELETE(type, q) SGLIB_QUEUE_DELETE_FIRST(type, (q).a, (q).i, (q).j, (int)(sizeof((q).a)/sizeof(type)))


/* *********************************************************** */

SGLIB_NQUEUE_TYPEDEF(int, 100, myqueue)


int main() {
  int i;
	myqueue t;

  SGLIB_NQUEUE_INIT(int, t);

  assert(SGLIB_NQUEUE_IS_EMPTY(int, t));
  assert(!SGLIB_NQUEUE_IS_FULL(int, t));
  
  for (i = 0; !SGLIB_NQUEUE_IS_FULL(int, t); i++)
    SGLIB_NQUEUE_ADD(int, t, i);

  assert(SGLIB_NQUEUE_IS_FULL(int, t));

  assert(0 == SGLIB_NQUEUE_FIRST_ELEMENT(int, t));
  SGLIB_NQUEUE_DELETE(int, t);
  assert(!SGLIB_NQUEUE_IS_FULL(int, t));

  assert(1 == SGLIB_NQUEUE_FIRST_ELEMENT(int, t));
  SGLIB_NQUEUE_DELETE(int, t);
  assert(!SGLIB_NQUEUE_IS_FULL(int, t));

  for (i = 2; !SGLIB_NQUEUE_IS_EMPTY(int, t); i++)
  {
    assert(i == SGLIB_NQUEUE_FIRST_ELEMENT(int, t));
    SGLIB_NQUEUE_DELETE(int, t);
  }

  assert(SGLIB_NQUEUE_IS_EMPTY(int, t));

  return(0);
}
