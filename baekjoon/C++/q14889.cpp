// 14889번. 스타트와 링크
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s[20][20];
vector<int> start, link;
int best = 1e9;

int getSum(vector<int> team) {

	int res = 0;
	for (int i = 0; i < team.size(); i++) {

		int tmp = team.front();
		team.erase(team.begin());
		for (int j = 0; j < team.size(); j++) {
			res += s[tmp][team[j]];
		}
		team.push_back(tmp);
	}
	return res;
}
void dfs(int pos) {

	if (start.size() == n / 2) {
				
		for (int i = 0; i < n; i++) {
			auto it = find(start.begin(), start.end(), i);
			if (it == start.end()) link.push_back(i);
		}

		// 각 팀의 능력치 합 구하기
		int startS = getSum(start);
		int linkS = getSum(link);
		
		best = min(best, abs(linkS - startS));

		link.clear();

	}
	for (int i = pos; i < n; i++) {
		start.push_back(i);
		dfs(i + 1);
		start.pop_back();
	}
}

int main() {

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &s[i][j]);
	dfs(0);

	printf("%d", best);
}