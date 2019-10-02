parser: parser.y scanner.l
	bison -d -v parser.y
	flex scanner.l
	gcc -c lex.yy.c parser.tab.c main.c
	gcc -o etapa3 lex.yy.o parser.tab.o main.o -lfl   
clean:
	echo "done!"
