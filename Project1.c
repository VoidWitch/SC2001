include <studio.h>
//merge insertion hybrid
/*

*/



// dataGeneration
//max value of X is 10 million -> highest number of array elements is 10 million
//array size, lowest 1000, increment by 500,000, max 10 million, 21 arrays



// mergeSort + merge
void MergeSort(int *arr, int l, int r){     //start and end index arr
    if(l < r){    //if at least 2 elements
        int mid = (l + r)/2;      //Calculate middle index

        // Recursively sort two halves
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);

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


// main
//insertion nested within merge with if(s<n) branch -> S range from [0, 1e6] -> eg. 1, 10, 100, 1000...