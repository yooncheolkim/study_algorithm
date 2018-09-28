//1억 번이면,, 대략 1초.. 
//13C6 10
// 10^5 nlogn
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct spot {
	int y, x;
};
int N, M;
vector<spot> homes;
vector<spot> chicks;

int getDist(const spot & a, const spot & b) {
	return abs(a.y - b.y) + abs(a.x - b.x);
}

int dfs(vector<spot> combiChicks, int idx) {
	//거리 계산
	int ret = 99999999;
	if (combiChicks.size() == M) {
		int sum = 0;
		for (int i = 0; i < homes.size(); i++) {
			int minVal = 99999999;
			for (int j = 0; j < combiChicks.size(); j++) {
				minVal = min(minVal, getDist(homes[i], combiChicks[j]));
			}
			sum += minVal;
		}
		return min(ret, sum);
	}

	//치킨집 고르기
	for (int i = idx; i < chicks.size(); i++) {
		combiChicks.push_back(chicks[i]);
		ret = min(ret, dfs(combiChicks, i + 1));
		combiChicks.pop_back();
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (input == 1)
				homes.push_back({ i,j });
			else if (input == 2)
				chicks.push_back({ i,j });
		}
	}
	vector<spot> combiChicks;
	cout << dfs(combiChicks, 0) << endl;

	return 0;
}