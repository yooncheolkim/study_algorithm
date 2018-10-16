#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

struct dot {
	int y, x;
};
using namespace std;
int N, M;
int area[9][9];
bool visited[9][9];
vector<dot> zero_dot;
queue<dot> work;
vector<dot> start_work;
int cnt_zero = 0;
int cnt_wall = 0;
int result = 0;

void bfs(vector<dot> curr_dot) {
	for (int i = 0; i < curr_dot.size(); i++) {
		area[curr_dot[i].y][curr_dot[i].x] = 1;
	}

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };

	int whole_infest = start_work.size();

	while (!work.empty()) {
		dot temp = work.front();
		work.pop();

		for (int i = 0; i < 4; i++) {
			int d_y = temp.y + dy[i];
			int d_x = temp.x + dx[i];

			if (0 <= d_y && d_y < N &&
				0 <= d_x && d_x < M && !visited[d_y][d_x] &&
				area[d_y][d_x] != 1 && area[d_y][d_x] != 2) {
				visited[d_y][d_x] = true;
				work.push({d_y,d_x});
				whole_infest++;
			}
		}
	}

	int cnt_remain = N*M - whole_infest - 3 - cnt_wall;

	result = result < cnt_remain ? cnt_remain : result;

	for (int i = 0; i < curr_dot.size(); i++) {
		area[curr_dot[i].y][curr_dot[i].x] = 0;
	}
}

void combi(vector<dot> curr_dot, int idx) {
	if (curr_dot.size() == 3) {


		memset(visited, false, sizeof(visited));
		for (int i = 0; i < start_work.size(); i++) {
			visited[start_work[i].y][start_work[i].x] = true;
			work.push({ start_work[i].y,start_work[i].x });
		}
		bfs(curr_dot);
	}

	for (int i = idx; i < zero_dot.size(); i++) {
		if (curr_dot.size() < 3) {
			curr_dot.push_back(zero_dot[i]);
			combi(curr_dot, i + 1);
			curr_dot.pop_back();
		}
	}
}

int main(){

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> area[i][j];
			if (area[i][j] == 0) {
				zero_dot.push_back({ i,j });
				cnt_zero++;
			}
			if (area[i][j] == 1)
				cnt_wall++;

			if (area[i][j] == 2) {
				work.push({ i,j });
				start_work.push_back({ i,j });
			}
		}
	}

	// NxM 에서 0인 부분 3개 정하기
	// 그리고 안전범위 구하기

	//zero_dot에서 3개 정하기
	vector<dot> curr_dot;
	combi(curr_dot,0);

	cout << result << endl;

	return 0;
}