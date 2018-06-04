#include <iostream>
#include <string.h>
using namespace std;
int dp[10][101];
int rmd = 1000000000;
int main()
{
	memset(dp, -1, sizeof(dp));

	dp[0][1] = 0;
	for (int i = 1; i < 10; i++)
	{
		dp[i][1] = 1;
	}

	int n;
	cin >> n;
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[j][i] = dp[j + 1][i-1] % rmd;
			else if (j == 9)
				dp[j][i] = dp[j - 1][i-1] % rmd;
			else
				dp[j][i] = (dp[j - 1][i-1] + dp[j + 1][i-1]) % rmd;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += dp[i][n];
		result %= rmd;
	}

	cout << result << endl;
	
	return 0;
}