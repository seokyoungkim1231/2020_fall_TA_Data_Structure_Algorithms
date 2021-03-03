#Optimization Level
CFLAG = -O0

#Include Directory
INCDIR = -I "include"

#Object File Directory
OBJDIR = ./

#Object File List
OBJ = \
./Array.o \
./main.o

#Target Name
TARGET = compile

${TARGET} : ${OBJ}
	gcc -o ${TARGET} ${OBJ} ${CFLAG} ${INCDIR}

${OBJDIR}Array.o: src/Array.c
	gcc src/Array.c ${INCDIR} ${CFLAG} -c -o $@

${OBJDIR}main.o: src/main.c
	gcc src/main.c ${INCDIR} ${CFLAG} -c -o $@

clean:
	rm *.o ${TARGET}




