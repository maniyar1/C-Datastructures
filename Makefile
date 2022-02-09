demo: demo.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g $^ -o $@
