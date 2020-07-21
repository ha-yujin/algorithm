// 15649 - N�� M (1) 
/*
	�� ������ ��Ʈ��ŷ ������� ������ ���ϴ� ���̴�.
	�ٽ��� ���� ������ ���� üũ�ϴ� �Ͱ� ��� �Լ��� �̿��ϴ� ���̴�.
	�� ���������� [12]�� [21]�� ��� ���ؾ� �Ѵ�. 
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
			visit[i] = true; // ���� üũ���� ���� ���� ���
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