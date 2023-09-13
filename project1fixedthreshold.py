import random
import time

N = 10000000
Min = 500000
S = 50
X = 10000000
maxarrsize = 50000

def merge_sort(arr, l, r):
    cmp = 0
    if l < r:
        mid = (l + r) // 2
        if mid < S:
            cmp += insertion_sort(arr, l, mid)
            cmp += insertion_sort(arr, mid + 1, r)
        else:
            cmp += merge_sort(arr, l, mid)
            cmp += merge_sort(arr, mid + 1, r)
        cmp += merge(arr, l, mid, r)
    return cmp

def merge(arr, left, middle, right):
    i, j, k, temp, cmp = left, middle + 1, left, 0, 0
    while j <= right and i <= middle:
        if arr[i] <= arr[j]:
            i += 1
        else:
            temp = arr[j]
            for k in range(j, i, -1):
                arr[k] = arr[k - 1]
            arr[i] = temp
            i += 1
            j += 1
            middle += 1
        cmp += 1
    return cmp

def insertion_sort(arr, left, right):
    cmp = 0
    for i in range(left + 1, right + 1):
        j = i
        while j > left and arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            j -= 1
            cmp += 1
    return cmp

def generate_array(arr_size):
    return [random.randint(1, X) for _ in range(arr_size)]

def print_array(arr):
    print("Current Array:", arr)

def main():
    for c in range(1, maxarrsize + 1):
        arr = generate_array(c)
        
        cmp = 0
        start_time = time.perf_counter()
        cmp = merge_sort(arr, 0, c - 1)
        end_time = time.perf_counter()
        
        timedif = end_time - start_time
        print("size:", c)
        print("Time consumed:", timedif)
        print("Number of comparisons:", cmp)

if __name__ == "__main__":
    main()
