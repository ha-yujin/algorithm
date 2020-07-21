// 15650 - N�� M (2)
/*
	�� ������ ��Ʈ��ŷ ������� ������ ���ϴ� ���̴�.
	15649 ������ �ٸ� ���� ������ �ٸ� ���� ������ �ѹ��� ����ؾ� �ȴٴ� ���̴�.
	��, [1 2 3]�� [2 1 3]�� ���� ���̹Ƿ� 1���� ����ؾ� �ȴ�.
	�̸� �ذ��ϱ� ���ؼ��� 15649���� Ž���� �����ϴ� �������� �������ָ� �ȴ�.
	��, 1�� �����ؼ� ������ ���ߴٸ� 2���� ������ ���� 1�� ���� �ʵ��� ���־�� �Ѵ�.
	���� ��� �Լ��� �Ű������� �ϳ� �� �߰��� �������� ��������� ��Ÿ������.
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
