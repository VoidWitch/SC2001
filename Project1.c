#include <stdlib.h>
#include <stdio.h>
#include <time.h>   //for clock function

#define N 10000000
#define min 500000
#define Smax 1000000

//functions
void MergeSort(int *arr, int l, int r, int S);
void merge(int *arr, int l, int m, int r);
void insertionSort(int arr[], int left, int right);
int* arrGeneration(int s);

int main(){
    int i, input;
    double time1, timedif;

    //part (i)
    int S = 30;    //fixed S hypo value

    //generating arrays with 500k increment
    do {
        printf("Input array size: ");
        scanf("%i", &input);
        MergeSort(arrGeneration(input), 0, input - 1, S); //start, end index of arr
        time1 = clock(); //get initial time
        time1 = time1 / CLOCKS_PER_SEC;
        timedif = (clock()/CLOCKS_PER_SEC) - time1;  //get final time and get diff
        printf("%f ", timedif); //runtime for each arr
    } while (input > 0);

    //part (ii)
    int* B = arrGeneration(1000);   //fixed arr size
    //S range from [1, 10, 100...10e6] -> optimal technically arnd 10-100
    for(i = 1; i <= Smax; i *= 10){
        MergeSort(B, 0, 999, i);
        time1 = clock(); //get initial time
        time1 = time1 / CLOCKS_PER_SEC;
        timedif = (clock()/CLOCKS_PER_SEC) - time1;  //get final time and get diff
        printf("%f ", timedif); //runtime for each arr
    }

}

// dataGeneration
int* arrGeneration(int arr_size){   //1 arr is sufficient, index data override for increasing sizes
    int *arr = (int*)malloc(arr_size*sizeof(int));

    for(int i = 0; i < arr_size; i++){
        arr[i] = (rand() % (arr_size - 1 + 1)) + 1;  //[rand()%(upper-lower+1)] + lower
    }
    return arr;
}



// mergeSort + merge
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
