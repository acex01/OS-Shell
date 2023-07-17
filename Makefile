a2:
	gcc date.c -o date
	gcc ls.c -o ls
	gcc rm.c -o rm
	gcc mkdir.c -o mkdir
	gcc cat.c -o cat
	gcc shell.c -o shell
	./shell
run:
	./shell
clean:
	rm date ls rm mkdir cat shell
	
