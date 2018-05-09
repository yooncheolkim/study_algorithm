#include <iostream>
#include <vector>
using namespace std;
vector<int> coin;
int N, K;
int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}
	int result = 0;

	for (int i = coin.size() - 1; i >= 0; i--)
	{
		//³ª´©¾î ¶³¾îÁö¸é ³ª´«´Ù.
		if (K >= coin[i])
		{
			result += (K / coin[i]);
			K = K % coin[i];
		}
	}

	cout << result << endl;
	return 0;
}