// 10989�� �� �����ϱ� 3
// �Է¹��� �� ��� �������� �ʰ� ���!! --> �޸� ����
#include <iostream>
#define N 10000
using namespace std;

int main() {

	ios::sync_with_stdio(false); // ���� ������� ����

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