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
	먼저 skill_trees 중에서 skill에 포함된 문자들만 뽑아서 vector에 넣었다.
	이때 skill의 문자열 순서로 비교했다는 것이 키 포인트!!
	그리고 이를 skill과 비교하면서 순서가 일치하는 경우에만 answer를 증가시켰다.
 */
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		vector<char> compare;

		for (int k = 0; k < skill_trees[i].size(); k++) {
			for (int j = 0; j < skill.size(); j++) {
				if (skill[j] == skill_trees[i][k]) {
					char tmp = skill[j];
					compare.push_back(tmp);
				}
			}
		}
		bool check = true;;
		for (int c = 0; c < compare.size(); c++) {
			if (skill[c] != compare[c]) {
				check = false;
			}
		}
		if (check)answer++;
	}

	return answer;
}