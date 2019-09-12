parser: parser.y scanner.l
	bison -d -v parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c
	gcc -o parser lex.yy.o parser.tab.o -lfl   
clean:
	echo "done!"
