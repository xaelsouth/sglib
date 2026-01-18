runall: arraysort arraysort1 arraybinsearch listsort listinsertsort listinsertsort1 rbtree dllist queue queue2 hash selftest
	+make clean

%.out: %.c ../sglib.h
	$(CC) -std=gnu89 -Wall -Wextra -pedantic -Wno-unused-function -I.. $*.c -o $*.out

arraysort: arraysort.out ../sglib.h
	./$< 6 7 3 4 1 4 1 3 5

arraysort1: arraysort1.out ../sglib.h
	./$< 6 7 3 4 1 4 1 3 5

arraybinsearch: arraybinsearch.out ../sglib.h
	./$< 6 7 3 4 1 4 1 3 5

listsort: listsort.out ../sglib.h
	./$< 6 7 3 4 1 4 1 3 5

dllist: dllist.out ../sglib.h
	./$< 6 7 3 4 1 4 1 3 5

hash: hash.out ../sglib.h
	./$<  1 3 1 5 2 3 1 7 11 33 11

listinsertsort: listinsertsort.out ../sglib.h
	./$< 6 7 3 4 1 4 1 3 5

listinsertsort1: listinsertsort1.out ../sglib.h
	./$< 6 7 3 4 1 4 1 3 5

rbtree: rbtree.out ../sglib.h
	./$< 6 7 3 4 1 4 1 3 5

queue: queue.out ../sglib.h
	gcc -I.. queue.c
	./$< 6 7 3 4 1 4 1 3 5

queue2: queue2.out ../sglib.h
	gcc -I.. queue2.c
	./$<

selftest: selftest.out ../sglib.h
	./$<
	echo Done.

clean:;
	rm -f *.out
