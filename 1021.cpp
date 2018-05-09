#include <iostream>
#include <vector>
using namespace std;
void l_shift();
void r_shift();
vector<int> q;
vector<int> input;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		q.push_back(i);

	int result = 0;
	int pop_ele = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> pop_ele;
		input.push_back(pop_ele);
	}

	for (int i = 0; i < m; i++)
	{
		pop_ele = input[i];

		int recent_loc = 0;
		int lot_cnt = 0;
		int lot_dir = 0; // 0이면 왼쪽, 1이면 오른쪽
		for (int i = 0; i < q.size(); i++)
		{
			if (q[i] == pop_ele)
			{
				recent_loc = i;
				break;
			}
		}

		if (q.size() - recent_loc <= recent_loc)
		{
			lot_cnt = q.size() - recent_loc;
			lot_dir = 1;
		}
		else
		{
			lot_cnt = recent_loc;
			lot_dir = 0;
		}


		if (lot_dir == 0)
		{
			if (lot_cnt == 0){}
			else
			{
				for (int j = 0; j < lot_cnt; j++)
					l_shift();
			}
		}
		else if (lot_dir == 1)
		{
			if (lot_cnt == 0){}
			else
			{
				for (int j = 0; j < lot_cnt; j++)
					r_shift();
			}
		}

		result += lot_cnt;
		q.erase(q.begin());
	}

	cout << result << endl;
	return 0;
}

void l_shift()
{
	q.push_back(q.front());
	q.erase(q.begin());
}

void r_shift()
{
	q.insert(q.begin(), q.back());
	q.pop_back();
}


