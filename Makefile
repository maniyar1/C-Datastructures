demo: demo.c *.h 
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g $^ -o $@
