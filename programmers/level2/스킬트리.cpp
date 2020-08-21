// level2 - 스킬트리

/*
	나의 풀이 
	조건을 만족하는 것보다 만족하지 않는 경우를 찾아 문제를 해결함
	1. 이번 문자가 발견되었는데 지난 문자보다 더 앞일 경우와
	2. 지난 문자가 발견되지 않았는데 이번 문자가 발견된 경우
*/
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {

	int before, current;
	int answer = skill_trees.size();
	for (int i = 0; i < skill_trees.size(); i++) {
		before = skill_trees[i].find(skill[0]);
		for (int j = 1; j < skill.length(); j++) {
			current = skill_trees[i].find(skill[j]);

			if ((before > current && current >= 0) || (before < 0 && current >= 0)) {
				answer--;
				break;
			}
			before = current;
		}
	}
	return answer;
}

/* 
	남의 풀이
 */
