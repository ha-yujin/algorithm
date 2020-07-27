// level2 - ���� ū ��
/* 
	������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ��� ���ؼ���
	compare �Լ��� �������� sort() �޼ҵ带 ����ؾ� �Ѵ�.
	�� ���� string���� �ٲ� �� ���� �� ���� ���� �������� (��������)������ �ϵ��� compare�Լ��� �����ߴ�.
	���� �迭�� �ں��� answer�� �����ش�.
	!!!!!! ó���� 0000 �� ��� 0���� �������ִ� ���� ������� �ʾ� ������
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {

	string as = to_string(a);
	string bs = to_string(b);
	return as + bs < bs + as;
}
string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);
	for (int i = numbers.size() - 1; i >= 0; i--)
		answer += to_string(numbers[i]);
	if (answer[0] == '0')
		return "0";
	else
		return answer;
}
