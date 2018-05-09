#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
//mem[n][k] = mem[n-1][k] + mem[n][k-coin[n]]??
int n, k;
int mem[10001];
vector<int> coin;
int main()
{
	cin >> n >> k;
	memset(mem, -1, sizeof(mem));
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}

	//init
	sort(coin.begin(), coin.end());
	mem[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		if (i % coin[0] == 0)
			mem[i] = 1;
		else mem[i] = 0;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = coin[i] ;j <= k; j++)
		{
			mem[j] = mem[j] + mem[j - coin[i]];
		}
	}

	cout << mem[k] << endl;
	return 0;
}