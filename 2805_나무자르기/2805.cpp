#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> trees(n);

	// 이분탐색 , mid로 잘랐을때 가능한가?
	long long left = 0;
	long long right = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> trees[i];
		right = trees[i] > right ? trees[i] : right;
	}
	long long result = 0;
	//mid 가 답
	while (left <= right){
		long long mid = (left + right) / 2;

		long long total = 0;
		for (int i = 0; i < trees.size(); i++)
		{
			if (trees[i] - mid > 0) total += trees[i] - mid;
		}

		//적어도 m을 가져가는거니깐.. m이상 되면 답이 될수 있다.
		if (total >= m)
		{
			result = result < mid ? mid : result;
			left = mid+1;
		}
		else if (total < m)
		{
			right = mid -1;
		}
	}

	cout << result << endl;

	 
	return 0;
}