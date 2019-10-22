parser: parser.y scanner.l
	bison -d -v parser.y
	flex scanner.l
	gcc -o etapa4 lex.yy.c parser.tab.c main.c ast.c symbol_table.c -lfl 
	#gcc -o etapa3 main.o lex.yy.o parser.tab.o -lfl   
clean:
	echo "done!"
