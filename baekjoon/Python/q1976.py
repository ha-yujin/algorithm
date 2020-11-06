# 여행 가자
def find_parent(x):

    if parent[x]==x:
        return x
    else:
        parent[x]=find_parent(parent[x])
        return parent[x]

def union(x,y):

    r1 = find_parent(x)
    r2 = find_parent(y)

    if r1 > r2:
        parent[r1]=r2
    else:
        parent[r2]=r1

def check(x,y):

    r1 = find_parent(x)
    r2 = find_parent(y)

    if r1 == r2: return True
    else: return False

n = int(input())
m = int(input())

info = [ list(map(int,input().split())) for _ in range(n)]
plan = list(map(int,input().split()))

parent = [i for i in range(n)]

for i in range(n):
    for j in range(n):
        if i!=j and info[i][j]:
            union(i,j)

ans=True
start = plan[0]-1
for i in range(1,len(plan)):
    if check(start,plan[i]-1):
        start=plan[i]-1
    else:
        ans=False
        break
if ans: print("YES")
else: print("NO")