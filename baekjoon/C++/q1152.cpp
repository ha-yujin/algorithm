// 1152 - �ܾ��� ����
/*
	�� �������� �����ؾ��� �κ��� ���ڿ��� �հ� �ڿ��� ������ �� �� �ִٴ� ���̴�.
	���� start��� bool ������ ���� �ܾ��� ������ üũ�ߴ�.
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