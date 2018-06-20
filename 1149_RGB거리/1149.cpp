#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
//현재의 집을 빨강,파랑,초록으로 칠할때 최소값을 구해 나가서
//결국 마지막 3개의 최솟값을 구하면 된다.

//0 빨강, 1 초록, 2 파랑
int N;
int cost[3][1001];
int mem[3][1001];


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> cost[j][i];
		}
	}
	
	mem[0][0] = cost[0][0];
	mem[1][0] = cost[1][0];
	mem[2][0] = cost[2][0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
				mem[0][i] = min(mem[1][i - 1], mem[2][i - 1]) + cost[0][i];
			else if (j == 1)
				mem[1][i] = min(mem[0][i - 1], mem[2][i - 1]) + cost[1][i];
			else if (j == 2)
				mem[2][i] = min(mem[0][i - 1], mem[1][i - 1]) + cost[2][i];
		}
	}

	cout << min(mem[0][N - 1], min(mem[1][N - 1], mem[2][N - 1])) << endl;
	
	return 0;
}