// level3 - 베스트 앨범
/* 
	문제를 풀이하기 위해 필요한 정보는 (1) 장르별 재생횟수 순위 (2) 장르내에서 노래별 재생 횟수 순위이다.
	먼저 (1)을 구하기 위해서는 map을 사용했다. key를 "장르명", value를 "재생횟수"로 저장했다.(m1)
	map은 key를 기준으로 정렬이 되기 때문에 (m1)의 key와 value 순서를 바꾸어 저장한 새로운 map(m2)를 생성했다.
	이 때, 오름차순으로 정렬되기 때문에 재생횟수를 음수로 바꾸어 저장했다.
	** 이처럼 key로 장르별 재생횟수를 설정할 수 있는 이유는 제한 사항 중 "모든 장르는 재생횟수가 다르다"는 조건때문이다.

	이제, 장르별 재생횟수 순위를 구했으므로, 각 장르별로 노래 재생 횟수를 구한다.
	이는 노래별로 pair로 노래의 재생횟수, 인덱스를 저장하고 이를 vector에 저장했다.
	pair객체 또한 first 값으로 자동으로 오름차순 정렬이 되기 때문에 따로 정렬할 필요가 없다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <map> 
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> m1;
	map<int, string> m2;

	for (int i = 0; i < genres.size(); i++) {
		m1[genres[i]] += plays[i];
	}

	for (auto it = m1.begin(); it != m1.end(); it++) {
		m2.insert({ -(it->second),it->first });
	} // 장르별 총 재생 수

	for (auto it = m2.begin(); it != m2.end(); it++) {
		vector<pair<int, int>> tmp;
		for (int i = 0; i < genres.size(); i++) {
			if (genres[i] == it->second)
				tmp.push_back(make_pair(-plays[i], i)); // -(노래 재생수), 원래 인덱스
		}
		sort(tmp.begin(), tmp.end());

		if (tmp.size() == 1)
			answer.push_back(tmp[0].second);
		else {
			answer.push_back(tmp[0].second);
			answer.push_back(tmp[1].second);
		}
	}
	return answer;
}