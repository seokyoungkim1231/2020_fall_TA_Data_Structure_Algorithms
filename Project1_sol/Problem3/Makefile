#Optimization Level
CFLAG = -O2 -g

#Include Directory
INCDIR = -I "include"

#Object File Directory
OBJDIR = ./

#Object File List
OBJ = \
./problem3.o \
./main.o

#Target Name
TARGET = compile

${TARGET} : ${OBJ}
	gcc -o ${TARGET} ${OBJ} ${CFLAG} ${INCDIR}

${OBJDIR}problem3.o: src/problem3.c
	gcc src/problem3.c ${INCDIR} ${CFLAG} -c -o $@

${OBJDIR}main.o: src/main.c
	gcc src/main.c ${INCDIR} ${CFLAG} -c -o $@

clean:
	rm *.o ${TARGET}




