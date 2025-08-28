def BinarySearch(arr: list[int], target: int) -> int:
    start, end = 0, len(arr) - 1
    while(start<=end):
        mid = start + (end-start)//2
        if(arr[mid] == target):
            return mid
        else:
            if(arr[mid] > target):
                end = mid-1
            else:
                start = mid+1
    return -1

if __name__ == "__main__":
    arr = [11, 20, 25, 37] 
    print(BinarySearch(arr, 11))