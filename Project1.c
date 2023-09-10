#include <stdlib.h>
#include <stdio.h>
#include <time.h>   //for clock function
#include <windows.h> //for high-resolution

#define N 10000000
#define Min 500000
#define Smax 1000000

//functions
int MergeSort(int *arr, int l, int r, int S);
int merge(int arr[], int left, int middle, int right);
int insertionSort(int arr[], int left, int right);
void arrGeneration(int *arr, int arr_size);
void printArray(int* arr, int size);

int main()
{
    int i, size, cmp, S;
    double timedif;
    clock_t time1, time2; //should use structure clock_t
    LARGE_INTEGER frequency, start, end;

    //part (i)
    //int S = 30;    //fixed S hypo value

    //generating arrays with 500k increment

    //part (i) & (ii)
    do {
        printf("Input array size: ");
        scanf("%i", &size);
        if (size < 1) break;
        printf("Input threshold value S: ");
        scanf("%i", &S);
        int* arr = (int*)malloc(size * sizeof(int)); //generate the array before time starts counting
        arrGeneration(arr, size);
        printArray(arr, size);
        cmp = 0;
        //printArray(arr, size);
        QueryPerformanceCounter(&frequency);
        QueryPerformanceCounter(&start);
        //time1 = clock(); //get initial time
        //time1 = time1 / CLOCKS_PER_SEC;
        //printf("Starting: %d\n", time1);
        cmp = MergeSort(arr, 0, size - 1, S); //start, end index of arr
        //sleep(1);
        //printArray(arr, size);
        QueryPerformanceCounter(&end);
        //time2 = clock();
        //time2 = time2 / CLOCKS_PER_SEC;
        //printf("Ending: %d\n", time2);
        timedif = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
        //timedif = (time2 - time1) / CLOCKS_PER_SEC;  //get final time and get diff
        printf("Time consumed: %f\n", timedif);
        printf("Number of comparisons: %d\n", cmp);
    } while (1); //loop structure changed to avoid executing when input is smaller than 1

    /*
    //part (ii)
    int* B = arrGeneration(1000);   //fixed arr size
    //S range from [1, 10, 100...10e6] -> optimal technically arnd 10-100
    for(i = 1; i <= Smax; i *= 10){
        time1 = clock(); //get initial time
        time1 = time1 / CLOCKS_PER_SEC;
        MergeSort(B, 0, 999, i);
        timedif = (clock()/CLOCKS_PER_SEC) - time1;  //get final time and get diff
        printf("%f ", timedif); //runtime for each arr
    }
    */
    return 0;
}

// dataGeneration
void arrGeneration(int *arr, int arr_size){   //1 arr is sufficient, index data override for increasing sizes
    for (int i = 0; i < arr_size; i++){
        arr[i] = (rand() % (arr_size - 1 + 1)) + 1;  //[rand()%(upper-lower+1)] + lower
    }
}

// printArray (for testing)
void printArray(int* arr, int size)
{
    int i;
    
    printf("Current Array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}


// mergeSort + merge
int MergeSort(int *arr, int l, int r, int S){     //start and end index arr
    int cmp = 0;
    
    if (l < r)
    {   //if at least 2 elements
        int mid = (l + r)/2;      //Calculate middle index
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        if (mid < S)
        {
            cmp += insertionSort(arr, l, mid);
            cmp += insertionSort(arr, mid + 1, r);
        }
        else
        {
            // Recursively sort two halves
            cmp += MergeSort(arr, l, mid, S);
            cmp += MergeSort(arr, mid + 1, r, S);
        }

        // Merge the sorted halves
        cmp += merge(arr, l, mid, r);      //mid+1 starting index of right half
    }

    return cmp;
}

int merge(int arr[], int left, int middle, int right)
{
    int i, j, k, temp, cmp;

    i = left;
    j = middle + 1;
    k = left;
    cmp = 0;

    while (j <= right && i <= middle)
    {
        if (arr[i] <= arr[j])
        {
            i++; // Move to the next element in the left subarray
        }
        else if (arr[i] > arr[j])
        {
            temp = arr[j]; 

            for (k = j; k > i; k--) // Shift elements in the left subarray to make space for the smaller element
            {
                arr[k] = arr[k - 1];
            }

            arr[i] = temp; // Place the smaller element in its correct position in the left subarray
            i++;
            j++;
            middle++;      // Increment the middle index to account for the shifted elements
        }
        cmp ++;
    }

    return cmp;
}

// insertionSort
int insertionSort(int arr[], int left, int right)
{
    int cmp = 0;

    for (int i=left+1; i<=right; i++){
        int curr = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > curr)
        {
            arr[j+1]=arr[j];
            j--;
            cmp++;
        }
        arr[j+1]=curr;
    }

    return cmp;
}
