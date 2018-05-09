#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
struct pos {
	int y, x;
};
int N;
string area[101];
char rg_area[101][101];
bool visited[101][101];
queue<pos> work;

void bfs(char a)
{
	int move_x[] = { -1,1,0,0 };
	int move_y[] = { 0,0,1,-1 };

	while (!work.empty())
	{
		pos p = work.front();
		work.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = move_y[i] + p.y;
			int dx = move_x[i] + p.x;

			if (dy >= 0 && dy < N && dx >= 0 && dx < N
				&& !visited[dy][dx])
			{
				//bfs로 가지고온 거랑 같으면.. bfs 계속
				if (area[dy][dx] == a)
				{
					work.push({ dy,dx });
					visited[dy][dx] = true;
				}
			}
		}
	}
}

void rg_bfs(char a)
{
	int move_x[] = { -1,1,0,0 };
	int move_y[] = { 0,0,1,-1 };

	while (!work.empty())
	{
		pos p = work.front();
		work.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = move_y[i] + p.y;
			int dx = move_x[i] + p.x;

			if (dy >= 0 && dy < N && dx >= 0 && dx < N
				&& !visited[dy][dx])
			{
				//bfs로 가지고온 거랑 같으면.. bfs 계속
				if (rg_area[dy][dx] == a)
				{
					work.push({ dy,dx });
					visited[dy][dx] = true;
				}
			}
		}
	}
}
int main()
{
	int result = 0;
	int rg_result = 0;

	cin >> N;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		cin >> area[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (area[i][j] == 'G')
				rg_area[i][j] = 'R';
			else
				rg_area[i][j] = area[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				work.push({ i,j });
				bfs(area[i][j]);
				result++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				work.push({ i,j });
				rg_bfs(rg_area[i][j]);
				rg_result++;
			}
		}
	}

	cout << result << " " << rg_result << endl;
	return 0;
}