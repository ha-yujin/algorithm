# 집합의 표현 - Union Find

def find_parent(x):

    if parent[x]==x:
        return x
    else:
        parent[x]=find_parent(parent[x])
        return parent[x]

def union(x,y):

    r1 = find_parent(x)
    r2=find_parent(y)
    if r1 > r2:
        parent[r1]=r2
    else:
        parent[r2]=r1

def check(x,y):

    r1= find_parent(x)
    r2=find_parent(y)
    if r1==r2:
        print("YES")
    else:
        print("NO")


n, m = map(int,input().split())

operation = [ list(map(int,input().split())) for _ in range(m)]

parent = [ i for i in range(n+1)]

for op in operation:
    if op[0]==0:
        union(op[1],op[2])
    elif op[0]==1:
        check(op[1],op[2])