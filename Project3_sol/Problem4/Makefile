#Optimization Level
CFLAG = -O0

#Include Directory
INCDIR = -I "include" -I "../Single-linked-list/include"

#Object File Directory
OBJDIR = ./

#Object File List
OBJ = \
./problem4.o \
./Single.o \
./main.o

#Target Name
TARGET = compile

${TARGET} : ${OBJ}
	gcc -o ${TARGET} ${OBJ} ${CFLAG} ${INCDIR}

${OBJDIR}Single.o: ../Single-linked-list/src/Single_linked_list.c
	gcc ../Single-linked-list/src/Single_linked_list.c ${INCDIR} ${CFLAG} -c -o $@

${OBJDIR}problem4.o: src/problem4.c 
	gcc src/problem4.c ${INCDIR} ${CFLAG} -c -o $@

${OBJDIR}main.o: src/main.c
	gcc src/main.c ${INCDIR} ${CFLAG} -c -o $@

clean:
	rm *.o ${TARGET}




