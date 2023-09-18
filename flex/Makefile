all: flex1 flex2 count

flex1: flex1.yy.c
	gcc flex1.yy.c -o flex1

flex2: flex2.yy.c
	gcc flex2.yy.c -o flex2

count: count.yy.c
	gcc count.yy.c -o count

flex1.yy.c:
	flex -o flex1.yy.c flex1.l

flex2.yy.c:
	flex -o flex2.yy.c flex2.l

count.yy.c:
	flex -o count.yy.c count.l

.PHONY: clean
clean:
	-rm *.yy.c
	-rm flex1 flex2 count
