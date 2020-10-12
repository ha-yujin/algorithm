// 톱니바퀴
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

deque <int> a[4];
bool visit[4];

// 톱니바퀴 회전
void turn(int idx, int dir) {

	if (dir == 1) { // 시계 방향
		int tmp = a[idx].back();
		a[idx].pop_back();
		a[idx].push_front(tmp);
	}
	else { // 반시계 방향
		int tmp = a[idx].front();
		a[idx].pop_front();
		a[idx].push_back(tmp);
	}
}

// 양쪽 톱니바퀴 확인 후 회전
void check(int idx, int dir) {

	visit[idx] = true;
	int pre = idx - 1; int next = idx + 1;

	if (next < 4 && !visit[next]) {
		if (a[idx][2] != a[next][6])
			check(next, dir*(-1));
	}
	if (pre >= 0 && !visit[pre]) {
		if (a[pre][2] != a[idx][6])
			check(pre, dir*(-1));
	}

	turn(idx, dir);
}

int main() {

	// 데이터 입력
	int k, result=0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int x;
			scanf_s("%1d", &x);
			a[i].push_back(x);
		}
	}

	scanf_s("%d", &k);
	for (int i = 0; i < k; i++) {
		int num, dir;
		cin >> num >> dir;

		check(num-1, dir);
		memset(visit, false, sizeof(visit));

	}

	// 결과 계산
	int tmp = 1;
	for (int i = 0; i < 4; i++) {
		if (a[i].front()) result += tmp;
		tmp *= 2;
	}
	cout << result;
}