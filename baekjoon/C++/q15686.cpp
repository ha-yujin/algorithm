// 15686번. 치킨 배달
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int map[50][50];
vector<pair<int, int>> chicken, home, selected;
int best = 1000000;

void dfs(int cnt) {

	if (selected.size() == m) { // 치킨집 M개 다 고름

		int dist = 0;
		for (int i = 0; i < home.size(); i++) {
			int min_dist = 10000;
			for (int j = 0; j < selected.size(); j++) {
				min_dist = min(min_dist, abs(selected[j].first - home[i].first) + abs(selected[j].second - home[i].second));
			}
			dist += min_dist;
		}
		best = min(best, dist);
		return;
	}

	for (int i = cnt; i < chicken.size(); i++) {
		
		selected.push_back({ chicken[i].first,chicken[i].second });
		dfs(i + 1);
		selected.pop_back();
	}
}
int main() {

	scanf_s("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &map[i][j]);
			if (map[i][j] == 2) chicken.push_back({ i,j });
			if (map[i][j] == 1) home.push_back({ i,j });
		}
	}
	dfs(0);

	printf("%d", best);
}