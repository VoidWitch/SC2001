import random
import time
import ctypes
import csv

def merge_sort(arr, l, r, S):
    cmp = 0
    if l < r:
        mid = (l + r) // 2
        if (mid - l + 1) < S:
            cmp += insertion_sort(arr, l, mid)
        else:
            cmp += merge_sort(arr, l, mid, S)
        if (r - mid + 1) < S:
            cmp += insertion_sort(arr, mid + 1, r)
        else:
            cmp += merge_sort(arr, mid + 1, r, S)
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
    return [random.randint(1, 10000000) for _ in range(arr_size)]

def print_array(arr):
    print("Current Array:", arr)
    
def saveToList(list1,size,S,time,cmp):
    list1[0].append(size)
    list1[1].append(S)
    list1[2].append(time)
    list1[3].append(cmp)
    return list1

def saveToCSV(list1):
    csv_file = "data.csv"
    with open(csv_file, mode='w', newline='') as file:
        writer = csv.writer(file)
        for row in list1:
            writer.writerow(row)
    print(f"Data saved to {csv_file} successfully.")

def manualTesting():
    list1 = [["SizeOfArray"],["ThresholdValue"],["TimeTaken"],["NumberOfComparisons"]]
    while True:
        size = int(input("Input array size: "))
        if size < 1:
            break
        S = int(input("Input threshold value S: "))
        arr = generate_array(size)
        print_array(arr)
        
        cmp = 0
        start_time = time.perf_counter()
        cmp = merge_sort(arr, 0, size - 1, S)
        end_time = time.perf_counter()
        
        timedif = end_time - start_time
        
        saveToList(list1,size,S,timedif,cmp)
        
        print("Time consumed:", timedif)
        print("Number of comparisons:", cmp)
        
    saveToCSV(list1)
    
def fixArraySize():
    list1 = [["SizeOfArray"],["ThresholdValue"],["TimeTaken"],["NumberOfComparisons"]]
    size = int(input("Enter the array size: "))
    arr = generate_array(size)
    S = 0
    while S <= size:
        temp_arr = arr[:]
        cmp = 0
        start_time = time.perf_counter()
        cmp = merge_sort(temp_arr, 0, size - 1, S)
        end_time = time.perf_counter()
        
        timedif = end_time - start_time
        
        saveToList(list1,size,S,timedif,cmp)
        
        print("Time consumed:", timedif, "Number of comparisons:", cmp)
        
        S += 1
        
    saveToCSV(list1)

def fixThresholdValue():
    list1 = [["SizeOfArray"],["ThresholdValue"],["TimeTaken"],["NumberOfComparisons"]]
    S = int(input("Enter the threshold value: "))
    size = S
    i = int(input("Enter the number of times: "))
    while i > 0:
        arr = generate_array(size)
        cmp = 0
        start_time = time.perf_counter()
        cmp = merge_sort(arr, 0, size - 1, S)
        end_time = time.perf_counter()
        
        timedif = end_time - start_time
        
        print("Time consumed:", timedif)
        print("Number of comparisons:", cmp)
        
        size += 1
        i -= 1
    
    saveToCSV(list1)
    
def main():
    while True:
        choice = int(input("Enter 1 for fixed threshold, 2 for fixed array size, 3 for manual testing, 0 to exit. "))
        if choice == 1:
            fixThresholdValue()
        if choice == 2:
            fixArraySize()
        if choice == 3:
            manualTesting()
        if choice == 0:
            break
    
if __name__ == "__main__":
    main()
