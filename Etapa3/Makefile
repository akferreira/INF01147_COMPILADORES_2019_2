parser: parser.y scanner.l
	bison -d -v parser.y
	flex scanner.l
	gcc -o etapa3 lex.yy.c parser.tab.c main.c ast.c -lfl 
	#gcc -o etapa3 main.o lex.yy.o parser.tab.o -lfl   
clean:
	echo "done!"
