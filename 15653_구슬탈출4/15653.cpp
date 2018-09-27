#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
struct spot {
	int Ry, Rx;
	int By, Bx;
	int cnt;
	spot(int Ry, int Rx, int By, int Bx) {
		this->Ry = Ry;
		this->Rx = Rx;
		this->By = By;
		this->Bx = Bx;
		this->cnt = cnt;
	}
};
struct biz {
	int y, x;
	biz(int y, int x) {
		this->y = y;
		this->x = x;
	}
};
int bfs() {
	int dy[4] = { 0,0,-1,1 };
	int dx[4] = { -1,1,0,0 };
	while (!works.empty()) {
		spot temp = works.front();
		works.pop();
		biz R(temp.Ry,temp.Rx);
		biz B(temp.By,temp.Bx);
		for (int i = 0; i < 4; i++) {
			//눕히는 방향과 먼저 움직여야 할 구슬
			bool redfirst = false;
			if (i == 0) {
				if (R.x <= B.x) redfirst = true;
				while (area[R.y][R.x + dx[i]] != '#' ||
					R.x + dx[i] >= 0 && R.x + dx[i] < M) {

				}
			}
			if (i == 1) {
				if (R.x >= B.x) redfirst = true;
			}
			if (i == 2) {
				if (R.y <= B.y) redfirst = true;
			}
			if (i == 3) {
				if (R.y >= B.y) redfirst = true;
			}
		}



		works.push(temp);
	}
	return -1;
}
int N, M;
vector<string> area;
bool visited[11][11][11][11];
//R y,x B y,x

queue<spot> works;
int main()
{
	cin >> N >> M;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		area.push_back(temp);
	}

	spot sp(0,0,0,0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (area[i][j] == 'R') {
				sp.Ry = i;
				sp.Rx = j;
			}
			if (area[i][j] == 'B') {
				sp.By = i;
				sp.Bx = j;
			}
		}
	}
	works.push(sp);
	visited[sp.Ry][sp.Rx][sp.By][sp.Bx] = true;


	int result = bfs();

	return 0;
}