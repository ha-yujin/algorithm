from collections import defaultdict
def solution(tickets):

    routes = dict()
    test = defaultdict(list)
    for k, v in tickets:
        test[k].append(v)
    print(test)
    for start, end in tickets:
        routes[start] = routes.get(start, []) + [end]  

    for r in routes.keys():
        routes[r].sort(reverse=True)

    # DFS 알고리즘으로 path를 만들어줌.
    st = ["ICN"]
    path = []
    
    while st:
        top = st[-1]

        if top not in routes or len(routes[top]) == 0:
            path.append(st.pop())
        else:
            st.append(routes[top][-1])
            routes[top] = routes[top][:-1]

    # 만든 path를 거꾸로 돌림.
    answer = path[::-1]
    return answer
