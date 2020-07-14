// 10989번 수 정렬하기 3
// 입력받은 수 모두 저장하지 않고 사용!! --> 메모리 제한
#include <iostream>
#define N 10000
using namespace std;

int main() {

	ios::sync_with_stdio(false); // 빠른 입출력을 위함

	int n, number;
	int cnt[N] = { 0, };
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> number;
		cnt[number - 1]++;
	}

	for (int i = 0; i < N; i++) {
		if (cnt[i] != 0) {
			for (int j = 0; j < cnt[i]; j++)
				cout << i+1 << "\n";
		}
	}

	return 0;
}