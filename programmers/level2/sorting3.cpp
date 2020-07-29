// level2 - H-index
/* 
	���� �迭�� ������ �� h���� �迭�� �ִ밪���� ������ ��,
	1�� �����ϸ� ã�Ƴ�����. �ο�� Ƚ���� h�̻��� ���� ������ ã�� �����Ѵ�.
	!!!!!! H �ε����� ���� �������� ���ؼ� Ʋ��.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int h, max = -1;

	sort(citations.begin(), citations.end());

		h=citations[citations.size()-1];

		while(true){

			for(int i=citations.size()-1;i>=0;i--){
				if(citations[i]>h)
					answer++;
			}
			if(h<=answer && answer > max)
			{
				return answer;
			}
			answer=0;
			h--;
		}

	return answer;
}