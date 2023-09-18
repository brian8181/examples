all: flex1 flex2

flex1: flex1.yy.c
	gcc flex1.yy.c -o flex1

flex2: flex2.yy.c
	gcc flex2.yy.c -o flex2

flex1.yy.c:
	flex -o flex1.yy.c flex1.l

flex2.yy.c:
	flex -o flex2.yy.c flex2.l

.PHONY: clean
clean:
	-rm flex*.yy.c
	-rm flex1 flex2
