#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "problem1.h"

#define MAX_MAIN 30000

//#define BUBBLE_SORT
#define SELECTION_SORT
//#define INSERTION_SORT
//#define HEAP_SORT
//#define MERGE_SORT
//#define QUICK_SORT

int main()
{
  FILE* fp;
  int *base;
  int i;
  int ans[MAX_MAIN];
  for(i = 0; i < MAX_MAIN; i++)
    ans[i] = i;
  
  #ifdef BUBBLE_SORT
  fp = fopen("./dataset/dataset1.txt","rt");
  base = bubble_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Bubble Pass dataset : dataset1\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }
  fp = fopen("./dataset/dataset2.txt","rt");
  base = bubble_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Bubble Pass dataset : dataset2\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset3.txt","rt");
  base = bubble_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Bubble Pass dataset : dataset3\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }
  #endif
  
  #ifdef SELECTION_SORT
  fp = fopen("./dataset/dataset1.txt","rt");
  base = selection_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Selection Pass dataset : dataset1\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset2.txt","rt");
  base = selection_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Selection Pass dataset : dataset2\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset3.txt","rt");
  base = selection_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Selection Pass dataset : dataset3\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }
  #endif

  #ifdef INSERTION_SORT
  fp = fopen("./dataset/dataset1.txt","rt");
  base = insertion_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Insertion Pass dataset : dataset1\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset2.txt","rt");
  base = insertion_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Insertion Pass dataset : dataset2\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset3.txt","rt");
  base = insertion_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification Insertion Pass dataset : dataset3\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }
  #endif

  #ifdef HEAP_SORT
  fp = fopen("./dataset/dataset1.txt","rt");
  base = heap_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification heap Pass dataset : dataset1\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset2.txt","rt");
  base = heap_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification heap Pass dataset : dataset2\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset3.txt","rt");
  base = heap_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification heap Pass dataset : dataset3\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }
  #endif

  #ifdef MERGE_SORT
  fp = fopen("./dataset/dataset1.txt","rt");
  base = merge_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification merge Pass dataset : dataset1\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset2.txt","rt");
  base = merge_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification merge Pass dataset : dataset2\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset3.txt","rt");
  base = merge_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification merge Pass dataset : dataset3\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }
  #endif

  #ifdef QUICK_SORT

  fp = fopen("./dataset/dataset1.txt","rt");
  base = quick_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification quick Pass dataset : dataset1\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset2.txt","rt");
  base = quick_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification quick Pass dataset : dataset2\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }

  fp = fopen("./dataset/dataset3.txt","rt");
  base = quick_prj4(fp);
  if(memcmp(ans,base,sizeof(int)*MAX_MAIN) == 0)
    printf("Verification quick Pass dataset : dataset3\n");
  else{
    printf("Verification fail\n");
    exit(1);
  }
  #endif


  return 0;
}

