#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
int arr[10];
unordered_map<int, bool> visit;
vector<int> vc;


void dfs(int cnt) {
	if (vc.size() == m) {
		for (auto i : vc)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (vc.size() < m) {
			if (!visit[arr[i]]) {
				vc.push_back(arr[i]);
				visit[arr[i]] = true;
				dfs(i + 1);
				visit[arr[i]] = false;
				vc.pop_back();
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0);
	return 0;
}