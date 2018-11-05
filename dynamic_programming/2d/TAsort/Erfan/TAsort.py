def is_sorted(arr, l, r):
    for i in range(r-l-1):
        if arr[i+l] > arr[i+l+1]:
            return False
    return True

def TAsort(arr, l, r):
    if is_sorted(arr, l, r):
        return 1
    mid = (l+r)//2
    result = TAsort(arr, l, mid) + TAsort(arr, mid, r) + 1
    arr[l:r].sort()
    return result

input_count, test_count = input().split()
input_list = [0] * int(input_count)
for index, item in enumerate(input().split()):
    input_list[index] = int(item)
for _ in range(int(test_count)):
    input_copy = input_list[:]
    s, e = input().split()
    print( TAsort(input_copy, int(s)-1, int(e)-1) )