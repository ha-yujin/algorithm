// 15650 - N과 M (2)
/*
	이 문제는 백트래킹 방법으로 조합을 구하는 것이다.
	15649 문제와 다른 점은 순서만 다른 같은 조합은 한번만 출력해야 된다는 것이다.
	즉, [1 2 3]과 [2 1 3]은 같은 것이므로 1번만 출력해야 된다.
	이를 해결하기 위해서는 15649에서 탐색을 시작하는 시작점만 수정해주면 된다.
	즉, 1을 포함해서 조합을 구했다면 2에서 시작할 때는 1을 보지 않도록 해주어야 한다.
	따라서 재귀 함수에 매개변수를 하나 더 추가해 시작점이 어디인지를 나타내었다.
*/
int N, M;
bool visit[8] = { false };
vector<int> list;

void find(int start, int x) {

	if (x == M) {
		for (int i = 0; i < list.size(); i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < N; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		list.push_back(i + 1);
		find(i, x + 1);
		visit[i] = false;
		list.pop_back();
	}

}
int main() {

	scanf_s("%d %d", &N, &M);
	find(0, 0);
	return 0;
}
