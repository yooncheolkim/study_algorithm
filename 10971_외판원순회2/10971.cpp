#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
int w[11][11];
int dp[11][1 < 12];
int go(int cur, int visited)
{
	if (((1 << N) - 1) == visited)
		return w[cur][0];

	int &ret = dp[cur][visited];

	if (ret != 0) return ret;

	ret = 999999999;

	for (int next = 0; next < N; next++)
	{
		if (w[cur][next] == 0) continue;
		if (((1 << next) & visited) != 0) continue;

		ret = min(ret, go(next, visited | (1 << next)) + w[cur][next]);
	}
	return ret;
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> w[i][j];
		}
	}

	memset(dp, 0, sizeof(dp));

	cout << go(0, 1) << endl;

	return 0;
}
