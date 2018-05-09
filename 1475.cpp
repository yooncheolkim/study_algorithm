#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> result;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (!q.empty())
	{
		for (int i = 0; i < m-1; i++)
		{
			int temp1 = q.front();
			q.pop();

			q.push(temp1);
		}
		result.push_back(q.front());
		q.pop();
	}

	printf("<");
	for (int i = 0; i < result.size(); i++)
	{
		if (i == result.size() - 1)
		{
			printf("%d>\n", result[i]);
			break;
		}
		printf("%d, ", result[i]);
	}
	return 0;
}