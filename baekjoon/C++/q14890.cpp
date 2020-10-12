// 경사로
#include <iostream>
#include <vector>
using namespace std;

int M, L;

int check(vector<vector<int>> map) {

	int res = 0;
	for (int i = 0; i < M; i++) {
		int cnt = 1; // 현재까지 연속된 같은 높이 계단 수
		bool flag = true;

		for (int j = 0; j < M - 1; j++) { // 한 행에 대해서 check

			if (map[i][j] == map[i][j + 1]) cnt++;
			else if (map[i][j] + 1 == map[i][j + 1]) { // 2 3인 경우
				if (cnt >= L) cnt=1; 
				else flag = false; // 길 만들 수 없음
			}
			else if (map[i][j] - 1 == map[i][j + 1]) { // 3 2인 경우
				if (cnt < 0) flag = false;
				else cnt = -(L - 1); // 앞으로 L-1개의 같은 높이 계단 필요
			}
			else flag = false;
		}
		if (cnt >= 0 && flag) res++;
	}
	return res;
}
int main() {

	// 필요한 변수 입력
	scanf_s("%d%d", &M, &L);

	vector<vector<int>> map(M,vector<int>(M,0));
	vector<vector<int>> map2(M, vector<int>(M, 0));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++)
		{
			scanf_s("%d", &map[i][j]);
			map2[j][i] = map[i][j];
		}
	}

	int res = check(map) + check(map2);
	printf("%d", res);
}