#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
struct dot {
	int y, x;
	int dir;
};
int N, M;
//0 合率, 1 悼率, 2 巢率, 3 辑率
bool visited[51][51];
int area[51][51];
int result = 0;
void go(dot curr_robot) {

	int ori_dir = curr_robot.dir;
	bool cleaning = false;

	for (int i = 0; i < 4; i++) {
		curr_robot.dir--;
		if (curr_robot.dir < 0) curr_robot.dir = 3;

		if (curr_robot.dir == 0) {
			if (0 <= curr_robot.y - 1 && curr_robot.y - 1 < N
				&& area[curr_robot.y - 1][curr_robot.x] == 0
				&& !visited[curr_robot.y - 1][curr_robot.x]) {
				visited[curr_robot.y - 1][curr_robot.x] = true;
				result++;
				go({ curr_robot.y - 1,curr_robot.x,curr_robot.dir });
				cleaning = true;
				return;
			}
		}

		if (curr_robot.dir == 1) {
			if (0 <= curr_robot.x + 1 && curr_robot.x + 1 < M
				&& area[curr_robot.y][curr_robot.x + 1] == 0
				&& !visited[curr_robot.y][curr_robot.x + 1]) {
				visited[curr_robot.y][curr_robot.x + 1] = true;
				result++;
				go({ curr_robot.y,curr_robot.x+1,curr_robot.dir });
				cleaning = true;
				return;
			}
		}

		if (curr_robot.dir == 2) {
			if (0 <= curr_robot.y + 1 && curr_robot.y + 1 < N
				&& area[curr_robot.y + 1][curr_robot.x] == 0
				&& !visited[curr_robot.y + 1][curr_robot.x]) {
				visited[curr_robot.y + 1][curr_robot.x] = true;
				result++;
				go({ curr_robot.y+1,curr_robot.x,curr_robot.dir });
				cleaning = true;
				return;
			}
		}

		if (curr_robot.dir == 3) {
			if (0 <= curr_robot.x - 1 && curr_robot.x - 1 < M
				&& area[curr_robot.y][curr_robot.x - 1] == 0
				&& !visited[curr_robot.y][curr_robot.x - 1]) {
				visited[curr_robot.y][curr_robot.x - 1] = true;
				result++;
				go({ curr_robot.y,curr_robot.x -1,curr_robot.dir });
				cleaning = true;
				return;
			}
		}
	}

	if (!cleaning) {
		if (curr_robot.dir == 0) {
			if (0 <= curr_robot.y + 1 && curr_robot.y + 1 < N
				&& area[curr_robot.y + 1][curr_robot.x] != 1)
				go({ curr_robot.y + 1,curr_robot.x , curr_robot.dir});
			return;
		}

		if (curr_robot.dir == 1) {
			if (0 <= curr_robot.x - 1 && curr_robot.x - 1 < M
				&& area[curr_robot.y][curr_robot.x - 1] != 1)
				go({ curr_robot.y,curr_robot.x -1 , curr_robot.dir });
			return;
		}

		if (curr_robot.dir == 2) {
			if (0 <= curr_robot.y-1 && curr_robot.y-1 < N
				&& area[curr_robot.y-1][curr_robot.x] != 1)
				go({ curr_robot.y-1,curr_robot.x , curr_robot.dir });
			return;
		}

		if (curr_robot.dir == 3) {
			if (0 <= curr_robot.x+1 && curr_robot.x + 1 < M
				&& area[curr_robot.y][curr_robot.x+1] != 1)
				go({ curr_robot.y,curr_robot.x +1 , curr_robot.dir });
			return;
		}
	}
	//框流老荐 绝促.
	return;
}

int main(){
	cin >> N >> M;

	int r, c, d;

	cin >> r >> c >> d;

	dot start_robot{ r,c,d };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> area[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
	visited[start_robot.y][start_robot.x] = true;
	result++;
	go(start_robot);

	cout << result << endl;
	return 0;
}