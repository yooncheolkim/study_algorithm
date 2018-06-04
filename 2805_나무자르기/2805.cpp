#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> trees(n);

	// �̺�Ž�� , mid�� �߶����� �����Ѱ�?
	long long left = 0;
	long long right = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> trees[i];
		right = trees[i] > right ? trees[i] : right;
	}
	long long result = 0;
	//mid �� ��
	while (left <= right){
		long long mid = (left + right) / 2;

		long long total = 0;
		for (int i = 0; i < trees.size(); i++)
		{
			if (trees[i] - mid > 0) total += trees[i] - mid;
		}

		//��� m�� �������°Ŵϱ�.. m�̻� �Ǹ� ���� �ɼ� �ִ�.
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