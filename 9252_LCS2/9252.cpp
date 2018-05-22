#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int dp[1001][1001];
string input1;
string input2;
stack<char> result;
int go(int a, int b)
{
	if (a < 0 || b < 0) return 0;

	if (dp[a][b] != -1) return dp[a][b];

	if (input1[a] == input2[b])
		return dp[a][b] = go(a - 1, b - 1) + 1;
	else
		return dp[a][b] = max(go(a - 1, b), go(a, b - 1));
}
int main()
{
	memset(dp, -1, sizeof(dp));
	
	cin >> input1 >> input2;

	if (input1[0] == input2[0])
	{
		for (int i = 0; i < input1.length(); i++)
			dp[i][0] = 1;
		for (int j = 0; j < input2.length(); j++)
			dp[0][j] = 1;
	}
	else
		dp[0][0] = 0;

	for (int i = 0; i < input1.length(); i++)
	{
		for (int j = 0; j < input2.length(); j++)
			go(i, j);
	}

	cout << go(input1.length()-1, input2.length()-1) << endl;

	int i = input1.length() - 1;
	int j = input2.length() - 1;

	while (i >= 0 && j >= 0)
	{
		if (input1[i] == input2[j])
		{
			result.push(input1[i]);
			i--;
			j--;
			continue;
		}
		else
		{
			if (dp[i][j] == dp[i][j - 1])
			{
				j--;
				continue;
			}
			else if (dp[i][j] == dp[i - 1][j])
			{
				i--;
				continue;
			}
		}
	}

	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result.top();
		result.pop();
	}

	cout << endl;
	return 0;
}