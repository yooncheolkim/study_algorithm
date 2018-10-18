#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
struct dot {
	int y, x;
};
struct p {
	dot r, b;
	int cnt;
	int dir;
};

int N, M;
int min_result = 999;
vector<string> area;
char temp_area[11][11];
bool visited[11][11][11][11][4];
queue<p>work;
dot check_r;
dot check_b;
bool isup(dot r, dot b) {
	return r.y < b.y;
}
bool isright(dot r, dot b) {
	return r.x > b.x;
}
bool isdown(dot r, dot b) {
	return r.y > b.y;
}
bool isleft(dot r, dot b) {
	return r.x < b.x;
}

//r이 통과 1, b가 통과 2, 안통과 0
int move_up(dot r, dot b) {
	int result = 0;
	if (isup(r, b)) {
		while (true) {
			if (area[r.y - 1][r.x] == 'O') {
				result = 1;  r.y--; break;
			}
			if (area[r.y - 1][r.x] == '#') break;
			r.y--;
		}
		while (true) {
			if (area[b.y - 1][b.x] == 'O') {
				result = 2; b.y--; break;
			}
			if (area[b.y - 1][b.x] == '#' || (b.y-1 == r.y && b.x == r.x)) break;
			b.y--;
		}
	}
	else {
		while (true) {
			if (area[b.y - 1][b.x] == 'O') {
				result = 2; b.y--; break;
			}
			if (area[b.y - 1][b.x] == '#') break;
			b.y--;
		}
		while (true) {
			if (area[r.y - 1][r.x] == 'O') {
				if (result != 2)
					result = 1;
				r.y--;
				break;
			}
			if (area[r.y - 1][r.x] == '#' || (r.y-1 == b.y && r.x == b.x)) break;
			r.y--;
		}
	}
	check_r = r;
	check_b = b;
	return result;
}
int move_right(dot r, dot b) {
	int result = 0;
	if (isright(r, b)) {
		while (true) {
			if (area[r.y][r.x + 1] == 'O') {
				result = 1;  r.x++; break;
			}
			if (area[r.y][r.x + 1] == '#') break;
			r.x++;
		}
		while (true) {
			if (area[b.y][b.x + 1] == 'O') {
				result = 2; b.x++; break;
			}
			if (area[b.y][b.x + 1] == '#' || (b.y == r.y && b.x+1 == r.x)) break;
			b.x++;
		}
	}
	else {
		while (true) {
			if (area[b.y][b.x + 1] == 'O') {
				result = 2; b.x++; break;
			}
			if (area[b.y][b.x + 1] == '#') break;
			b.x++;
		}
		while (true) {
			if (area[r.y][r.x + 1] == 'O') {
				if (result != 2)
					result = 1;
				r.x++;
				break;
			}
			if (area[r.y][r.x + 1] == '#' || (r.y == b.y && r.x+1 == b.x)) break;
			r.x++;
		}
	}
	check_r = r;
	check_b = b;
	return result;
}

int move_down(dot r, dot b) {
	int result = 0;
	if (isdown(r, b)) {
		while (true) {
			if (area[r.y + 1][r.x] == 'O') {
				result = 1;  r.y++; break;
			}
			if (area[r.y + 1][r.x] == '#') break;
			r.y++;
		}
		while (true) {
			if (area[b.y + 1][b.x] == 'O') {
				result = 2; b.y++; break;
			}
			if (area[b.y + 1][b.x] == '#' || (b.y+1 == r.y && b.x == r.x)) break;
			b.y++;
		}
	}
	else {
		while (true) {
			if (area[b.y + 1][b.x] == 'O') {
				result = 2; b.y++; break;
			}
			if (area[b.y + 1][b.x] == '#') break;
			b.y++;
		}
		while (true) {
			if (area[r.y + 1][r.x] == 'O') {
				if (result != 2)
					result = 1;
				r.y++;
				break;
			}
			if (area[r.y + 1][r.x] == '#' || (r.y+1 == b.y && r.x == b.x)) break;
			r.y++;
		}
	}
	check_r = r;
	check_b = b;
	return result;
}
int move_left(dot r, dot b) {
	int result = 0;
	if (isleft(r, b)) {
		while (true) {
			if (area[r.y][r.x - 1] == 'O') {
				result = 1;  r.x--; break;
			}
			if (area[r.y][r.x - 1] == '#') break;
			r.x--;
		}
		while (true) {
			if (area[b.y][b.x - 1] == 'O') {
				result = 2; b.x--; break;
			}
			if (area[b.y][b.x - 1] == '#' || (b.y == r.y && b.x-1 == r.x)) break;
			
			b.x--;
		}
	}
	else {
		while (true) {
			if (area[b.y][b.x - 1] == 'O') {
				result = 2; b.x--; break;
			}
			if (area[b.y][b.x - 1] == '#') break;
			
			b.x--;
		}
		while (true) {
			if (area[r.y][r.x - 1] == 'O') {
				if (result != 2) {
					result = 1;
				}
				r.x--;
				break;
			}
			if (area[r.y][r.x - 1] == '#' || (r.y == b.y && r.x-1 == b.x)) break;
			
			r.x--;
		}
	}
	check_r = r;
	check_b = b;
	return result;
}
int bfs() {
	dot start_r, start_b;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (area[i][j] == 'R') {
				start_r.y = i;
				start_r.x = j;
			}
			if (area[i][j] == 'B') {
				start_b.y = i;
				start_b.x = j;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		work.push({ start_r,start_b,1, i });
		visited[start_r.y][start_r.x][start_b.y][start_b.x][i] = true;
	}

	while (!work.empty()) {
		p temp = work.front();
		work.pop();
		if (temp.cnt > 10)
			return -1;
		//기울이기..
		if (temp.dir == 0) {
			int move_result = move_up(temp.r, temp.b);
			if (move_result == 0) {
				for (int i = 0; i < 4; i++) {
					if (!visited[check_r.y][check_r.x][check_b.y][check_b.x][i] && i != temp.dir) {
						work.push({ check_r,check_b,temp.cnt + 1,i });
						visited[check_r.y][check_r.x][check_b.y][check_b.x][i] = true;
					}
				}
			}
			if (move_result == 1) return temp.cnt;
			if (move_result == 2) continue;
		}

		if (temp.dir == 1) {
			int move_result = move_right(temp.r, temp.b);
			if (move_result == 0) {
				for (int i = 0; i < 4; i++) {
					if (!visited[check_r.y][check_r.x][check_b.y][check_b.x][i] && i != temp.dir) {
						work.push({ check_r,check_b,temp.cnt + 1,i });
						visited[check_r.y][check_r.x][check_b.y][check_b.x][i] = true;
					}
				}
			}
			if (move_result == 1) return temp.cnt;
			if (move_result == 2) continue;
		}

		if (temp.dir == 2) {
			int move_result = move_down(temp.r, temp.b);
			if (move_result == 0) {
				for (int i = 0; i < 4; i++) {
					if (!visited[check_r.y][check_r.x][check_b.y][check_b.x][i] && i != temp.dir) {
						work.push({ check_r,check_b,temp.cnt + 1,i });
						visited[check_r.y][check_r.x][check_b.y][check_b.x][i] = true;
					}
				}
			}
			if (move_result == 1) return temp.cnt;
			if (move_result == 2) continue;
		}

		if (temp.dir == 3) {
			int move_result = move_left(temp.r, temp.b);
			if (move_result == 0) {
				for (int i = 0; i < 4; i++) {
					if (!visited[check_r.y][check_r.x][check_b.y][check_b.x][i] && i != temp.dir) {
						work.push({ check_r,check_b,temp.cnt + 1,i });
						visited[check_r.y][check_r.x][check_b.y][check_b.x][i] = true;
					}
				}
			}
			if (move_result == 1) return temp.cnt;
			if (move_result == 2) continue;
		}
	}
	return -1;
}

int main(){
	cin >> N >> M;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		area.push_back(t);
	}
	
	cout << bfs() << endl;
	return 0;
}