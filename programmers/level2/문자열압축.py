def solution(s):
    length = []
    result = ""

    if len(s) == 1:
        return 1

    # 몇개씩 압축할 것인지
    for cut in range(1, len(s) // 2 + 1): 
        count = 1
        tempStr = s[:cut] 
        for i in range(cut, len(s), cut):
            if s[i:i+cut] == tempStr: # 같은 문자열일 경우
                count += 1
            else: # 다른 문자열일 경우
                # 17~19 라인 다음과 같이 축약 가능
                # result += (str(count)+tempStr) if count > 1 else tempStr  
                if count == 1:
                    count = ""
                result += str(count) + tempStr
                tempStr = s[i:i+cut]
                count = 1

        if count == 1:
            count = ""
        result += str(count) + tempStr
        length.append(len(result))
        result = ""

    return min(length)