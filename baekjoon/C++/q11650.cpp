// ��ǥ �����ϱ�
/* x��ǥ�� y��ǥ�� �̷���� �ϳ��� ���� ǥ���ϱ� ���� pair�� ����� */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, x, y;
	scanf_s("%d", &N);

	vector<pair<int, int>> point;

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &x);
		scanf_s("%d", &y);
		point.push_back(make_pair(x, y));
	}

	sort(point.begin(), point.end());

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", point[i].first, point[i].second);
	}
	return 0;
}