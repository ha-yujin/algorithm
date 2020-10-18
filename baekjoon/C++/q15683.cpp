// 15683번. 감시

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map, visited;
vector<pair<int, int>> cctv;
int minValue = 987654321;
int M, N;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void check(int row, int col, int dir, int i) { // i=1 감시 , i=-1 복구

	while (true) { // 한칸씩 이동하며 감시할 수 있는지 확인

		row += dy[dir];
		col += dx[dir];
		if (row < 0 || row >= M || col < 0 || col >= N) break;
		if (visited[row][col] == 6)break;
		visited[row][col] += i;
	}
}
void monitor(int idx, int dir, int i) {

	int row = cctv[idx].first;
	int col = cctv[idx].second;
	int number = map[row][col];

	// cctv 종류에 따라 감시
	if (number == 1) {

		check(row, col, dir, i);
	}
	else if (number == 2) {

		check(row, col, dir, i);
		check(row, col, (dir + 2) % 4, i);
	}
	else if (number == 3) {

		check(row, col, dir, i);
		check(row, col, (dir + 1) % 4, i);
	}
	else if (number == 4) {

		check(row, col, dir, i);
		check(row, col, (dir + 1) % 4, i);
		check(row, col, (dir + 2) % 4, i);
	}
	else if (number == 5) {

		check(row, col, dir, i);
		check(row, col, (dir + 1) % 4, i);
		check(row, col, (dir + 2) % 4, i);
		check(row, col, (dir + 3) % 4, i);
	}
}
void solve(int idx) {

	//cnt개의 cctv 확인 후, cnt+1개째 cctv를 확인한다.
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) cnt++;
			}
		}
		minValue = min(minValue, cnt);
		return;
	}
	else { // cnt번째 cctv 확인
		for (int i = 0; i < 4; i++) { // 해당 cctv를 4방향으로 회전하면서

			monitor(idx, i, 1); // 회전
			solve(idx + 1); // 다음 cctv 확인
			monitor(idx, i, -1); // 다시 원상복귀
		}
	}
}
int main() {

	scanf_s("%d %d", &M, &N);
	map = vector<vector<int>>(M, vector<int>(N, 0));
	visited = vector<vector<int>>(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &map[i][j]);
			visited[i][j] = map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv.push_back({ i,j });
			}
		}
	}

	if (cctv.size() != 0) {
		solve(0);
	}
	else {
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) cnt++;
			}
		}
		minValue = cnt;
	}

	printf("%d", minValue);
}