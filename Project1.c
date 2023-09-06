include <studio.h>
//merge insertion hybrid



// dataGeneration



// mergeSort



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


// main
