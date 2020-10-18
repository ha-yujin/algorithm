// q17144번. 미세먼지 안녕!
#include <iostream>
using namespace std;

int map[50][50], r, c, t;
int airMachine[2] = { -1, };
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

void spreadDust() {

	int cmap[50][50] = { 0, };
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				int tmp = map[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int dr = i + dy[k];
					int dc = j + dx[k];

					if (dr >= 0 && dc >= 0 && dr < r && dc < c && map[dr][dc] != -1) {
						cmap[dr][dc] += tmp;
						cmap[i][j] -= tmp;
					}
				}
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] += cmap[i][j];
		}
	}
}

void circulate() {

	int up_y = airMachine[0];
	int down_y = airMachine[1];

	// 윗부분
	for (int i = up_y - 1; i > 0; i--)
		map[i][0] = map[i - 1][0];
	for (int i = 0; i < c - 1; i++)
		map[0][i] = map[0][i + 1];
	for (int i = 0; i < up_y; i++)
		map[i][c - 1] = map[i + 1][c - 1];
	for (int i = c - 1; i > 1; i--)
		map[up_y][i] = map[up_y][i - 1];
	map[up_y][1] = 0;

	// 아랫부분
	for (int i = down_y + 1; i < r-1; i++)
		map[i][0] = map[i + 1][0];
	for (int i = 0; i < c-1; i++)
		map[r - 1][i] = map[r - 1][i + 1];
	for (int i = r - 1; i > down_y; i--)
		map[i][c - 1] = map[i - 1][c - 1];
	for (int i = c - 1; i > 1; i--)
		map[down_y][i] = map[down_y][i - 1];
	map[down_y][1] = 0;
}

int main() {

	scanf_s("%d %d %d", &r, &c, &t);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
		{
			scanf_s("%d", &map[i][j]);
			if (map[i][j] == -1) {
				if (airMachine[0] == -1) airMachine[0] = i;
				else airMachine[1] = i;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		spreadDust();
		circulate();
	}

	int res = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j]>0)
				res += map[i][j];
		}
	}
	printf("%d", res);
}