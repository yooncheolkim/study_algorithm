#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct dot {
	int y, x;
};
int max_result = 0;
int N;
int area[101][101];
int t_area[101][101];
bool visited[101][101];
queue<dot> work;
int d_y[4] = { 0,0,-1,1 };
int d_x[4] = { -1,1,0,0 };
void bfs() {
	int t_result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && t_area[i][j] != 0) {
				visited[i][j] = true;
				work.push({ i,j });
				while (!work.empty()) {
					dot temp = work.front();
					work.pop();

					for (int i = 0; i < 4; i++) {
						int dy = temp.y + d_y[i];
						int dx = temp.x + d_x[i];

						if (0 <= dy && dy < N &&
							0 <= dx && dx < N && t_area[dy][dx] != 0
							&& !visited[dy][dx]) {
							visited[dy][dx] = true;
							work.push({ dy,dx });
						}
					}
				}
				t_result++;
			}
		}
	}
	max_result = max_result < t_result ? t_result : max_result;
}
int main(){
	cin >> N;
	memset(area, -1, sizeof(area));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
		}
	}

	for (int k = 0; k <= 100; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (area[i][j] <= k) t_area[i][j] = 0;
				else t_area[i][j] = area[i][j];
			}
		}
		memset(visited, false, sizeof(visited));
		bfs();
	}
	cout << max_result << endl;
	return 0;
}