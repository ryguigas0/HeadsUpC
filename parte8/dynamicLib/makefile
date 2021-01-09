encript.o: encript.c
	gcc -I/includes -fPIC -c encript.c -o encript.o

checksum.o: checksum.c
	gcc -I/includes -fPIC -c checksum.c -o checksum.o

libezsecurity.so: checksum.o encript.o
	gcc -shared checksum.o encript.o -o libs/libezsecurity.so

libTest: libTest.c libezsecurity.so
	gcc -I/includes -c libTest.c -o libTest.o
	gcc libTest.o -L/libs -lezsecurity -o libTest

clean:
	rm -r -f *.a *.o *.so