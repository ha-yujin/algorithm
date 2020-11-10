def oneDifferent(a,b): # 변환 가능한 단어인지 check
    
    cnt=0
    for first, second in zip(a,b):
        if first != second:
            cnt+=1
            if cnt>1: return False
    return True

def dfs(begin, target, words, visit, answer, cnt):
    
    if target == begin:
        if cnt < answer[0]:
            answer[0]=cnt
        return
    
    for i in range(len(words)):
        if oneDifferent(begin,words[i]):
            if words[i] not in visit:
                visit.append(words[i])
                dfs(words[i],target,words,visit,answer,cnt+1)
                visit.remove(words[i])
                
def solution(begin, target, words):
    
    answer =[98776543]
    visit=[begin]
    
    if target not in words:
        return 0
    dfs(begin,target,words,visit,answer,0)
    
    return answer[0]