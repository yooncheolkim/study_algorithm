#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long mem[101] = { 0,1,1,1,2,2};
long long p(long long n)
{
	if (n <= 5)
		return mem[n];
	if (mem[n] != 0)
		return mem[n];
	else
	{
		mem[n] = p(n - 1) + p(n - 5);
		return mem[n];
	}
}
int main()
{
	int t;
	cin >> t;
	int temp;
	vector<long long> result;
	for (int i = 0; i < t; i++)
	{
		cin >> temp;
		result.push_back(p(temp));
	}

	for (int i = 0; i < t; i++)
		cout << result[i] << endl;

	return 0;
}