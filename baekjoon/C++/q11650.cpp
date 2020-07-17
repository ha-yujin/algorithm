// 좌표 정렬하기
/* x좌표와 y좌표로 이루어진 하나의 점을 표현하기 위해 pair를 사용함 */
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