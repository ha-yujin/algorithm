// level2 - ����
/*
   �� ������ �ǵ��� �ؽø� ����ϴ� ���̴�.
   mySol) ���� ��� ���� ���ռ��� ����� �� �ִ� ����� ���������� �����غ��Ҵ�.
   (��A ����+1) * (��B ����+1) *... -1�� �ϸ� ��ü ������ ���� ���´�.
   �̸� �����ϱ� ���� �ʿ��� ���� �� ������ �ǻ��� ���̴�.
   ���� �̸� ���� map �����̳ʸ� �̿��� key�� ���� ����, value�� ������ �����ߴ�.
*/
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, int> type;
	for (int i = 0; i < clothes.size(); i++) {
		type[clothes[i][1]]++;
	}

	for (auto it = type.begin(); it != type.end(); it++) {
		answer *= (it->second + 1);
	}
	answer -= 1;
	return answer;
}