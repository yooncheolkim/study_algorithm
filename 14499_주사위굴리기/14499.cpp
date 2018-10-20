#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
struct dice {
	int y, x;
	int ship[6] = { 0,0,0,0,0,0 };//¹Ø,ºÏ,µ¿,¼­,³²,À§
};
int N, M;
int area[21][21];
int let_num;
queue<int> work;
dice curr_dice;
bool move_dice(int dir) {
	int temp;
	int dy = 0;
	int dx = 0;
	if (dir == 1) {
		dy = 1;
		if (0 <= curr_dice.y + dy && curr_dice.y + dy < M
			&& 0 <= curr_dice.x + dx && curr_dice.x + dx < N){
			temp = curr_dice.ship[0];
			curr_dice.ship[0] = curr_dice.ship[2];
			curr_dice.ship[2] = curr_dice.ship[5];
			curr_dice.ship[5] = curr_dice.ship[3];
			curr_dice.ship[3] = temp;
			curr_dice.y += dy;
			curr_dice.x += dx;
			return true;
		}
		return false;
	}
	if (dir == 2) {
		dy = -1;
		if (0 <= curr_dice.y + dy && curr_dice.y + dy < M
			&& 0 <= curr_dice.x + dx && curr_dice.x + dx < N) {
			temp = curr_dice.ship[0];
			curr_dice.ship[0] = curr_dice.ship[3];
			curr_dice.ship[3] = curr_dice.ship[5];
			curr_dice.ship[5] = curr_dice.ship[2];
			curr_dice.ship[2] = temp;
			curr_dice.y += dy;
			curr_dice.x += dx;
			return true;
		}
		return false;
	}
	if (dir == 3) {
		dx = -1;
		if (0 <= curr_dice.y + dy && curr_dice.y + dy < M
			&& 0 <= curr_dice.x + dx && curr_dice.x + dx < N) {
			temp = curr_dice.ship[0];
			curr_dice.ship[0] = curr_dice.ship[1];
			curr_dice.ship[1] = curr_dice.ship[5];
			curr_dice.ship[5] = curr_dice.ship[4];
			curr_dice.ship[4] = temp;
			curr_dice.y += dy;
			curr_dice.x += dx;
			return true;
		}
		return false;
	}
	if (dir == 4) {
		dx = 1;
		if (0 <= curr_dice.y + dy && curr_dice.y + dy < M
			&& 0 <= curr_dice.x + dx && curr_dice.x + dx < N) {
			temp = curr_dice.ship[0];
			curr_dice.ship[0] = curr_dice.ship[4];
			curr_dice.ship[4] = curr_dice.ship[5];
			curr_dice.ship[5] = curr_dice.ship[1];
			curr_dice.ship[1] = temp;
			curr_dice.y += dy;
			curr_dice.x += dx;
			return true;
		}
		return false;
	}
	return false;
}
void go() {
	while (!work.empty()) {
		int temp_dir = work.front();
		work.pop();

		if (!move_dice(temp_dir)) continue;

		if (area[curr_dice.x][curr_dice.y] == 0) {
			area[curr_dice.x][curr_dice.y] = curr_dice.ship[0];
		}
		else {
			curr_dice.ship[0] = area[curr_dice.x][curr_dice.y];
			area[curr_dice.x][curr_dice.y] = 0;
		}

		cout << curr_dice.ship[5] << endl;
	}
}
int main(){
	cin >> N >> M;
	cin >> curr_dice.x >> curr_dice.y;
	cin >> let_num;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> area[i][j];
		}
	}

	for (int i = 0; i < let_num; i++) {
		int t; cin >> t; work.push(t);
	}
	go();
	return 0;
}