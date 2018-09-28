#include <iostream>
#include <vector>
using namespace std;
int N, M; // 1~N 에서 M개 뽑기
vector<int> combiNum;
bool visited[9];
void dfs() {
	if (combiNum.size() == M) {
		//출력
		for (int i = 0; i < combiNum.size(); i++) {
			cout << combiNum[i] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			combiNum.push_back(i);
			dfs();
			combiNum.pop_back();
			visited[i] = false;
		}
	}
}
int main(){
	cin >> N >> M;

	dfs();
	return 0;
}