BUILD=./build

all: flex1 flex2 count ex1

flex1: flex1.yy.c
	gcc $(BUILD)/flex1.yy.c -o $(BUILD)/flex1

flex2: flex2.yy.c
	gcc $(BUILD)/flex2.yy.c -o $(BUILD)/flex2

count: count.yy.c
	gcc $(BUILD)/count.yy.c -o $(BUILD)/count

ex1: ex1.yy.c
	gcc $(BUILD)/ex1.yy.c -ll -o $(BUILD)/ex1

flex1.yy.c:
	flex -o $(BUILD)/flex1.yy.c flex1.l

flex2.yy.c:
	flex -o $(BUILD)/flex2.yy.c flex2.l

count.yy.c:
	flex -o $(BUILD)/count.yy.c count.l

ex1.yy.c:
	flex -o $(BUILD)/ex1.yy.c ex1.l

.PHONY: clean
clean:
	-rm $(BUILD)/*
	