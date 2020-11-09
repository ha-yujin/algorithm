def solution(brown, yellow):
    answer = []
    total = brown+yellow
    for i in range(2,total):
        if total%i==0:
            if 2*(i+total//i) == brown+4:
                return [total//i,i]