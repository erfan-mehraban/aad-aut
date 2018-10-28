def reduce(a, b):
    minimum = min(a, b)
    maximum = max(a, b)
    step = maximum // minimum
    maximum = maximum % minimum
    return minimum, maximum, step

a, b = input().split()
a = int(a)
b = int(b)

result = 0
while a!=0 and b!=0:
    a, b, step = reduce(a, b)
    result += step

if a == 1 or b == 1:
    print(result-1)
else:
    print("impossible")