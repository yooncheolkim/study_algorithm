#include <iostream>
#include <set>
#include <string.h>
using namespace std;

int graph[1001][1001];
bool visited[1001];
int n, m;
int parents[1001];
set<int> num_group;


int find(int a)
{
	// 부모 노드를 찾는다.

	if (parents[a] == a) return a;

	//압축 해주기, 모두 부모 노드로...
	return parents[a] = find(parents[a]);
}
void uni(int l, int r)
{
	// 두개의 트리를 합친다.


	//부모 노드를 찾고.
	l = find(l);
	r = find(r);

	//큰쪽으로 맞춰 주기
	if (l < r) swap(l, r);

	//합치기
	parents[r] = l;
	for (int i = 1; i < 1001; i++)
	{
		if (parents[i] == r)
			parents[i] = l;
	}
}

void dfs(int y)
{
	visited[y] = true;
	for (int x = 1; x <= n; x++)
	{
		if (graph[y][x] == 1 && !visited[x])
			dfs(x);
	}
}
void way1()
{
	//dfs
	memset(graph, 0, sizeof(graph));
	memset(visited, false, sizeof(visited));
	cin >> n >> m;

	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		
		graph[u][v] = graph[v][u] = 1;
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << endl;
}




void way2()
{
	//union find
	for (int i = 1; i < 1001; i++)
		parents[i] = i;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		uni(a, b);
	}

	for (int i = 1; i <= n; i++)
	{
		find(i);
		num_group.insert(parents[i]);
	}

	cout << num_group.size() << endl;
}

int main()
{
	way2();
	return 0;
}
