#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sh[9];
bool flag = false;
//idx는 지금 고려해야 할거, cnt는 현재 몇개 추가되었는지
void combi(vector<int> a, int n,int r, int idx, int cnt)
{
	if (cnt >= r)
	{
		int result = 0;
		for (int i = 0; i < a.size(); i++)
			result += a[i];

		if (result == 100)
		{
			sort(a.begin(), a.end());
			for (int i = 0; i < a.size(); i++)
				cout << a[i] << endl;
			flag = true;
		}
		return;
	}

	if (n > idx && r >cnt)
	{
		a.push_back(sh[idx]);
		combi(a, n, r, idx +1, cnt + 1);
		if (flag) return;
		a.erase(a.begin()+a.size()-1);
		combi(a, n, r, idx + 1, cnt);
	}
}
int main()
{
	for (int i = 0; i < 9 ; i++) 
		cin >> sh[i];
	
	vector<int> a;
	combi(a,9,7,0,0);

	return 0;
}