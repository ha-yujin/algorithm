// level2 - 124 나라의 숫자

/* 나의 풀이 */
#include <string>

using namespace std;

string solution(int n) {
	string answer = "";
	int remainder;
	while (n != 0) {
		remainder = n % 3;
		n = n / 3;

		if (remainder == 0) {
			remainder = 4;
			n--;
		}
		answer = to_string(remainder) + answer;
	}
	return answer;
}

/* 
	남의 풀이
 */
