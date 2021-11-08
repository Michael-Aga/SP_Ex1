all: mains maindloop maindrec loops loopd recursives recursived

loops: libclassloops.a

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: libclassrec.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: libclassrec.so

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -Wall -g -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

loopd: libclassloops.so

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -Wall -g -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	gcc -Wall -g -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	gcc -Wall -g -o maindrec main.o ./libclassrec.so -lm

main.o: main.c NumClass.h
	gcc -Wall -g -c main.c

basicClassification.o: basicClassification.c
	gcc -Wall -g -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc -Wall -g -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc -Wall -g -c advancedClassificationRecursion.c

clean:
	rm -f *.o *.a *.so mains maindrec maindloop