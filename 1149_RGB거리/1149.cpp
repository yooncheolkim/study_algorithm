#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
//������ ���� ����,�Ķ�,�ʷ����� ĥ�Ҷ� �ּҰ��� ���� ������
//�ᱹ ������ 3���� �ּڰ��� ���ϸ� �ȴ�.

//0 ����, 1 �ʷ�, 2 �Ķ�
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