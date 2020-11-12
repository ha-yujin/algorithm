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

// 파이썬
from collections import defaultdict

def solution(clothes):
	answer = 1
	d = defaultdict(int)
	for x in clothes:
		d[x[1]]+=1

	for v in d.values():
		answer*=(v+1)
	return answer-1