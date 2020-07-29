// level2 �Ҽ� ã��
/*
	��� ������ ã�� ������ �Ѵ�.(���� ������ ����)
	���� �ߺ��Ǵ� ���ڸ� �����ϱ� ���� set �����̳ʸ� ����ߴ�.
	!!!!�Ҽ� �Ǻ��ϴ� �������� �ð� �ʰ��� �߻��ؼ� ������
*/
#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> answers;
vector<int> tmp;
bool *visit;

// �Ҽ��� �ƴ� ���� ������ �Ǻ��ؾ� ��
bool isPrime(int x) {

	int i;
	if (x <= 1) return false;
	for (i = 2; i < x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}
void makeNum(string numbers, int start, int end) {

	if (start == end) {
		string ans = "";
		for (int i = 0; i < tmp.size(); i++) {
			ans += tmp[i];
		}
		if (isPrime(stoi(ans))) {
			answers.insert(stoi(ans));
		}
		return;
	}
	else {
		for (int i = 0; i < numbers.length(); i++) {
			if (visit[i]) continue;
			visit[i] = true;
			tmp.push_back(numbers[i]);
			makeNum(numbers, start + 1, end);
			visit[i] = false;
			tmp.pop_back();
		}
	}
}
int solution(string numbers) {
	int answer = 0;
	visit = new bool[numbers.length()];
	for (int i = 0; i < numbers.length(); i++)
		visit[i] = false;
	for (int j = 0; j < numbers.length(); j++)
		makeNum(numbers, 0, j + 1);
	answer = answers.size();
	return answer;
}