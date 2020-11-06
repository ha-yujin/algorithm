# 네트워크 - DFS
def dfs(n,i,computers):
    
    check[i]=True
    for idx in range(n):
        if not check[idx] and computers[i][idx]:
            dfs(n,idx,computers)
    
def solution(n, computers):
    global answer, check
    answer=0
    check=[False]*n
    
    for i in range(n):
        if not check[i]:
            dfs(n,i,computers)
            answer+=1
            
    return answer



# 네트워크 - Union-Find
def find_parent(x, parent): # root 노드 찾기
    
    if parent[x]==x :
        return x
    else:
        parent[x]=find_parent(parent[x],parent) # 경로 단축 위함
        return parent[x]
    
def union(parent,x,y): # 집합 합쳐주기
    
    r1=find_parent(x,parent)
    r2=find_parent(y,parent)
    if r1>r2:
        parent[r1]=r2
    else:
        parent[r2]=r1
    
def solution(n, computers):
    parent = [i for i in range(n)]
    
    for i in range(n):
        for j in range(n):
            if i!=j and computers[i][j]:
                union(parent,i,j)

    # 존재하는 집합 개수 구하기
    answer=set()  
    for i in range(n):
        if parent[i]==find_parent(i,parent):
            answer.add(parent[i])
    return len(answer)