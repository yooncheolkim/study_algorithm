#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct changing_spot {
	int y, x;
	char con;
};
int N;
char area[51][51];
vector<changing_spot> ch_spot;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
		}
	}

	bool ischange = true;
	while (ischange) {
		ischange = false;
		int d_y[4] = { 0,0,-1,1 };
		int d_x[4] = { 1,-1,0,0 };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (area[i][j] < 'A' || area[i][j] > 'Z') {
					char con_alpha[26];
					for (int d = 0; d < 4; d++) {
						int dy = i + d_y[d];
						int dx = j + d_x[d];

						int check = area[i][j] - '0';
						check = ~(check & 15);
						for (int bit = 1; bit < 16; bit = bit * 2) {
							//장애물이 없다.
							if ((bit & check) == 0) {
								if (dy >= 0 && dy < N
									&& dx >= 0 && dx < N) {
									con_alpha[area[dy][dx] - 'A']++;
								}
							}
						}
					}
					//확인

					bool issame = false;
					int max = 0;
					int real_con = 0;
					for (int con = 0; con < 26; con++) {
						if (max < con_alpha[con]) {
							max = con_alpha[con];
							real_con = con;
							issame = false;
						}
						if (max == con_alpha[con])
							issame = true;
					}

					if (!issame && max != 0) {
						ch_spot.push_back({i,j, 'A' + (char)real_con });
						ischange = true;
					}
				}
			}
		}

		for (int i = 0; i < ch_spot.size(); i++) {
			changing_spot t = ch_spot[i];
			area[t.y][t.x] = t.con;
		}
		ch_spot.clear();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << area[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}