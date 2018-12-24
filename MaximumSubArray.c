#include <stdio.h>
#include <stdlib.h>

//adapated pseudo code from "Introduction to Algorithms"

int* findMaxCrossing(int A[], int low, int mid, int high) {
    
    int leftSum = -2147483647;
    int sum = 0;
    int maxLeft = mid;
    for (int i=mid; i>=low; i--) {
        sum = sum + A[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightSum = -2147483647;
    sum = 0;
    int maxRight = high;
    for (int i=mid+1; i<=high; i++) {
        sum = sum + A[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }
    
    static int tmp[3];
    tmp[0] = maxLeft; tmp[1] = maxRight; tmp[2] = leftSum + rightSum;
    return tmp;
}


int* findMaxSubArray(int A[], int low, int high) {
    //base case
    if (high==low) {
        static int B[3];
        B[0] = low; B[1] = high; B[2] = A[low];
        return B;
    }
    
    else {
        //divide
        mid = (low + high) / 2;
        //conquer
        int* L;
        L = findMaxSubArray(A, low, mid);
        int* R;
        R = findMaxSubArray(A, mid+1, high);
        //merge
        int* C;
        C = findMaxCrossing(A, low, mid, high);
        if (L[2] >= R[2] && L[2] >= C[2]) {
            return L;
        }
        else if (R[2] >= L[2] && R[2] >= C[2]) {
            return R;
        }
        else {
            return C;
        }
    }
}

//run geeksforgeeks tests
int main() {
    int t, n, arr[1000];
	
	  scanf("%d", &t);
	  while (t--) {
		  scanf("%d", &n);
		  for (int i=0; i<n; i++) {
			  scanf("%d", &arr[i]);
		  }	
		  int* S;
		  S = findMaxSubArray(arr, 0, n-1);
		  for (int i=S[0]; i<=S[1]; i++) {
			  printf("%d ", arr[i]);
		  }
		  printf("\n");
	  }
	return 0;
}
