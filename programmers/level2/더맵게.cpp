// level2 - 더맵게

/*
	나의 풀이 
    priority Queue를 이용해 minHeap 구현
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(pq.top()<K){
        
        if(pq.size()==1) return -1;
        int tmp=pq.top();
        pq.pop();
        tmp+=2*pq.top();
        pq.pop();
        pq.push(tmp);
        answer++;
    }
    return answer;
}

/* 
	남의 풀이
    minHeap을 초기화 하는 부분
 */
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

