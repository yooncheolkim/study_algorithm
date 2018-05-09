#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct Pair {
	int y, x;
	int cnt;
	Pair(int a, int b, int c) {
		y = a;
		x = b;
		cnt = c;
	}
};

int bfs();
int map[101][101];
bool visited[101][101];
int n, m;
queue<Pair> work;

int main()
{
	memset(map, -1, sizeof(map));
	scanf("%d", &n);
	scanf("%d", &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	memset(visited, false, sizeof(visited));


	cout <<bfs() << endl;
	return 0;
}

int bfs() 
{
	work.push(Pair(0, 0,1));
	visited[0][0] = true;

	int mov_y[4] = {0,0,1,-1};
	int mov_x[4] = {1,-1,0,0};
	while (!work.empty())
	{
		Pair temp = work.front();
		work.pop();
		if (temp.y == n - 1 && temp.x == m - 1)
			return temp.cnt;
		for (int i = 0; i < 4; i++)
		{
			int temp_y = temp.y + mov_y[i];
			int temp_x = temp.x + mov_x[i];

			if ((0 <= temp_y) && (temp_y < n) && (0 <= temp_x) && (temp_x < m) && visited[temp_y][temp_x] == false && map[temp_y][temp_x] ==1)
			{
				work.push(Pair(temp_y, temp_x, temp.cnt + 1));
				visited[temp_y][temp_x] = true;
			}
		}
	}
}