// 14888번. 연산자 끼워넣기
#include <iostream>
#include <algorithm>
using namespace std;

int N, num[11], op[4];
int MIN = 100000000;
int MAX = MIN*-1;

void makeExp(int cnt, int res) { 

	if (cnt == N - 1) {
		if (MIN > res) MIN = res;
		if (MAX < res) MAX = res;
		return;
	}

	for (int i = 0; i < 4; i++) {

		if (op[i] == 0) continue;

		op[i]--;
		if (i == 0) makeExp(cnt + 1, res + num[cnt+1]);
		else if (i == 1) makeExp(cnt + 1, res - num[cnt+1]);
		else if (i == 2) makeExp(cnt + 1, res*num[cnt+1]);
		else makeExp(cnt + 1, res/num[cnt+1]);

		op[i]++;
	}
}
int main() {

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
		scanf_s("%d", &num[i]);
	for (int i = 0; i < 4; i++) { // +, -, *, %
		scanf_s("%d", &op[i]);
	}
	makeExp(0,num[0]);

	printf("%d\n%d", MAX, MIN);
}