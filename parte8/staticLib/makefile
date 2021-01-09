encript.o: encript.c
	gcc -c encript.c -o encript.o

checksum.o: checksum.c
	gcc -c checksum.c -o checksum.o

libezsecurity.a: checksum.o encript.o
	ar -rcs libezsecurity.a checksum.o encript.o

libTest: libTest.c libezsecurity.a
	gcc libTest.c -L . -lezsecurity -o libTest

clean:
	rm -r -f *.a *.o