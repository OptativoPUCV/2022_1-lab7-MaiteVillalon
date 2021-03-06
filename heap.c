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
    pq->capac = (pq->capac * 2 ) + 1;
    pq->heapArray = (heapElem*) realloc(pq->heapArray, (pq->capac)*sizeof(heapElem));
  }

  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size ].priority = priority;
  pq->size = pq->size +1;

  
  for ( int i = pq->size ; i >= 0 ; i--)
    {
      int posActual = i - 1;
      int posPadre = (posActual-1)/2;
      
      if (pq->heapArray[posPadre].priority < pq->heapArray[posActual].priority)
      {
        int auxPrio = pq->heapArray[posPadre].priority;
        void * auxData = pq->heapArray[posPadre].data;
        pq->heapArray[posPadre].priority = pq->heapArray[posActual].priority;
        pq->heapArray[posPadre].data = pq->heapArray[posActual].data;

        pq->heapArray[posActual].priority = auxPrio;
        pq->heapArray[posActual].data = auxData;

      }
    }
  
}


void heap_pop(Heap* pq)
{ 
  
  int tamano = pq->size;
  int auxPrior = pq->heapArray[tamano-1].priority;
  void *auxData = pq->heapArray[tamano-1].data;

  pq->heapArray[tamano].priority = pq->heapArray[0].priority;
  pq->heapArray[tamano].data = pq->heapArray[0].data;

  pq->heapArray[0].priority = auxPrior;
  pq->heapArray[0].data = auxData;
  pq->size = pq->size-1;

  int i = 0;
  while (  i < pq->size )
  {
    int posPrimHij= (i*2) + 1;
    int posSegHij = (i*2) + 2;
    int auxPrior2 = pq->heapArray[i].priority;
    void *auxData2 = pq->heapArray[i].data;

    if (posPrimHij > pq->size)
    {
      pq->heapArray[posPrimHij].priority = 0;
    }
    if (posSegHij > pq->size)
    {
      pq->heapArray[posSegHij].priority = 0;
    }
    
    
    if (pq->heapArray[posPrimHij].priority > pq->heapArray[posSegHij].priority)
    {
      if (pq->heapArray[posPrimHij].priority > pq->heapArray[i].priority)
      {
          pq->heapArray[i].priority = pq->heapArray[posPrimHij].priority;
          pq->heapArray[i].data = pq->heapArray[posPrimHij].data;

          pq->heapArray[posPrimHij].priority = auxPrior2;
          pq->heapArray[posPrimHij].data = auxData2;
          i = posPrimHij; 
      }
      else break;
    }
    else if (pq->heapArray[posSegHij].priority > pq->heapArray[posPrimHij].priority)
    {
      if (pq->heapArray[posSegHij].priority > pq->heapArray[i].priority)
      {
          pq->heapArray[i].priority = pq->heapArray[posSegHij].priority;
          pq->heapArray[i].data = pq->heapArray[posSegHij].data;

          pq->heapArray[posSegHij].priority = auxPrior2;
          pq->heapArray[posSegHij].data = auxData2;
          i = posSegHij; 
      } 
      else break;
    }
    else
    {
      break;
    }
  
  }


  
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
