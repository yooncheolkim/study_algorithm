#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct tong {
	int a, b, c;
};

int A, B, C;
bool vis[201];
vector<int> result;
queue<tong> work;
//[a][b][c]  
bool visited[201][201][201];


void bfs()
{
	while (!work.empty())
	{
		tong t = work.front();
		work.pop();

		//º×±â
		//A->B
		if (t.a != 0)
		{
			if (t.a + t.b > B)
			{
				if (!visited[t.a - (B - t.b)][B][t.c])
				{
					visited[t.a - (B - t.b)][B][t.c] = true;
					work.push({ t.a - (B - t.b) ,B,t.c });
					if (t.a - (B - t.b) == 0) result.push_back(t.c);
				}
			}
			else
			{
				if (!visited[0][t.b + t.a][t.c])
				{
					visited[0][t.b + t.a][t.c] = true;
					work.push({ 0,t.b + t.a,t.c });
					result.push_back(t.c);
				}
			}
		}
		//A->C
		if (t.a != 0)
		{
			if (t.a + t.c > C)
			{
				if (!visited[t.a - (C - t.c)][t.b][C])
				{
					visited[t.a - (C - t.c)][t.b][C] = true;
					work.push({ t.a - (C - t.c) ,t.b,C });
					if (t.a - (C - t.c) == 0) result.push_back(C);
				}
			}
			else
			{
				if (!visited[0][t.b][t.a + t.c])
				{
					visited[0][t.b][t.a + t.c] = true;
					work.push({ 0,t.b,t.a + t.c });
					result.push_back(t.a+t.c);
				}
			}
		}
		//B->A
		if (t.b != 0)
		{
			if (t.b + t.a > A)
			{
				if (!visited[A][t.b - (A - t.a)][t.c])
				{
					visited[A][t.b - (A - t.a)][t.c] = true;
					work.push({ A ,t.b - (A - t.a),t.c });
				}
			}
			else
			{
				if (!visited[t.b + t.a][0][t.c])
				{
					visited[t.b + t.a][0][t.c] = true;
					work.push({ t.b + t.a,0,t.c });
					if (t.b + t.a == 0) result.push_back(t.c);
				}
			}
		}
		//B->C
		if (t.b != 0)
		{
			if (t.b + t.c > C)
			{
				if (!visited[t.a][t.b - (C - t.c)][C])
				{
					visited[t.a][t.b - (C - t.c)][C] = true;
					work.push({ t.a ,t.b - (C - t.c),C });
					if (t.a == 0) result.push_back(C);
				}
			}
			else
			{
				if (!visited[t.a][0][t.b + t.c])
				{
					visited[t.a][0][t.b + t.c] = true;
					work.push({ t.a,0,t.b + t.c });
					if (t.a == 0) result.push_back(t.b + t.c);
				}
			}
		}
		//C->A
		if (t.c != 0)
		{
			if (t.c + t.a > A)
			{
				if (!visited[A][t.b][t.c - (A - t.a)])
				{
					visited[A][t.b][t.c - (A - t.a)] = true;
					work.push({ A ,t.b,t.c - (A - t.a) });
				}
			}
			else
			{
				if (!visited[t.c + t.a][t.b][0])
				{
					visited[t.c + t.a][t.b][0] = true;
					work.push({ t.c + t.a,t.b,0 });
					if (t.c + t.a == 0) result.push_back(0);
				}
			}
		}
		//C->B
		if (t.c != 0)
		{
			if (t.c + t.b > B)
			{
				if (!visited[t.a][B][t.c - (B - t.b)])
				{
					visited[t.a][B][t.c - (B - t.b)] = true;
					work.push({ t.a ,B, t.c - (B - t.b) });
					if (t.a == 0) result.push_back(t.c - (B - t.b));
				}
			}
			else
			{
				if (!visited[t.a][t.c + t.b][0])
				{
					visited[t.a][t.c + t.b][0] = true;
					work.push({ t.a,t.c + t.b,0 });
					if (t.a == 0) result.push_back(0);
				}
			}
		}
	}

}


int main()
{
	memset(visited, false, sizeof(visited));
	memset(vis, false, sizeof(vis));
	cin >> A >> B >> C;
	
	work.push({ 0,0,C });
	visited[0][0][C] = true;
	result.push_back(C);

	bfs();

	vector<int> result2;
	for (int i = 0; i < result.size(); i++)
	{
		if (!vis[result[i]])
		{
			result2.push_back(result[i]);
			vis[result[i]] = true;
		}
	}

	sort(result2.begin(), result2.end());

	for (int i = 0; i < result2.size(); i++)
	{
		cout << result2[i] << " ";
	}
		
	cout << endl;

	return 0;
}