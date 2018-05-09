#include <iostream>
#include <algorithm>
using namespace std;
int eu(int, int);
int main()
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;

		int gcm = eu(a, b);
		int lcm = a * b / gcm;
		cout << lcm << endl;
	}

	return 0;
}

int eu(int x, int y)
{
	int n;

	while (1)
	{
		n = x%y;
		if (n == 0) return y;
		x = y;
		y = n;
	}
}
