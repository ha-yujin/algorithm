// 소트인사이드 - 정렬
/* 내림차순을 오름차순으로 정렬하고 있었음...*/
#include <iostream>
#include <string>
using namespace std;
int main() {

	string N;
	cin >> N;
	int len = N.length();

	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
			if (N[j] > N[max])
				max = j;
		int tmp = N[i];
		N[i] = N[max];
		N[max] = tmp;
	}

	cout << N;
	return 0;
}