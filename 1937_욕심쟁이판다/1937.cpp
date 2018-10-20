#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int area[501][501];
int dp[501][501];
int d_y[4] = { 0,0,-1,1 };
int d_x[4] = { -1,1,0,0 };
int max_day = 0;
bool isinrange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}
//여기서 시작 했을때, 최대 갈수 있는 곳..
int dfs(int y, int x){
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int dy = y + d_y[i];
		int dx = x + d_x[i];
		if (isinrange(dy, dx)&&
			area[dy][dx] > area[y][x]) {
			dp[y][x] = max(dp[y][x], dfs(dy, dx) + 1);
		}
	}
	return dp[y][x];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_day = max(max_day,dfs(i, j));
		}
	}
	cout << max_day << endl;
	return 0;
}