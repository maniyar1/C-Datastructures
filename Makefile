demo: demo.c *.h 
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g $^ -o $@

memtest: mem-test.c *.h 
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g $^ -o $@
