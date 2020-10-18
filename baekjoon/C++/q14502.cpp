// 14502번. 연구소
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 8
using namespace std;

int N, M;
int map[MAX][MAX];
int cmap[MAX][MAX];
bool *check;
bool visit[MAX][MAX];
vector<pair<int, int>> virus, zero;
int maxValue = -1;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void copyMap() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cmap[i][j] = map[i][j];
	}
}
void spreadVirus(int row, int col) { // 바이러스 퍼지게한다.

	queue<pair<int, int>> q;
	q.push({ row,col });
	visit[row][col] = true;
	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			if (ty >= 0 && tx >= 0 && ty < N && tx < M) {
				if (!visit[ty][tx] && cmap[ty][tx] == 0) {
					cmap[ty][tx] = 2;
					visit[ty][tx] = true;
					q.push({ ty,tx });
				}
			}
		}
	}
}
int getArea() {

	int cnt = 0;
	copyMap();
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < zero.size(); i++) {
		if (cnt == 3) break;
		if (check[i]) {
			cmap[zero[i].first][zero[i].second] = 1;
			cnt++;
		}
	} // 찾은 벽 다 세워줌

	for (int i = 0; i < virus.size(); i++) {
		spreadVirus(virus[i].first, virus[i].second);
	}

    // 빈공간인 부분 찾음
	int size = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (cmap[i][j] == 0) size++;
	}
	return size;
}

void bfs(int idx, int num) { // 벽 세울 수 있는 부분 BFS로 찾음

	if (num == 3) {
		maxValue = max(maxValue, getArea());
		return;
	}
	else {
		for (int i = idx; i < zero.size(); i++) {
			if (check[i]) continue;
			check[i] = true;
			bfs(i,num + 1);
			check[i] = false;
		}
	}
}

int main() {

	scanf_s("%d %d", &N, &M);

	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &map[i][j]);
			if (map[i][j] == 0) zero.push_back({ i,j });
			else if (map[i][j] == 2) virus.push_back({ i,j });
		}
	check = new bool[zero.size()];
	fill_n(check, zero.size(), false);
	bfs(0,0);
	printf("%d", maxValue);
}