scanner: scanner.l
	flex scanner.l
	gcc -o main main.c lex.yy.c -lfl -lm
	
clean:
	echo "done!"
