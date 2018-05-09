#include <iostream>
using namespace std;
void Go(int, int);
int N;
int arr[10] = { 0, };
int dp[1000000001] = { 0, };
int main()
{
	
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		Go(10, i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}
void Go(int div, int n)
{
	if (n == 0)
		return;

	int temp = n%div;
	int temp2 = n / div;

	arr[temp]++;

	Go(10, temp2);
}