//15649�� �ٸ���
// 15649 �� ����, �̰Ŵ� ����
// ��, �� ������ ���������̿��� �Ѵ� -> �ߺ��� ����.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> combi;

void dfs(int idx) {
	if (combi.size() == M){
		for (int i = 0; i < combi.size(); i++) {
			cout << combi[i] << " ";
		}
		cout << "\n";
	}

	for (int i = idx; i <= N; i++) {
		if (combi.size() < M) {
			combi.push_back(i);
			dfs(i + 1);
			combi.pop_back();
		}
	}
}
int main(){
	cin >> N >> M;

	dfs(1);

	return 0;
}