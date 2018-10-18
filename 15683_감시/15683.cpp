#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
struct dot {
	int y, x;
	int num;
	int dir;
};
//num -> 1,3,4 4방향 
// num -> 2, 2방향
// num -> 5 의미 없음
int N, M;
int area[9][9];
int temp_area[9][9];
int min_result = 999999999;
vector<dot> camera;
void check_up(dot camera) {
	for (int i = camera.y; i >= 0; i--) {
		if (temp_area[i][camera.x] == 6) return;
		temp_area[i][camera.x] = 8;
	}
}
void check_right(dot camera) {
	for (int i = camera.x; i < M; i++) {
		if (temp_area[camera.y][i] == 6) return;
		temp_area[camera.y][i] = 8;
	}
}
void check_down(dot camera) {
	for (int i = camera.y; i < N; i++) {
		if (temp_area[i][camera.x] == 6) return;
		temp_area[i][camera.x] = 8;
	}
}
void check_left(dot camera) {
	for (int i = camera.x; i >= 0; i--) {
		if (temp_area[camera.y][i] == 6) return;
		temp_area[camera.y][i] = 8;
	}
}

void check(vector<dot> curr_dot) {


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			temp_area[i][j] = area[i][j];
	}

	for (auto camera : curr_dot) {

		if (camera.num == 1) {
			//위
			if (camera.dir == 0) {
				check_up(camera);
			}
			//오른쪽
			if (camera.dir == 1) {
				check_right(camera);
			}
			//아래
			if (camera.dir == 2) {
				check_down(camera);
			}
			//왼쪽
			if (camera.dir == 3) {
				check_left(camera);
			}
		}

		if (camera.num == 2) {
			if (camera.dir == 0 || camera.dir == 2) {
				check_up(camera);
				check_down(camera);
			}
			if (camera.dir == 1 || camera.dir == 3) {
				check_right(camera);
				check_left(camera);
			}
		}

		if (camera.num == 3) {
			if (camera.dir == 0) {
				check_up(camera);
				check_right(camera);
			}
			if (camera.dir == 1) {
				check_right(camera);
				check_down(camera);
			}
			if (camera.dir == 2) {
				check_down(camera);
				check_left(camera);
			}
			if (camera.dir == 3) {
				check_left(camera);
				check_up(camera);
			}
		}

		if (camera.num == 4) {
			if (camera.dir == 0) {
				check_left(camera);
				check_up(camera);
				check_right(camera);
			}
			if (camera.dir == 1) {
				check_up(camera);
				check_right(camera);
				check_down(camera);
			}
			if (camera.dir == 2) {
				check_right(camera);
				check_down(camera);
				check_left(camera);
			}
			if (camera.dir == 3) {
				check_down(camera);
				check_left(camera);
				check_up(camera);
			}
		}

		if (camera.num == 5) {
			check_up(camera);
			check_down(camera);
			check_left(camera);
			check_right(camera);
		}
	}

	int no_check_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp_area[i][j] == 0)
				no_check_cnt++;
		}
	}
	min_result = min_result < no_check_cnt ? min_result : no_check_cnt;
}
void go(vector<dot> curr_dot,int idx) {
	//카메라 들이 다 모였으면, 그걸로 맵 체크
	if (curr_dot.size() == camera.size()) {
		check(curr_dot);
	}

	//카메라 방향 정하기
	for (int i = idx; i < camera.size(); i++) {
		for (int j = 0; j < 4; j++) {
			curr_dot.push_back({ camera[i].y, camera[i].x ,camera[i].num, (camera[i].dir + j)%4 });
			go(curr_dot, i + 1);
			curr_dot.pop_back();
		}
	}

}
int main(){
	cin >> N >> M;
	memset(area, -1, sizeof(area));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> area[i][j];

			if (area[i][j] != 0 && area[i][j] != 6) {
				camera.push_back({ i,j,area[i][j],0 });
			}
		}
	}

	//카메라 방향 정하기. 4^9
	//사각지대 구하기
	vector<dot> combi;
	go(combi,0);

	cout << min_result << endl;

	return 0;
}