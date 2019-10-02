parser: parser.y scanner.l
	bison -d -v parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c
	gcc -o etapa2 lex.yy.o parser.tab.o -lfl   
clean:
	echo "done!"
