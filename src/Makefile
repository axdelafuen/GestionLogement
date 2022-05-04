CC = gcc
CFLAGS = -Wall -fPIC

all : testGlobal

testGlobal : testGlobal.o global.o locataire.o demande.o logement.o
	$(CC) -o testGlobal testGlobal.o global.o locataire.o demande.o logement.o

testGlobal.o : testGlobal.c global.c locataire.c demande.c logement.c
	$(CC) -c $(CFLAGS) testGlobal.c

global.o : global.c global.h
	$(CC) -c $(CFLAGS) global.c

locataire.o : locataire.c locataire.h
	$(CC) -c $(CFLAGS) locataire.c

demande.o : demande.c demande.h
	$(CC) -c $(CFLAGS) demande.c

logement.o : logement.c logement.h
	$(CC) -c $(CFLAGS) logement.c

clean:
	rm -f testGlobal *.o
