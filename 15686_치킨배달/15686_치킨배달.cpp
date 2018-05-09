//1억 번이면,, 대략 1초.. 
//13C6 10
// 10^5 nlogn
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct pos {
	int y, x;
};
int N, M;
int map[51][51];
vector<pos> chicken;
vector<pos> home;
vector<int> chickset;
int result = 999999999;
void pick(int n, vector<int> st, int r)
{
	if (r == 0)
	{
		int sum_result = 0;
		for (int i = 0; i < home.size() ;i++)
		{
			int home_min = 999999999;
			for (int j = 0; j < st.size(); j++)
			{
				int temp =  abs(home[i].y - chicken[st[j]].y) + abs(home[i].x - chicken[st[j]].x);
				home_min = home_min < temp ? home_min : temp;
			}
			sum_result += home_min;
		}
		result = result < sum_result ? result : sum_result;
	}

	int smallest = st.empty() ? 0 : st.size();

	for (int next = smallest; next < n; next++)
	{
		st.push_back(next);
		pick(n, st, r - 1);
		st.erase(st.begin()+st.size()-1);
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) home.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	//chicken.size() 에서 M개 뽑기. 그래서 최소 값 찾기
	pick(chicken.size(), chickset, M);

	cout << result << endl;
	
	return 0;
}
