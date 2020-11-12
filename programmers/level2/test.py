import itertools
import heapq
a='1234'

arr = list(map(''.join,itertools.permutations(a)))

b = '01234'

arr2 = list(map(int,map(''.join,itertools.permutations(b,2))))
print(arr2)

b = [0,1,2,3,4]

arr3 = list(map(int,map(''.join,itertools.permutations(map(str,b),2))))
print(arr3)

heapq.heapify(arr3)
print(arr3)