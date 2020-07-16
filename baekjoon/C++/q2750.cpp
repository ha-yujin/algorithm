// 수 정렬하기
/* 선택정렬을 사용해서 구현함. "수는 중복되지 않는다"라는 제한조건과 출력형태를 제대로 보지 못함. */
#include <iostream>

int main() {

	int N, min;
	scanf("%d", &N);
	int *num = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N; i++) {
		min = i;
		for (int j = i + 1; j < N; j++) {
			if (num[j] < num[min])
				min = j;
		}

		int tmp = num[i];
		num[i] = num[min];
		num[min] = tmp;
	}

	for (int i = 0; i < N; i++) {
		printf("%d", num[i]);
		if (i != N - 1)
			printf("\n");
	}
	return 0;
}