all:ldpreload_exploit


ldpreload_exploit:main.o
	gcc -o ldpreload_exploit main.o

main.o:main.c
	gcc -fPIC -shared -o /tmp/main.so main.c -nostartfiles


