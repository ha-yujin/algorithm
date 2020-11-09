from itertools import permutations

def countPrime(num):
    ans=0
    for n in num:
        cnt=0
        for i in range(2,n):
            if n%i==0:
                count+=1
                break
        if n>=1 and count==0:
            ans+=1
    return ans

def solution(n):
    num = set()
    for i in range(len(numbers)):
        num |= set(map(int,map("".join,permutations(list(n),i+1))))

    return  countPrime(num)
