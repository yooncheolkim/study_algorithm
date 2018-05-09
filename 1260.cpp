#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void dfs(int);
void bfs();
int map[1001][1001];
bool visited[1001];

queue <int> work1;
stack<int>work2;
int start_p;

vector<int> result_bfs;
vector<int> result_dfs;

int main()
{
	int n, m;
	cin >> n >> m >> start_p;

	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;

		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}

	bfs();
	memset(visited, false, sizeof(visited));
	dfs(start_p);


	for (int i = 0; i < result_dfs.size(); i++)
	{
		if (i == result_dfs.size() - 1)
		{
			printf("%d\n", result_dfs[i]);
			break;
		}
		printf("%d ", result_dfs[i]);
	}

	for (int i = 0; i < result_bfs.size(); i++)
	{
		if (i == result_bfs.size() - 1)
		{
			printf("%d\n", result_bfs[i]);
			break;
		}
		printf("%d ", result_bfs[i]);
	}

	return 0;
}

void bfs()
{
	work1.push(start_p);
	visited[start_p] = true;
	while (!work1.empty())
	{
		int temp_v = work1.front();
		result_bfs.push_back(temp_v);
		work1.pop();
		for (int i = 0; i < 1001; i++)
		{
			if (map[temp_v][i] == 1 && visited[i] == false)
			{
				work1.push(i);
				visited[i] = true;
			}
		}
	}
}

void dfs(int a) 
{
	visited[a] = true;
	result_dfs.push_back(a);

	for (int i = 0; i < 1001; i++)
	{
		if (map[a][i] == 1 && visited[i] == false)
		{
			dfs(i);
		}
	}
}