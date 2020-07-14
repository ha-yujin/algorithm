// 나이순 정렬
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, string> x, const pair<int, string> y) {
	return x.first < y.first;
}

int main() {

	int N;
	int age; string name;
	vector<pair<int, string>> person;

	cin>> N;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		person.push_back(make_pair(age, name));
	}
	stable_sort(person.begin(), person.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << person[i].first << " " << person[i].second << "\n";
	}

	return 0;
}
