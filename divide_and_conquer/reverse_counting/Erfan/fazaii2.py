def _merge(arr, start_index, end_index):
    l = start_index
    r = (end_index+start_index)//2+1
    result = 0
    sorted_arr = []
    while l <= (end_index+start_index)//2 and r <= end_index:
        if int(arr[l]) >= int(arr[r]):
            sorted_arr.append(arr[r])
            result += (end_index+start_index)//2 - l +1
            result = result % 1000000007
            r += 1
        else:
            sorted_arr.append(arr[l])
            l += 1
    while l <= (end_index+start_index)//2:
        sorted_arr.append(arr[l])
        l += 1
    while r <= end_index:
        sorted_arr.append(arr[r])
        r += 1
    for i in range(start_index, end_index+1):
        arr[i] = sorted_arr[i-start_index]
    return result

def merge_sort(arr, start_index, end_index):
    if end_index==start_index:
        return 0
    half_left_result = merge_sort(arr, start_index, (end_index+start_index)//2)
    half_right_result = merge_sort(arr, (end_index+start_index)//2+1, end_index)
    merge_result = _merge(arr, start_index, end_index)
    # print(merge_result + half_right_result + half_left_result, start_index, end_index)
    return (merge_result + half_right_result + half_left_result) % 1000000007

input()
# a = [2, 1, 4, 6, 5, 3, 7]
# a = [4, 3, 2, 1]
# a = [5, 1, 3, 4, 2]
a = input().split()
print(merge_sort(a, 0, len(a)-1))