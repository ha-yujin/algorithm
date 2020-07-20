// level1 - 완주하지 못한 선수
/* 본 문제의 의도는 해시를 사용하는 것이나 해시가 아닌 정렬을 이용해 풀이함
   처음에는 이중 포문을 이용해 participant와 completion을 하나씩 비교하는 코드를 짰으나
   효율성 점수가 낮아 해당 방법을 이용했다. 
   두 벡터를 문자열로 정리한 후 비교하면 더 쉽게 찾아낼 수 있다.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < participant.size(); i++) {
		if (participant[i] != completion[i])
		{
			answer = participant[i];
			break;
		}
	}
	return answer;
}