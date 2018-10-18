#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
struct dot {
	int y, x;
};
struct process {
	int x;
	char c; // L 이면 왼쪽, D 면 오른쪽
};
int N, K, L;
queue<process> prc;
deque<dot> snake;
int dir; // 0,1,2,3 // 북,동,남,서
int area[101][101];
int result = 0;
//사과 3, 아무것도 없음 0
bool iswall(dot d, int dir) {
	if (dir == 0) {
		if (0 <= d.y - 1 && d.y - 1 < N
			&& 0 <= d.x && d.x < N)
			return false;
		return true;
	}

	if (dir == 1) {
		if (0 <= d.y && d.y < N
			&& 0 <= d.x + 1 && d.x +1< N)
			return false;
		return true;
	}

	if (dir == 2) {
		if (0 <= d.y + 1 && d.y + 1 < N
			&& 0 <= d.x && d.x < N)
			return false;
		return true;
	}

	if (dir == 3) {
		if (0 <= d.y && d.y < N
			&& 0 <= d.x - 1 && d.x - 1 < N)
			return false;
		return true;
	}
	return false;
}

bool isapple(dot d, int dir) {
	if (dir == 0) {
		if (area[d.y - 1][d.x] == 3) {
			area[d.y - 1][d.x] = 0;
			return true;
		}
		return false;
	}
	if (dir == 1) {
		if (area[d.y][d.x + 1] == 3) {
			area[d.y][d.x + 1] = 0;
			return true;
		}
		return false;
	}
	if (dir == 2) {
		if (area[d.y + 1][d.x] == 3) {
			area[d.y + 1][d.x] = 0;
			return true;
		}
		return false;
	}
	if (dir == 3) {
		if (area[d.y][d.x - 1] == 3) {
			area[d.y][d.x - 1] = 0;
			return true;
		}
		return false;
	}
	return false;
}
bool isbody(dot d, int dir) {
	dot temp{ d.y,d.x };
	if (dir == 0)
		temp.y--;
	if (dir == 1)
		temp.x++;
	if (dir == 2)
		temp.y++;
	if (dir == 3)
		temp.x--;
	for (auto s : snake) {
		if (s.y == temp.y && s.x == temp.x)
			return true;
	}
	return false;
}

void go() {
	while (++result) {
		dot head = snake.front();
		
		if (!iswall(head, dir) && !isbody(head,dir)) {
			if (isapple(head, dir)) {
				if (dir == 0)
					snake.push_front({ head.y - 1,head.x });
				if (dir == 1)
					snake.push_front({ head.y,head.x + 1 });
				if (dir == 2)
					snake.push_front({ head.y + 1,head.x });
				if (dir == 3)
					snake.push_front({ head.y,head.x - 1 });
			}
			else {
				snake.pop_back();
				if (dir == 0)
					snake.push_front({ head.y - 1,head.x });
				if (dir == 1)
					snake.push_front({ head.y,head.x + 1 });
				if (dir == 2)
					snake.push_front({ head.y + 1,head.x });
				if (dir == 3)
					snake.push_front({ head.y,head.x - 1 });
			}
		}
		else {
			//끝남
			break;
		}

		if (!prc.empty() && prc.front().x == result) {
			if (prc.front().c == 'L') dir--;
			if (prc.front().c == 'D') dir++;
			if (dir == -1) dir = 3;
			if (dir == 4) dir = 0;
			prc.pop();
		}
	}
}
int main(){
	cin >> N >> K;
	memset(area, 0, sizeof(area));
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		area[r-1][c-1] = 3;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int s;
		char c;
		cin >> s >> c;
		prc.push({ s,c });
	}
	snake.push_back({ 0,0 });
	dir = 1;

	go();

	cout << result << endl;

	return 0 ;
}