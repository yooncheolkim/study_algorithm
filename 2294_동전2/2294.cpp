#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int mem[101][10001];
int n, k;
vector<int> coin;
int go(int n, int k)
{
	if (mem[n][k] != -1) return mem[n][k];

	if (coin[n] > k)
		return mem[n][k] = go(n-1,k);
	if(k%coin[n] ==0) return mem[n][k] = k / coin[n];

	return mem[n][k] = min(go(n - 1, k), go(n,k - coin[n])+1);
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}

	memset(mem, -1, sizeof(mem));
	for (int i = 1; i <= k; i++)
	{
		if (i%coin[0] == 0)
			mem[0][i] = i / coin[0];
		else mem[0][i] = 999999999;
	}
	for (int i = 0; i < n; i++)
		mem[i][0] = 999999999;
	sort(coin.begin(), coin.end());

	if (go(n - 1, k) == 999999999)
		cout << -1 << endl;
	else
		cout << go(n - 1, k) << endl;

	return 0;
}