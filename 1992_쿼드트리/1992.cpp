#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
vector<string> input;
int N;
void dq(int y , int x,int size,int braket_check)
{
	bool issame = true;
	char first = input[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (input[i][j] != first)
			{
				issame = false;
				break;
			}
		}
		if (!issame) break;
	}

	if (!issame)
	{
		cout << "(";
		dq(y, x, size / 2, 1);
		dq(y, x + size / 2, size / 2, 3);
		dq(y + size/2, x, size / 2,2);
		dq(y + size/2, x + size/2, size / 2,4);
		cout << ")";
	}
	else
	{
		cout << first;
	}
}
int main()
{
	cin >> N;
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	dq(0, 0, N, 1);
	cout << endl;
	return 0;
}