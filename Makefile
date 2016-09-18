all:
	gcc -g -o pointer_math pointer_math.c

cli:
	gcc -g -o cli cli.c

clean:
	rm pointer_math
	rm -rf pointer_math.dSYM/
	

