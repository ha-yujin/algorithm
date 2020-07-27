// level2 - 가장 큰 수
/* 
	정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내기 위해서는
	compare 함수를 재정의해 sort() 메소드를 사용해야 한다.
	두 수를 string으로 바꾼 후 더해 더 작은 값을 기준으로 (오름차순)정렬을 하도록 compare함수를 정의했다.
	이후 배열의 뒤부터 answer에 더해준다.
	!!!!!! 처음에 0000 의 경우 0으로 리턴해주는 것을 고려하지 않아 실패함
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
