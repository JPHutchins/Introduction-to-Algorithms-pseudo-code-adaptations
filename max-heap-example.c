#include <stdio.h>

void max_heapify(int A[], int i, int length) {
    int l = i * 2;
    int r = i * 2 + 1;
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
    if (largest != i) {
        if (largest == l) {
            int temp = A[l];
            A[l] = A[i];
            A[i] = temp;
            max_heapify(A, l, length);
        }
        else {
            int temp = A[r];
            A[r] = A[i];
            A[i] = temp;
            max_heapify(A, r, length);
        }   
    }
    return;
}

int pop_max_heap(int A[], int k, int length) {
    for (int i = length/2; i>0; i--) {
        max_heapify(A, i, length);
    }
    int max = A[1];
    //pop
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
		      n--;
		  }
		  printf("\n");
	  }
	return 0;
}
