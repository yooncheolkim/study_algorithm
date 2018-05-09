#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include<limits.h>
using namespace std;
vector<int> input;
vector<vector<int>> mem;
int main()
{
	int n;

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}
	int result = INT_MIN; 
	int recent_sum = 0;

	for (int i = 0; i < input.size(); i++)
	{
		recent_sum += input[i];

		if (recent_sum< 0)
		{
			result = result < recent_sum ? recent_sum : result;
			recent_sum = 0;
		}
		else
		{
			result = result < recent_sum ? recent_sum : result;
		}
	}

	cout << result << endl;

	return 0;
}