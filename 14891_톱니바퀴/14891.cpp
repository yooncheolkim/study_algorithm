#include <iostream>
#include <deque>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
struct topni {
	deque<int> state;

	void turn(int dir)
	{
		if (dir == -1)
		{
			state.push_back(state.front());
			state.pop_front();
		}
		else if (dir == 1)
		{
			state.push_front(state.back());
			state.pop_back();
		}
	}
};
topni t[4];
bool checked[4];

//현재 고려할 톱니번호, 돌아가야할 방향
void checkturn(int top_num, int turn_num)
{
	if (checked[top_num]) return;

	if (top_num == 0)
	{
		if (t[top_num].state[2] != t[top_num + 1].state[6])
		{
			t[top_num].turn(turn_num);
			checked[top_num] = true;
			checkturn(top_num + 1, -1 * turn_num);
		}
		else
		{
			t[top_num].turn(turn_num);
			checked[top_num] = true;
		}
	}
	else if (top_num == 3)
	{
		if (t[top_num].state[6] != t[top_num - 1].state[2])
		{
			t[top_num].turn(turn_num);
			checked[top_num] = true;
			checkturn(top_num - 1, -1 * turn_num);
		}
		else 
		{
			t[top_num].turn(turn_num);
			checked[top_num] = true;
		}
	}
	else
	{
		if (t[top_num].state[6] != t[top_num - 1].state[2])
		{
			checked[top_num] = true;
			checkturn(top_num - 1, -1 * turn_num);
		}
		if (t[top_num].state[2] != t[top_num + 1].state[6])
		{
			checked[top_num] = true;
			checkturn(top_num + 1, -1 * turn_num);
		}

		t[top_num].turn(turn_num);
		checked[top_num] = true;
	}

}
int main()
{
	string temp;

	//N극은 0 S극은 1
	for (int i = 0; i < 4; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
			t[i].state.push_back(temp[j] - '0');
		temp.clear();
	}

	int k;

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int top_num;
		int turn_num;

		cin >> top_num >> turn_num;
		memset(checked, false, sizeof(checked));
		checkturn(top_num-1,turn_num);
	}

	int result = 0;

	for (int i = 0; i < 4; i++)
	{
		if (t[i].state[0] == 1)
			result += pow(2, i);
	}

	cout << result << endl;
	return 0;
}