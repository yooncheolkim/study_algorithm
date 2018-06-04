#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int w[1001][1001];
int n, m;
int target_s, target_e;
int result = 999999999;
vector<int> result_path;
void dfs(vector<int> path, int cost)
{
	if (path[path.size() - 1] == target_e)
	{
		if (result > cost)
		{
			result_path = path;
			result = cost;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		//path에 i 포함 x && i로 가는 길이 있다면
		if (find(path.begin(), path.end(), i) == path.end() && w[path[path.size() - 1]][i] > 0)
		{
			int temp_cost = cost + w[path[path.size() - 1]][i];
			vector<int> temp_path = path;
			temp_path.push_back(i);
			dfs(temp_path, temp_cost);
		}
	}
}
int main()
{

	cin >> n >> m;

	memset(w, 0, sizeof(w));
	for (int i = 0; i < m; i++)
	{
		int start, end, weight;

		cin >> start >> end >> weight;
		w[start][end] = weight;
	}
	
	cin >> target_s >> target_e;

	vector<int> path;
	path.push_back(target_s);

	dfs(path,0);

	cout << result << endl;
	cout << result_path.size() << endl;
	for (auto i : result_path)
	{
		cout << i << " ";
	}
	cout << endl;



	return 0;
}