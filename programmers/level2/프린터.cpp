// level2 - 프린터

/*
	나의 풀이 
	priority와 index를 pair로 deque에 저장했다. 
	저장한 후 맨 앞 원소를 pop하면서 priority가 최고인 경우에는 pop하고, 최고가 아닌 경우에는 pop하고 다시 push해줌
*/
#include <string>
#include <vector>
#include <deque>
using namespace std;

bool isMax(deque<pair<int,int>> list, int num){
    
    for(int i=0;i<list.size();i++){
        if(list[i].first>num) return false;
    }
    return true;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> list;
    
    for(int i=0;i<priorities.size();i++){
        list.push_back(make_pair(priorities[i],i));
    }
    
    int num = list.front().first;
    int index = list.front().second;
    while(true){
        if(isMax(list,num)){
            if(index==location) break;
        }
        else{
            list.push_back(make_pair(num,index));            
        }
        list.pop_front();
        num=list.front().first;
        index=list.front().second;
    }
    return priorities.size()-(list.size()-1);
}

/* 
	남의 풀이
	먼저 skill_trees 중에서 skill에 포함된 문자들만 뽑아서 vector에 넣었다.
	이때 skill의 문자열 순서로 비교했다는 것이 키 포인트!!
	그리고 이를 skill과 비교하면서 순서가 일치하는 경우에만 answer를 증가시켰다.
 */
