#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct pos {
	int y, x;
	int cnt;
};

queue<pos> works;
int M, N;
int tomato[1001][1001];
bool visited[1001][1001];

bool isik()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tomato[i][j] == 0)
				return false;
		}
	}

	return true;
}

int bfs()
{
	int t_x[4] = {0,0,-1,1};
	int t_y[4] = {1,-1,0,0};
	pos p;
	while (!works.empty())
	{
		p = works.front();
		works.pop();

		/*
		if (isik())
			return p.cnt;
			*/

		for (int i = 0; i < 4; i++)
		{
			int ty = p.y + t_y[i];
			int tx = p.x + t_x[i];

			if (0 <= ty && ty < N && 0 <= tx && tx < M
				&& !visited[ty][tx] && tomato[ty][tx] == 0)
			{
				tomato[ty][tx] = 1;
				works.push({ ty,tx, p.cnt+1});
			}
		}
	}
	if (isik())
		return p.cnt;
	return -1;
}
int main()
{
	memset(tomato, -1,sizeof(tomato));
	memset(visited, false, sizeof(visited));
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tomato[i][j] == 1)
			{
				pos p{ i,j,0 };
				works.push(p);
				visited[i][j] = true;
			}
		}
	}
	
	cout << bfs() << endl;
	
	return 0;
}