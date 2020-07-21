// 15651 - N�� M (3) 
/* ���� 15650�� �޶��� ���� ���� ���� �� ������ �� �ִٴ� ���̴�.
	���� �̹� �� ���� üũ�ߴٰ� ǥ���ϴ� bool�� ������ �����ߴ�.
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> list;

void find(int x) {

	if (x == M) {

		for (int i = 0; i < list.size(); i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		list.push_back(i + 1);
		find(x + 1);
		list.pop_back();
	}
}
int main() {

	scanf_s("%d %d", &N, &M);
	find(0);
	return 0;
}
