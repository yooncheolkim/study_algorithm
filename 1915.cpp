#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>> input;
int mem[1001][1001];
int top_y = 0;
int top_x = 0;
int bottom_y = 0;
int bottom_x = 0;
int size = 0;

int main()
{
	int r, c;
	cin >> r >> c;
	int temp;
	for (int i = 0; i < r; i++)
	{
		input.push_back(vector<int>());
		for (int j = 0; j < c; j++)
		{
			cin >> temp;
			input[i].push_back(temp);
		}
	}

	memset(mem, -1, sizeof(mem));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (mem[i][j] != -1)
				continue;
			go(i, j);
		}
	}
	return 0;
}