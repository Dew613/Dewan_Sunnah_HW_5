dirtest: dirinfo.c
	gcc dirinfo.c
clean:
	rm *~
run: a.out
	./a.out
