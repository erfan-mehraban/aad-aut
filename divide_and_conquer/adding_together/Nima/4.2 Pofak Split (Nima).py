M, S = sorted(int(x) for x in input().split())

ans = 0
while M:
    ans += S // M
    S = S % M
    M,S = S,M

if S == 1:
    print(ans - 1)
else:
    print("impossible")