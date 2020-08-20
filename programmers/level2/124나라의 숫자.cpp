// level2 - 124 나라의 숫자

/*
	나의 풀이 
	3진법과 유사함을 찾아내서 3진법 계산하듯이 함
*/
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
	"412"[index]를 이용해 추가해주는 것이 새로움
 */
#include <string>

using namespace std;

string solution(int n)
{
    string answer = "";
  int a;
    while(n > 0){
    a = n % 3;
    n = n / 3;
    if (a == 0){
        n -= 1;
    }
    answer = "412"[a] + answer;
  }

    return answer;
}