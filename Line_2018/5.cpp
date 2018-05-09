#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct pj {
	int m, d, i;
};
vector<pj> arba;
int N;
int mem[501][301];

//mem[n][k]는 arba[n]을 포함했을때, k기간에서의 최대 보수
//mem[n][k] = max(go(n, arba[n].m) + arba[n].i, go(n - 1, k));
int go(int n, int k)
{
	if (mem[n][k] != -1) return mem[n][k];

	if (arba[n].d > k) return mem[n][k] = go(n - 1,k);
	
	if (arba[n].d < k) return mem[n][k] = go(n,k-1);

	return mem[n][k] = max(go(n, arba[n].m) + arba[n].i, go(n - 1, k));
}
int main()
{
	cin >> N;
	memset(mem, -1, sizeof(mem));
	for (int i = 0; i < N; i++)
	{
		pj temp;
		cin >> temp.m >> temp.d >> temp.i;
		temp.d += temp.m;
		arba.push_back(temp);
	}

	//mem[0][i] 초기화.
	for (int i = 0; i < 301; i++)
	{
		if (arba[0].d > i)
			mem[0][i] = 0;
		else mem[0][i] = arba[0].i;
	}


	cout << go(N - 1, arba[arba.size() - 1].d) << endl;
	

	//추적
	vector<pj> selected_work;
	int i = N - 1;
	int j = arba[i-1].d;

	while (i >= 0 && j >= 0)
	{
		//i-1번째 알바를 선택하였다.
		if (go(i - 1, j) == go(i, j - 1))
		{
			selected_work.push_back({ arba[i].m,arba[i].d,0 });
		}
		i--;
		j = arba[i]
		

		
	}
	return 0;
}