// level3 - 네트워크
/* 
	DFS 사용
	solution 함수를 통해 하나의 네트워크를 찾기 시작하고, checkConn을 통해 연결된 컴퓨터들을 모두 찾아나간다.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool *checked;
void checkConn(int n,int i, vector<vector<int>> computers){

	checked[i]=true;
	for(int index=0;index<n;index++){
		if(!checked[index] && computers[i][index])
			checkConn(n,index,computers);
	}

}
int solution(int n, vector<vector<int>> computers) {

	int answer=0;
	checked = new bool[n];
	fill_n(checked,n,false);
	for(int i=0;i<n;i++){
		if(!checked[i])
		{
			checkConn(n,i,computers);
			answer++;
		}
	}
	return answer;
}