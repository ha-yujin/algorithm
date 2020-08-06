// level3 - ��Ʈ��ũ
/* 
	DFS ���
	solution �Լ��� ���� �ϳ��� ��Ʈ��ũ�� ã�� �����ϰ�, checkConn�� ���� ����� ��ǻ�͵��� ��� ã�Ƴ�����.
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