#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int area[501][501];
bool visited[501][501];
int max_val = 0;

void dfs(int y, int x, int depth, int sum) {
	int dy[4] = { 0,0,-1,1 };
	int dx[4] = { -1,1,0,0 };

	if (depth >= 4) {
		max_val = max_val < sum ? sum : max_val;
		return;
	}
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int d_y = y + dy[i];
		int d_x = x + dx[i];

		if (0 <= d_y && d_y < N &&
			0 <= d_x && d_x < M && !visited[d_y][d_x]) {
			dfs(d_y, d_x, depth + 1, sum + area[d_y][d_x]);
		}
	}

	visited[y][x] = false;
}

void not_dfs(int y, int x) {
	if (y + 2 >= N || x + 2 >= M)
		return;

	//벽에 붙어 있는 경우
	if (y == 0) {
		int temp_res = area[y][x] + area[y][x + 1] + area[y][x + 2] + area[y + 1][x + 1];
		max_val = max_val < temp_res ? temp_res : max_val;
	}
	if (x == 0) {
		int temp_res = area[y][x] + area[y + 1][x] + area[y + 2][x] + area[y + 1][x + 1];
		max_val = max_val < temp_res ? temp_res : max_val;
	}
	if (y == N - 3) {
		int temp_res = area[y + 2][x] + area[y + 2][x + 1] + area[y + 2][x + 2] + area[y + 1][x + 1];
		max_val = max_val < temp_res ? temp_res : max_val;
	}

	if (x == M - 3) {
		int temp_res = area[y][x + 2] + area[y + 1][x + 2] + area[y + 2][x + 2] + area[y + 1][x + 1];
		max_val = max_val < temp_res ? temp_res : max_val;
	}

	//벽에 붙어있지 않은 경우
	int vals[4] = { area[y][x + 1], area[y + 1][x],area[y + 1][x + 2], area[y + 2][x + 1] };
	
	int minval = 999999999;

	int res = 0;
	for (int i = 0; i < 4; i++) {
		minval = minval < vals[i] ? minval : vals[i];
		res += vals[i];
	}

	res += area[y + 1][x + 1];
	res -= minval;

	max_val = max_val < res ? res : max_val;
}

int main() {
	cin >> N >> M;
	memset(area, -1, sizeof(area));
	memset(visited, false, sizeof(visited));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> area[n][m];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(i, j, 0, 0);

			not_dfs(i, j);
		}
	}

	cout << max_val << endl;

	return 0;
}