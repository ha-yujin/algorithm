// 15651 - N과 M (3) 
/* 이전 15650과 달라진 점은 같은 수를 또 선택할 수 있다는 것이다.
	따라서 이미 한 수를 체크했다고 표시하는 bool형 변수를 삭제했다.
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
