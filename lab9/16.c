// FIND THE KTH LARGEST ELEMENT OF A MAX HEAP 

#include <stdio.h>
#include <stdlib.h>

int kthLargest(int* heap, int k) 
{
   int auxHeap[k];
   int i;
   for (i = 0; i < k; i++) {
       auxHeap[i] = INT_MIN;
   }

   for (i = 0; i < k; i++) {
       auxHeap[i] = heap[i];
   }


   for (i = k; i < heapSize; i++) {
       int biggest = INT_MIN;
       int j;
       for (j = i - k + 1; j <= i; j++) {
           if (auxHeap[j] > biggest) {
               biggest = auxHeap[j];
           }
       }
       auxHeap[i] = biggest;
   }

   return auxHeap[k - 1];
}


int main() {
   int heap[] = {20, 15, 18, 8, 10, 5, 17};
   int k = 4;
   printf("%d\n", kthLargest(heap, k)); 
   return 0;
}
