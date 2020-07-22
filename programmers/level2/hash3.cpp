// level2 - 위장
/*
   본 문제의 의도는 해시를 사용하는 것이다.
   mySol) 먼저 모든 옷의 조합수를 계산할 수 있는 방법을 수학적으로 생각해보았다.
   (옷A 종류+1) * (옷B 종류+1) *... -1을 하면 전체 조합의 수가 나온다.
   이를 구현하기 위해 필요한 것은 옷 종류별 의상의 수이다.
   따라서 이를 위해 map 컨테이너를 이용해 key를 옷의 종류, value를 개수로 저장했다.
*/
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, int> type;
	for (int i = 0; i < clothes.size(); i++) {
		type[clothes[i][1]]++;
	}

	for (auto it = type.begin(); it != type.end(); it++) {
		answer *= (it->second + 1);
	}
	answer -= 1;
	return answer;
}