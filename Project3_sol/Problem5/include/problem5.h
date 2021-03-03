#include<stdbool.h>

#include "Single_linked_list.h" //You can use function & node in Single_linked_list.h

typedef struct node_Q {
  node_t *head; //node_t -> node in Single_linked_list.h
  node_t *tail;
  int count;
} node_q;
node_q *Queue;
bool Enqueue(node_q *Queue, int value);
int Dequeue(node_q *Queue);
void pererror_function_queue(int error_code);





