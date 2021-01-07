encript.o: encript.c encript.h
	gcc -c encript.c

msgHider.o: msgHider.c encript.c encript.h
	gcc -c msgHider.c

decrypt.o: decrypt.c encript.c encript.h
	gcc -c decrypt.c

encrypter: msgHider.o encript.o
	gcc msgHider.o encript.o -o encrypter

decrypter: decrypt.o encript.o
	gcc decrypt.o encript.o -o decrypter

clean:
	rm -f *.o