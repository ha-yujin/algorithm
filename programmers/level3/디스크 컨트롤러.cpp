// level3 - 디스크 컨트롤러

/*
	나의 풀이 
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare{
    bool operator()(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, time=0, idx=0;
    priority_queue<vector<int>, vector<vector<int>>, compare> wq;
    
    sort(jobs.begin(),jobs.end()); // 요청 순서대로 정렬
    
    while(idx<jobs.size() || !wq.empty()){
        
        // 현재 시간 전에 요청이 들어온 작업이 있을 경우 대기큐에 넣어줌
        if(idx<jobs.size() && time >= jobs[idx][0]){
            wq.push(jobs[idx++]);
            continue;
        }
        // 대기큐가 비어있지 않을 경우 가장 작업시간이 짧은 작업 실행
        if(!wq.empty()){
            time += wq.top()[1];
            answer+=time-wq.top()[0];
            wq.pop();
        }
        // 대기큐가 비어있을 경우
        else
            time=jobs[idx][0];
    }
    return answer/jobs.size();
}

/* 
	남의 풀이
	vector.erase() : 사용한 원소를 벡터에서 삭제한다.
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0; // 현재까지 작업이 진행된 시간
    int time = 0; // 각각의 작업이 진행되는데 걸린 시간들의 합
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), compare); // 소요시간으로 우선 배열

    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            if(jobs[i][0] <= start) {
                start += jobs[i][1];
                time += start - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }

            if(i == jobs.size()-1) start++;
        }
    }

    answer = time / size;
    return answer;
}