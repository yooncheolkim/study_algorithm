#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int N;

int T[1001]; // 수행 날짜
int P[1001]; // 이익
int dp[1001];

int go(int day) {
	if (dp[day] != -1) return dp[day];
	if (day > N) return 0;

	//선택 할때 -> go(day+T[day]) + P[day]
	//선택 안할때 -> go(day+1)
	//둘중 어떤것이 더 이득인지
	int res = 0;
	if (day + T[day] <= N + 1)
		res = max(go(day + T[day]) + P[day], go(day + 1));
	else
		res = go(day + 1);

	return dp[day] = res;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> T[i + 1] >> P[i + 1];
	
	cout << go(1) << endl;

	return 0;
}