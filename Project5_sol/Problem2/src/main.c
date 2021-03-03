#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "problem2.h"

int main()
{
    FILE *fp_in;
    fp_in = fopen("graph.txt","rt");
    if(fp_in == NULL)
        exit(1);
    graph_input(fp_in);
    printf("DSF\n");
    dfs();
    printf("BSF\n");
    bfs();
}
