from sys import stdin
def _merge(arr, start_index, end_index):
    l = start_index
    r = (end_index+start_index)//2+1
    result = 0
    sorted_arr = [0]* (end_index-start_index+1)
    sorted_index = 0
    while l <= (end_index+start_index)//2 and r <= end_index:
        if int(arr[l]) >= int(arr[r]):
            sorted_arr[sorted_index] = arr[r]
            sorted_index += 1
            result += (end_index+start_index)//2 - l +1
            result = result%1000000007
            r += 1
        else:
            sorted_arr[sorted_index] = arr[l]
            sorted_index += 1
            l += 1
    # while l <= (end_index+start_index)//2:
    #     sorted_arr[sorted_index] = arr[l]
    #     sorted_index += 1
    #     l += 1
    sorted_arr[sorted_index:] = arr[l:(end_index+start_index)//2+1]
    sorted_index += (end_index+start_index)//2 -l +1
    # while r <= end_index:
    #     sorted_arr[sorted_index] = arr[r]
    #     sorted_index += 1
    #     r += 1
    sorted_arr[sorted_index:] = arr[r:end_index+1]
    sorted_index += end_index -r +1
    # for i in range(start_index, end_index+1):
    #     arr[i] = sorted_arr[i-start_index]
    arr[start_index:end_index+1] = sorted_arr
    return result

def merge_sort(arr, start_index, end_index):
    if end_index==start_index:
        return 0
    half_left_result = merge_sort(arr, start_index, (end_index+start_index)//2)
    half_right_result = merge_sort(arr, (end_index+start_index)//2+1, end_index)
    merge_result = _merge(arr, start_index, end_index)
    # print(merge_result + half_right_result + half_left_result, start_index, end_index)
    return merge_result%1000000007 + half_right_result%1000000007 + half_left_result%1000000007

def main():
    # a = [0, 2, 1, 10, 4, 6, 5, 3, 7, 9, 8]
    # a = [4, 3, 2, 1]
    # a = [i for i in range(100,0,-1)]
    # a = input().split()

    input()
    a = stdin.readline()[:-1].split()
    print(merge_sort(a, 0, len(a)-1)%1000000007)

main()