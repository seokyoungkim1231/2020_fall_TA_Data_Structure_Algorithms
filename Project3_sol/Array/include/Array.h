#include<stdbool.h>

//Parameter
#define MAX_SIZE 100

int *List;

//Function prototype
bool insert(int *L, int X);
bool delete(int *L, int X);
bool   find(int *L, int X);
int  findkth(int *L, int X);
void printlist(int *L);
bool isEmpty(int *L);
bool makeEmpty(int *L);


