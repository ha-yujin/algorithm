// level2 - 기능개발
/*
   나의 풀이
   먼저 기능별로 진도가 100%가 될 때까지 몇일이 걸리는지 계산을 해서 큐에 넣었다.
   큐에는 기능별로 걸리는 날 수가 저장된다.
   먼저 배포가 되어야하는 것부터 처리해야하므로 큐를 사용해 앞의 기능부터 비교를 시작함.
   더 오래 걸리는 기능을 만나면 그동안의 값을 저장해주는 것이다.
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> tmp;
    int day, cnt=0;
    for(int i=0;i<progresses.size();i++){
        day = (100-progresses[i]);
        if(day%speeds[i]==0) day=day/speeds[i];
        else day = day/speeds[i]+1;
        tmp.push(day);
    }
    int a=tmp.front();

    while(!tmp.empty()){

        if(tmp.front()>a){
            a=tmp.front();
            answer.push_back(cnt);
            cnt=0;
        }
        else{
            tmp.pop();
            cnt++; 
        }
    }
    answer.push_back(cnt);
    return answer;
}

/*
	남의 풀이
	내 풀이에서 반복문 2개를 사용해 따로 계산한 것을 반복문 1개로 모두 계산함.
	day를 계산하면서 지금까지의 max_day보다 큰 작업일 경우 vector에 추가했다.
	만약 max_day보다 더 적게 걸리는 작업일 경우 vector의 back을 이용해 이전에 저장한
	기능 수에서 증가시켰다.
	vector 라이브러리의 기본 메소드들을 잘 활용함
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}