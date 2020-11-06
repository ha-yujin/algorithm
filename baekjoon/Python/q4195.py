# 친구 네트워크 - Union Find

def find_parent(x):

    if parent[x]==x:
        return x
    else:
        parent[x]=find_parent(parent[x])
        return parent[x]

def union(x,y):

    r1 = find_parent(x)
    r2 = find_parent(y)

    if r1 != r2:
        parent[r2]=r1
        number[r1]+=number[r2]     
    answer.append(number[r1])


t = int(input())
answer=[]
for _ in range(t):

    f = int(input())
    relation = [ list(map(str,input().split())) for _ in range(f)]
    
    parent={}
    number={}

    for x in relation:
        
        if x[0] not in parent:
            parent[x[0]]=x[0]
            number[x[0]]=1
        if x[1] not in parent:
            parent[x[1]]=x[1]
            number[x[1]]=1

        union(x[0],x[1])

for ans in answer:
    print(ans)