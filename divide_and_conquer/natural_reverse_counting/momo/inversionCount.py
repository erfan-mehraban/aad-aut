n = int(input())

arr = list(map(int, input().split()))

c = 0
def mergeSort(alist, c):
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]
        c = mergeSort(lefthalf, c)
        c = mergeSort(righthalf, c)

        i=0
        j=0
        k=0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1

            else:
                alist[k]=righthalf[j]
                j=j+1
                c += len(lefthalf)-i
            k=k+1
        if i<len(lefthalf):
            alist[k:] = lefthalf[i:len(lefthalf)]
        if j<len(righthalf):
            alist[k:] = righthalf[j:len(righthalf)]

    return c
a = mergeSort(arr, c)
print(a % 1000000007)
