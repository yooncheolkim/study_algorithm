//bfs -> 메모리초과
//dfs -> 시간초과..
#include <iostream>
#include <string.h>
using namespace std;
int move_x[] = { 0,0,1,-1 };
int move_y[] = { 1,-1,0,0 };
int N, M;
int dp[501][501];
int field[501][501];

int dfs(int y , int x)
{
	if (y == M-1 && x == N-1) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int dy = move_y[i] + y;
		int dx = move_x[i] + x;

		if (dy < M && dy >= 0 && dx < N && dx >= 0
			&& field[y][x] > field[dy][dx])
		{
			dp[y][x] += dfs(dy, dx);
		}
	}
	return dp[y][x];
}
int main()
{
	cin >> M >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> field[i][j];
		}
	}

	cout << dfs(0, 0) << endl;
	
	return 0;
}