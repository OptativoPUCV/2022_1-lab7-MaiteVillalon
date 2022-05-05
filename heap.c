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
  int i = 0;
  if (pq->size == 0) return NULL;
    
  else
  {
    if (pq->heapArray[i].data != NULL)
      return (pq->heapArray[i].data);
  }

  return NULL;
  
}



void heap_push(Heap* pq, void* data, int priority)
{

  if (pq->size == pq->capac)
  {
    pq = realloc(pq, (pq->capac *2) + 1);
  }
  else
  {
    pq->heapArray[pq->size + 1].data = data;
    pq->heapArray[pq->size + 1].priority = priority;
    pq->size = pq->size +1;
  }
  
  for ( int i = pq->size ; i >= 0 ; i--)
    {
      int posPadre = (i-1)/2;
      int posActual = i - 1;
      
      if (pq->heapArray[i - 1].priority < pq->heapArray[i].priority)
      {
        int auxPrio = pq->heapArray[posPadre].priority;
        void * auxData = pq->heapArray[posPadre].data;
        pq->heapArray[posPadre].priority = pq->heapArray[posActual].priority;
        pq->heapArray[posPadre].data = pq->heapArray[posActual].data;

        pq->heapArray[posActual].priority = auxPrio;
        pq->heapArray[posActual].data = auxData;

      }
      else break;
    }
  
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
