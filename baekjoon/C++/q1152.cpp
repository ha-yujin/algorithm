// 1152 - 단어의 개수
/*
	이 문제에서 주의해야할 부분은 문자열의 앞과 뒤에도 공백이 올 수 있다는 것이다.
	따라서 start라는 bool 변수를 통해 단어의 시작을 체크했다.
*/
#include <iostream>
#define MAX 1000000
using namespace std;

int main() {

	char str[MAX];
	bool start = false;
	int cnt = 0;

	cin.getline(str, MAX, '\n');
	for (int i = 0; str[i] != '\0'; i++) {
		if (!start&& str[i] != ' ') {
			start = true;
			cnt++;
		}
		else if (str[i] == ' ') {
			start = false;
		}
	}
	printf("%d", cnt);
	return 0;
}