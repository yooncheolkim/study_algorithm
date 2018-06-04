#include <iostream>
#include <string.h>
using namespace std;
int N, S, M;
int V[101];

bool dp[101][1001];

int main()
{
	cin >> N >> S >> M;

	memset(dp, false, sizeof(dp));
	for (int i = 1; i <= N; i++)
		cin >> V[i];


	dp[0][S] = true;

	//v - V[i] v+V[i] 가 가능하면, i번째 곡의 볼륨이 가능한거
	for (int i = 1; i <= N; i++)
	{
		for (int v = 0; v <= M; v++)
		{
			if (!dp[i - 1][v])
				continue;
			if (v - V[i] >= 0)
				dp[i][v - V[i]] = true;
			if (v + V[i] <= M)
				dp[i][v + V[i]] = true;
		}
	}

	bool flag = false;
	for (int v = M; v >= 0; v--)
	{
		if (dp[N][v])
		{
			flag = true;
			cout << v << endl;
			break;
		}
	}

	if (!flag)
		cout << -1 << endl;
	return 0;
}