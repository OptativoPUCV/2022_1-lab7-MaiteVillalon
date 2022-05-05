#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{

  
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap * nuevo = (Heap*) malloc(sizeof(Heap));
  nuevo->size = 0;
  nuevo->capac = 3;
  nuevo->heapArray = (heapElem *) malloc(3*sizeof(heapElem));

  for (int i = 0 ; i < nuevo->capac ; i++)
  {
    nuevo->heapArray[i].data = NULL;
    nuevo->heapArray[i].priority = 0;
  }
  return nuevo;
}
