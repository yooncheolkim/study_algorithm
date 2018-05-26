#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
int N;
int area[101][101];
bool visited[101][101];
struct pos {
	int y, x;
};
vector<vector<pos>> isls;
queue<pos> work;
void search()
{
	int d_x[4] = { 0,0,-1,1 };
	int d_y[4] = { 1,-1,0,0 };
	vector<pos> isl;
	while (!work.empty())
	{
		pos curr = work.front();
		work.pop();
		isl.push_back(curr);

		for (int i = 0; i < 4; i++)
		{
			int dx = curr.x + d_x[i];
			int dy = curr.y + d_y[i];

			if (0 <= dx && dx < N && 0 <= dy && dy < N
				&& !visited[dy][dx] && area[dy][dx] == 1)
			{
				visited[dy][dx] = true;
				work.push({ dy,dx });
			}
		}
	}

	isls.push_back(isl);
}

int distance(pos p1, pos p2)
{
	return abs(p1.y - p2.y) + abs(p1.x - p2.x);
}
int main()
{
	memset(area, -1, sizeof(area));
	memset(visited, false, sizeof(visited));
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> area[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && area[i][j] == 1)
			{
				visited[i][j] = true;
				work.push({ i,j });
				search();
			}
		}
	}
	
	int result = 999999999;
	for (int i = 0; i < isls.size()-1; i++)
	{
		for (int j = i + 1; j < isls.size(); j++)
		{
			vector<pos> i1 = isls[i];
			vector<pos> i2 = isls[j];

			for (int ii = 0; ii < i1.size(); ii++)
			{
				for (int jj = 0; jj < i2.size(); jj++)
				{
					int dis = distance(i1[ii], i2[jj]);
					result = result < dis ? result : dis;
				}
			}
		}
	}

	cout << result-1 << endl;

	return 0;
}