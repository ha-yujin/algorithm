// level3 - ����Ʈ �ٹ�
/* 
	������ Ǯ���ϱ� ���� �ʿ��� ������ (1) �帣�� ���Ƚ�� ���� (2) �帣������ �뷡�� ��� Ƚ�� �����̴�.
	���� (1)�� ���ϱ� ���ؼ��� map�� ����ߴ�. key�� "�帣��", value�� "���Ƚ��"�� �����ߴ�.(m1)
	map�� key�� �������� ������ �Ǳ� ������ (m1)�� key�� value ������ �ٲپ� ������ ���ο� map(m2)�� �����ߴ�.
	�� ��, ������������ ���ĵǱ� ������ ���Ƚ���� ������ �ٲپ� �����ߴ�.
	** ��ó�� key�� �帣�� ���Ƚ���� ������ �� �ִ� ������ ���� ���� �� "��� �帣�� ���Ƚ���� �ٸ���"�� ���Ƕ����̴�.

	����, �帣�� ���Ƚ�� ������ �������Ƿ�, �� �帣���� �뷡 ��� Ƚ���� ���Ѵ�.
	�̴� �뷡���� pair�� �뷡�� ���Ƚ��, �ε����� �����ϰ� �̸� vector�� �����ߴ�.
	pair��ü ���� first ������ �ڵ����� �������� ������ �Ǳ� ������ ���� ������ �ʿ䰡 ����.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <map> 
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> m1;
	map<int, string> m2;

	for (int i = 0; i < genres.size(); i++) {
		m1[genres[i]] += plays[i];
	}

	for (auto it = m1.begin(); it != m1.end(); it++) {
		m2.insert({ -(it->second),it->first });
	} // �帣�� �� ��� ��

	for (auto it = m2.begin(); it != m2.end(); it++) {
		vector<pair<int, int>> tmp;
		for (int i = 0; i < genres.size(); i++) {
			if (genres[i] == it->second)
				tmp.push_back(make_pair(-plays[i], i)); // -(�뷡 �����), ���� �ε���
		}
		sort(tmp.begin(), tmp.end());

		if (tmp.size() == 1)
			answer.push_back(tmp[0].second);
		else {
			answer.push_back(tmp[0].second);
			answer.push_back(tmp[1].second);
		}
	}
	return answer;
}