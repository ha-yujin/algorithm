// level2 - 주식가격

/* 나의 풀이 */
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++) {
		int j;
		for (j = i + 1; j < prices.size(); j++) {
			if (prices[i] > prices[j]) {
				answer.push_back(j - i);
				break;
			}
		}
		if (j == prices.size())
			answer.push_back(j - i - 1);
	}
	return answer;
}

/* 
	남의 풀이
    : 인덱스를 이용해 접근, 스택 사용
 */
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> s;
	int size = prices.size();
	for (int i = 0; i < size; i++) {
		// 스택에 원소가 있고, 가격이 떨어지기 시작하는 순간
		while (!s.empty() && prices[s.top()] > prices[i]) {
			answer[s.top()] = i - s.top();
			s.pop();
		}
		// 가격이 올라갈 때 동안 스택에 넣음
		s.push(i);
	}

	// 스택에 남은 것들을 계산함 
	while (!s.empty()) {
		answer[s.top()] = size - s.top() - 1;
		s.pop();
	}
	return answer;
}