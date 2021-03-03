#Optimization Level
CFLAG = -O0 -g

#Include Directory
INCDIR = -I "include"

#Object File Directory
OBJDIR = ./

#Object File List
OBJ = \
./Single_linked_list.o \
./main.o

#Target Name
TARGET = compile

${TARGET} : ${OBJ}
	gcc -o ${TARGET} ${OBJ} ${CFLAG} ${INCDIR}

${OBJDIR}Single_linked_list.o: src/Single_linked_list.c
	gcc src/Single_linked_list.c ${INCDIR} ${CFLAG} -c -o $@

${OBJDIR}main.o: src/main.c
	gcc src/main.c ${INCDIR} ${CFLAG} -c -o $@

clean:
	rm *.o ${TARGET}




