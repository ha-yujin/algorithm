# import itertools
# import heapq
# a='1234'
# arr = list(map(int,map(''.join,itertools.permutations(a))))
# print(arr)

# b = '01234'
# arr2 = list(map(int,map(''.join,itertools.permutations(b,2))))
# print(arr2)

# b = [1,2,3,4]
# arr3 = list(map(int,map(''.join,itertools.permutations(map(str,b),2))))
# print(arr3)
from collections import deque

def dfs(start):
    
    print(start,end=' ')
    visited[start]=True
    
    for e in info[start]:
        if not visited[e]:
            dfs(e)

def bfs(start):

    q = deque([start])
    visited[start]=True

    while q:
        node = q.popleft()            
        print(node,end= ' ')

        for e in info[node]:
            if not visited[e]:
               visited[e]=True
               q.append(e)


n,m,v = map(int,input().split())
info = [[] for _ in range(n+1)]
visited=[False]*(n+1)
for _ in range(m):
    a, b = map(int,input().split())
    info[a].append(b)
    info[b].append(a)

for i in info:
    i.sort()

dfs(v)
print()
visited = [False]*(n+1)
bfs(v)