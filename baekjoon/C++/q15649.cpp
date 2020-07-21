// 15649 - N과 M (1) 
/*
	이 문제는 백트래킹 방법으로 순열을 구하는 것이다.
	핵심은 내가 지나간 곳을 체크하는 것과 재귀 함수를 이용하는 것이다.
	이 문제에서는 [12]와 [21]을 모두 구해야 한다. 
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[8] = { false };
vector<int> list;

void find(int x) {

	if (x == M) {
		for (int i = 0; i < list.size(); i++)
			printf("%d ", list[i]);
		printf("\n");
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visit[i]) continue;
			visit[i] = true; // 아직 체크하지 않은 곳일 경우
			list.push_back(i + 1);
			find(x + 1);
			visit[i] = false;
			list.pop_back();
		}
	}
}

int main() {

	scanf_s("%d %d", &N, &M);
	find(0);
	return 0;
}