// level2 - H-index
/* 
	먼저 배열을 정렬한 후 h값을 배열의 최대값으로 설정한 후,
	1씩 감소하며 찾아나간다. 인용된 횟수가 h이상인 것의 개수를 찾아 리턴한다.
	!!!!!! H 인덱스의 뜻을 이해하지 못해서 틀림.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int h, max = -1;

	sort(citations.begin(), citations.end());

		h=citations[citations.size()-1];

		while(true){

			for(int i=citations.size()-1;i>=0;i--){
				if(citations[i]>h)
					answer++;
			}
			if(h<=answer && answer > max)
			{
				return answer;
			}
			answer=0;
			h--;
		}

	return answer;
}