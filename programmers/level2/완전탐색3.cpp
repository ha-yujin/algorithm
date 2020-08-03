// level2 - 카펫

/* 나의 풀이 */
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int i,j;
    int total = brown+yellow;
    bool res = false;
    for(i=total-1;i>=3;i--){ // 가로 길이
        if(total%i==0){
            j=total/i; // 세로 길이
            if(j>=3 && j<=i){
                res = ((i-2)*(j-2)==yellow);
            }
        }
        if(res){
            answer.push_back(i);
            answer.push_back(j);
            break;
        }      
    }
    return answer;
}

/* 
	남의 풀이
    : 방정식을 이용해 수식적으로 접근했다. 또한 w, h가 모두 자연수라는 점을 이용
 */
vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while(w >= h){
        if(w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}