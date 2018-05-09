#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[1001][1001]; // �ε����� idx�� ������ �պκг����� ���� ������ ����
//���� ����..
//dp ������ �غ��� ���� ���ʰ� �����Ŷ� �ٸ��� �밢�� +1 ����Ѱ� �ϱ�
//���ٷ� ����ϸ��...
string A, B;
int go(int a, int b)
{
	if (a < 0 || b < 0) return 0;

	if (dp[a][b] != -1) return dp[a][b];

	if (A[a] == B[b])
		return dp[a][b] = go(a - 1, b - 1) + 1;
	else
		return dp[a][b] = max(go(a - 1, b), go(a, b - 1));
}
int main()
{
	cin >> A >> B;
	memset(dp, -1, sizeof(dp));
	
	if (A[0] == B[0])
	{
		for(int i = 0; i < A.length() ; i++)
			dp[i][0] = 1;
		for (int j = 0; j < B.length(); j++)
			dp[0][j] = 1;
	}
	else
		dp[0][0] = 0;

	cout << go(A.length() - 1, B.length() - 1) << endl;
	
	return 0;
}