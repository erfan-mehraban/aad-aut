a, b = map(int, input().split())
if (a%b==0 or b%a==0) and a>1 and b>1:
    print('impossible')
else:
    M = max(a, b)
    m = min(a, b)
    n= M//m
    c= M%m
    while c!=0:
        M= m
        m= c
        n= n+M//m
        c= M%m
    print(n-1)
