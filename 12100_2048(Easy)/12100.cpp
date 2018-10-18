#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int N;
int area[21][21];
int temp_area[21][21];
int max_result = 0;

void move_dir(int dir) {

	if (dir == 0) {
		for (int x = 0; x < N; x++) {
			int curr_num = 0;
			vector<int> collection;
			for (int y = 0; y < N; y++) {
				if (y == N-1) {
					if (curr_num != 0) {
						if (temp_area[y][x] == 0)
							collection.push_back(curr_num);
						else if (temp_area[y][x] != 0) {
							if (temp_area[y][x] == curr_num) {
								collection.push_back(curr_num + curr_num);
								curr_num = 0;
								continue;
							}
							collection.push_back(curr_num);
							collection.push_back(temp_area[y][x]);
						}
					}
					if (curr_num == 0) {
						collection.push_back(temp_area[y][x]);
					}
					continue;
				}
				if (curr_num != 0 && temp_area[y][x] == curr_num) {
					collection.push_back(curr_num + curr_num);
					curr_num = 0;
					continue;
				}
				if(curr_num != 0 && temp_area[y][x] != curr_num && temp_area[y][x] != 0){
					collection.push_back(curr_num);
					curr_num = temp_area[y][x];
					continue;
				}
				if (curr_num == 0 && temp_area[y][x] != 0) {
					curr_num = temp_area[y][x];
					continue;
				}
			}
			for (int i = 0; i < collection.size(); i++)
				temp_area[i][x] = collection[i];
			for (int i = collection.size(); i < N; i++)
				temp_area[i][x] = 0;
		}
	}

	if (dir == 1) {
		for (int y = 0; y < N; y++) {
			int curr_num = 0;
			vector<int> collection;
			for (int  x = N-1; x >= 0; x--) {
				if (x == 0) {
					if (curr_num != 0) {
						if (temp_area[y][x] == 0)
							collection.push_back(curr_num);
						else if (temp_area[y][x] != 0) {
							if (temp_area[y][x] == curr_num) {
								collection.push_back(curr_num + curr_num);
								curr_num = 0;
								continue;
							}
							collection.push_back(curr_num);
							collection.push_back(temp_area[y][x]);
						}
					}
					if (curr_num == 0) {
						collection.push_back(temp_area[y][x]);
					}
					continue;
				}
				if (curr_num != 0 && temp_area[y][x] == curr_num) {
					collection.push_back(curr_num + curr_num);
					curr_num = 0;
					continue;
				}
				if (curr_num != 0 && temp_area[y][x] != curr_num && temp_area[y][x] != 0) {
					collection.push_back(curr_num);
					curr_num = temp_area[y][x];
					continue;
				}
				if (curr_num == 0 && temp_area[y][x] != 0 ) {
					curr_num = temp_area[y][x];
					continue;
				}
			}
			for (int i = 0; i < collection.size(); i++)
				temp_area[y][N-i-1] = collection[i];
			for (int i = collection.size(); i < N; i++)
				temp_area[y][N-i-1] = 0;
		}
	}

	if (dir == 2) {
		for (int x = 0; x < N; x++) {
			int curr_num = 0;
			vector<int> collection;
			for (int y = N-1; y >= 0; y--) {
				if (y == 0) {
					if (curr_num != 0) {
						if (temp_area[y][x] == 0)
							collection.push_back(curr_num);
						else if (temp_area[y][x] != 0) {
							if (temp_area[y][x] == curr_num) {
								collection.push_back(curr_num + curr_num);
								curr_num = 0;
								continue;
							}
							collection.push_back(curr_num);
							collection.push_back(temp_area[y][x]);
						}
					}
					if (curr_num == 0) {
						collection.push_back(temp_area[y][x]);
					}
					continue;
				}
				if (curr_num != 0 && temp_area[y][x] == curr_num) {
					collection.push_back(curr_num + curr_num);
					curr_num = 0;
					continue;
				}
				if (curr_num != 0 && temp_area[y][x] != curr_num && temp_area[y][x] != 0) {
					collection.push_back(curr_num);
					curr_num = temp_area[y][x];
					continue;
				}
				if (curr_num == 0 && temp_area[y][x] != 0) {
					curr_num = temp_area[y][x];
					continue;
				}
			}
			for (int i = 0; i < collection.size(); i++)
				temp_area[N-i-1][x] = collection[i];
			for (int i = collection.size(); i < N; i++)
				temp_area[N-i-1][x] = 0;
		}
	}

	if (dir == 3) {
		for (int y = 0; y < N; y++) {
			int curr_num = 0;
			vector<int> collection;
			for (int x = 0; x < N; x++) {
				if (x == N-1) {
					if (curr_num != 0) {
						if (temp_area[y][x] == 0)
							collection.push_back(curr_num);
						else if (temp_area[y][x] != 0) {
							if (temp_area[y][x] == curr_num) {
								collection.push_back(curr_num + curr_num);
								curr_num = 0;
								continue;
							}
							collection.push_back(curr_num);
							collection.push_back(temp_area[y][x]);
						}
					}
					if (curr_num == 0) {
						collection.push_back(temp_area[y][x]);
					}
					continue;
				}
				if (curr_num != 0 && temp_area[y][x] == curr_num) {
					collection.push_back(curr_num + curr_num);
					curr_num = 0;
					continue;
				}
				if (curr_num != 0 && temp_area[y][x] != curr_num && temp_area[y][x] != 0) {
					collection.push_back(curr_num);
					curr_num = temp_area[y][x];
					continue;
				}
				if (curr_num == 0 && temp_area[y][x] != 0) {
					curr_num = temp_area[y][x];
					continue;
				}
			}
			for (int i = 0; i < collection.size(); i++)
				temp_area[y][i] = collection[i];
			for (int i = collection.size(); i < N; i++)
				temp_area[y][i] = 0;
		}
	}
}

void check(vector<int>curr_dir) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp_area[i][j] = area[i][j];
		}
	}

	for (int i = 0; i < curr_dir.size(); i++) {
		move_dir(curr_dir[i]);
	}

	int max_block = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			max_block = max_block < temp_area[i][j] ? temp_area[i][j] : max_block;
		}
	}
	max_result = max_result < max_block ? max_block : max_result;
}

void go(vector<int> curr_dir) {
	if (curr_dir.size() == 5) {
		check(curr_dir);
		return;
	}

	for (int i = 0; i < 4; i++) {
		curr_dir.push_back(i);
		go(curr_dir);
		curr_dir.pop_back();
	}
	
}
int main(){
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
		}
	}
	vector<int> dir;
	go(dir);

	cout << max_result << endl;

	return 0;
}