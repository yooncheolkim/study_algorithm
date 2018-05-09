#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int T, n;
int students[100001];
bool iscycle[100001];
bool visited[100001];
vector<int> p;
int result = 0;
void dfs(int idx, int start)
{
	visited[idx] = true;
	p.push_back(idx);

	if (visited[students[idx]])
	{

	}
	if (students[idx] == start)
	{
		for (auto i : p)
			iscycle[i] = true;
	}

	dfs(students[idx], start);
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(students, 0, sizeof(students));
		memset(iscycle, false, sizeof(iscycle));
		memset(visited, false, sizeof(visited));
		cin >> n;
		result = n;
		for (int j = 1; j <= n; j++)
			cin >> students[j];

		for (int j = 1; j <= n; j++)
		{
			dfs(j,j);
		}
		
		
	}
	return 0;
}