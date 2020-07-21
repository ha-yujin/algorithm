// level2 - 전화번호 목록
/*
   본 문제의 의도는 해시를 사용하는 것이다.
   mySol) 직관적인 풀이법 : 서로 하나씩 비교해보며 find() 메소드를 이용해 접두어를 찾았다. 
   otherSol) 입력이 문자열로 들어오기 때문에 배열을 정렬하고 나면 ["119", "11923", "234" ] 이렇게 되므로
   인접한 것들끼리만 비교해보면 되므로 더 효율적이다.
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