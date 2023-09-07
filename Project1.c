#include <stdlib.h>
#include <stdio.h>
#include <time.h>   //for clock function

#define N 10000000
#define min 500000
#define Smax 1000000

int A[N];

//functions
void MergeSort(int *arr, int l, int r, int S);  //arr, start and end index, min subarr size)
void merge(int *arr, int l, int m, int r);  //arr, left, mid, and right index
void insertionSort(int arr[], int left, int right); //arr, left and right index
void arrGeneration(int arr[], int s);  //arr generation of size s

int main(){
    int i;
    double time1, timedif;

    //part (i)
    int S = 100;    //fixed S hypothetical value

    //generating arrays with 500k increment
    for(i = min; i <= N; i+=min){
        arrGeneration(A, i);   //generate arr 1, 2, ...n(20)
        MergeSort(A, 0, i - 1, S); //start, end index of arr
        time1 = clock(); //get initial time
        time1 = time1 / CLOCKS_PER_SEC;
        timedif = (clock()/CLOCKS_PER_SEC) - time1;  //get final time and get diff
        printf("%f ", timedif); //runtime for each arr
    }

    //part (ii)
    int B[1000];    //fixed size input

    //S range from [1, 10, 100...10e6] -> optimal technically arnd 10-100
    arrGeneration(B, 1000);
    for(i = 1; i <= Smax; i *= 10){
        mergeSort(B, 0, 999, i);
        time1 = clock(); //get initial time
        time1 = time1 / CLOCKS_PER_SEC;
        timedif = (clock()/CLOCKS_PER_SEC) - time1;  //get final time and get diff
        printf("%f ", timedif); //runtime for each arr
    }

}

// dataGeneration of 500,000 increment to 10 mil -> 20 arrs
void arrGeneration(int arr[], int arr_size){   //1 arr is sufficient, index data override for increasing sizes
    for(int i = 0; i < arr_size; i++){
        arr[i] = (rand() % (arr_size - 1 + 1)) + 1;  //[rand()%(upper-lower+1)] + lower
    }
}


// mergeSort + merge + insertion 
void MergeSort(int *arr, int l, int r, int S){     //start and end index arr
    if(l < r){    //if at least 2 elements
        int mid = (l + r)/2;      //Calculate middle index

        // Recursively sort two halves
        MergeSort(arr, l, mid, S);
        MergeSort(arr, mid + 1, r, S);

        // Merge the sorted halves
        merge(arr, l, mid, r);      //mid+1 starting index of right half
    }
}


// insertionSort
void insertionSort(int arr[], int left, int right){
    for(int i=left+1; i<=right; i++){
        int curr = arr[i];
        int j = i - 1;
        
        while (j>=left && arr[j]>curr){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
}
