#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int mem[1001];
vector<int> miro;
int dp(int a)
{
	if (mem[a] != -1)
		return mem[a];
	if (a == 0)
	{
		mem[a] = 0;
		return 0;
	}

	int result = -1;
	for (int i = 0; i < a; i++)
	{
		if (i + miro[i] >= a) // i 에서 a로 갈수 있음
		{
			result = dp(i);
			break;
		}
	}
	if (result == -1)
		return result;

	mem[a] = result + 1;
	return mem[a];
}
int main()
{
	int n;
	int temp;
	cin >> n;
	memset(mem, -1, sizeof(mem));
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		miro.push_back(temp);
	}

	cout << dp(n - 1) << endl;
	return 0;
}