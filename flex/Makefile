all: output

output: lex.yy.c
	gcc lex.yy.c -o output

lex.yy.c:
	flex flex_tut.l 

.PHONY: clean
clean:
	rm output
