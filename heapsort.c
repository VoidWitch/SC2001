#include <stdlib.h>
#include <stdio.h>

//reference
#define N 10000000

int A[N], n;        //int arr and size

void swap(int *a, int *b) {     //swap parent node and child node to maximize heap
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(int a, int size) {
    int l = a;      //largest l index is currently initialized as input root a

    //bit size 1 to left -> times 2 -> check left child(within arr), if larger update largest value
    if ((a<<1) <= size && A[a<<1] > A[l]) l = a<<1;
    //check right child(within arr), if larger, update largest value
    if ((a<<1)+1 <=size && A[(a<<1)+1] > A[l]) l = (a<<1)+1;

    //if parent < child, proceed with swap
    if (A[a] < A[l]) {
        swap(A+a, A+l);
        heapify(l, size);       //make sure remaining sub arr satisfy maximizing heap
    }
}

int delete(int size) {
    int val = A[1];
    A[1] = A[size];
    A[size] = -1;
    heapify(1, size);
    return val;
}

int main() {
    scanf("%d", &n);    //n arr size
    //generating array inputs
    for (int i=1; i<=n; i++) scanf("%d", A+i);

    //generating maximizing heap starting from last child
    for (int i=n>>1; i; i--) heapify(i, n);

    for (int size=n; size; size--)
        A[size] = delete(size);     //replacing first and last element

    for (int i=1; i<=n; i++) printf("%d ", A[i]);
        printf("\n");
}
