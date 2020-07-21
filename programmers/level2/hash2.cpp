// level2 - ��ȭ��ȣ ���
/*
   �� ������ �ǵ��� �ؽø� ����ϴ� ���̴�.
   mySol) �������� Ǯ�̹� : ���� �ϳ��� ���غ��� find() �޼ҵ带 �̿��� ���ξ ã�Ҵ�. 
   otherSol) �Է��� ���ڿ��� ������ ������ �迭�� �����ϰ� ���� ["119", "11923", "234" ] �̷��� �ǹǷ�
   ������ �͵鳢���� ���غ��� �ǹǷ� �� ȿ�����̴�.
*/
#include <string>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	bool found = false;
	for (int i = 0; i < phone_book.size() && !found; i++) {
		for (int j = 0; j < phone_book.size(); j++) {
			if (phone_book[i].length() < phone_book[j].length()) {
				if (phone_book[j].find(phone_book[i]) == 0) {
					found = true;
					answer = false;
					break;
				}
			}
		}
	}
	return answer;
}