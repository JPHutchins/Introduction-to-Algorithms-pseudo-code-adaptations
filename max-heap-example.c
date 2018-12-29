#include <stdio.h>

void max_heapify(int A[], int i, int length) {
    //define children
    int l = i * 2;
    int r = i * 2 + 1;
    //determine which of A[i], A[l], & A[r] is largest
    int largest;
    if (l <= length && A[l] > A[i]) {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r <= length && A[r] > A[largest]) {
        largest = r;
    }
    //if i == largest we're done - otherwise swap A[i] with A[largest]
    if (largest != i) {
        if (largest == l) {
            int temp = A[l];
            A[l] = A[i];
            A[i] = temp;
	    //recurse down to the node that was switched, since it may not be the root of a max heap anymore
            max_heapify(A, l, length);
        }
        else {
            int temp = A[r];
            A[r] = A[i];
            A[i] = temp;
	    //recurse down to the node that was switched, since it may not be the root of a max heap anymore
            max_heapify(A, r, length);
        }   
    }
    return;
}

int pop_max_heap(int A[], int k, int length) {
    //pop the max item from the list
    //start heapify at index=n/2 and work are way down to index=1
    for (int i = length/2; i>0; i--) {
        max_heapify(A, i, length);
    }
    //we are 1-indexed:
    int max = A[1];
    //pop ... result is that A may no longer be a max heap
    for (int i=1; i<length; i++) {
        A[i] = A[i+1];
    }
    return max;
}
//geeks for geeks tests https://practice.geeksforgeeks.org/problems/k-largest-elements/0
int main() {
	int t, k, n, A[1000];
	
	  scanf("%d", &t);
	  while (t--) {
		  scanf("%d %d", &n, &k);
		  //might as well 1-index it on input
		  for (int i=1; i<=n; i++) {
			  scanf("%d", &A[i]);
		  }	
		  while (k > 0) {
		      int max = pop_max_heap(A, k, n);
		      printf("%d ", max);
		      k--;
		      //decrement n by one since we popped the max item off the heap
		      n--;
		  }
		  printf("\n");
	  }
	return 0;
}
