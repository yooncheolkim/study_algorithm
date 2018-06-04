#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct pos {
	int y, x;
	int dis;
};
//각각의 거리 구하기
int dis[11][11];
bool visited[21][21];
//dp[현재][방문한곳]
int dp[21][1 << 11];
vector<string> input;
queue<pos> work;
vector<pos> waste;
pos start;
int w, h;
void bfs(int idx)
{
	int d_x[4] = { 0,0,-1,1 };
	int d_y[4] = { 1,-1,0,0 };
	while (!work.empty())
	{
		pos curr = work.front();
		work.pop();

		for (int i = 0; i < waste.size(); i++)
		{
			if (curr.y == waste[i].y && curr.x == waste[i].x)
			{
				dis[idx][i] = dis[i][idx] = curr.dis;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int dx = d_x[i] + curr.x;
			int dy = d_y[i] + curr.y;

			if (0 <= dx && dx < w && 0 <= dy && dy < h
				&& !visited[dy][dx] && input[dy][dx] != 'x')
			{
				visited[dy][dx] = true;
				pos p;
				p.y = dy; p.x = dx;
				p.dis = curr.dis + 1;
				work.push(p);
			}
		}
		
	}
}

int tsp(int cur, int visited)
{
	if (visited == (1 << waste.size()) - 1) return dp[cur][visited];

	if (dp[cur][visited] != -1) return dp[cur][visited];
	
	//다음으로 갈 가장 짧은 거리 구하기
	int result = 99999999;

	for (int next = 0; next < waste.size(); next++)
	{
		// visted 에 next 가 포함되어 있으면
		if ((visited & (1 << next)) != 0) continue;
		// cur 이랑 next 랑 같은 점이면
		if (dis[cur][next] == 0) continue;

		result = min(result, tsp(next, visited | (1 << next)) + dis[cur][next]);
		dp[next][ visited | (1 << next)] = result;
	}
	return result;
	
}
int main()
{

	
	while (1) 
	{
		memset(visited, false, sizeof(visited));
		memset(dis, -1, sizeof(dis));
		input.clear();
		waste.clear();
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++)
		{
			string st;
			cin >> st;
			input.push_back(st);
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (input[i][j] == 'o')
				{
					waste.push_back({ i,j,0 });
					start.y = i; start.x = j;
				}
				if (input[i][j] == '*')
					waste.push_back({ i,j,0 });
			}
		}
		
		for (int i = 0; i < waste.size(); i++)
		{
			memset(visited, false, sizeof(visited));
			work.push(waste[i]);
			visited[waste[i].y][waste[i].x] = true;
			bfs(i);
		}

		memset(dp, -1, sizeof(dp));
		int start_idx = 0;
		for (int i = 0; i < waste.size(); i++)
		{
			if (waste[i].y == start.y && waste[i].x == start.x)
				start_idx = i;
		}
		//외판원 순회...
		//시작점
		int reuslt = tsp(start_idx, 1 << start_idx) + 1;
		
		if (reuslt < 0) cout << -1 << endl;
		else cout << reuslt << endl;
	}

	return 0;
}