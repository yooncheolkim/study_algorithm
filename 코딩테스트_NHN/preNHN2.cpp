#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct spot {
	int y, x;
};

int N;
int area[11][11];
vector<int> result;
queue<spot> works;

void bfs() {
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { -1,1,0,0 };
	int small_result = 0;
	while (!works.empty()) {
		spot temp = works.front();
		works.pop();
		small_result++;
		for (int i = 0; i < 4; i++) {
			int d_y = dy[i] + temp.y;
			int d_x = dx[i] + temp.x;

			if (area[d_y][d_x] == 1 &&
				d_y >= 0 && d_y < N &&
				d_x >= 0 && d_x < N) {
				works.push({ d_y,d_x});
				area[d_y][d_x] = 0;
			}
		}
	}
	result.push_back(small_result);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
		}
	}
	
	spot start;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (area[i][j] == 1) {
				start.y = i;
				start.x = j;
				area[i][j] = 0;
				works.push(start);
				bfs();
			}
		}
	}
	sort(result.begin(),result.end());

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1) {
			cout << result[i] << endl;
			break;
		}
		cout << result[i] << " ";
	}
	
	return 0;
}