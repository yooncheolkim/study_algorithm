#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int mem[1501111];
int T[1501111], P[1501111];
int N;
// 이 상담을 선택할까 말까?
//선택 했을때 -> go(T[day]+day) + P[day]
//선택 안했을때 -> go(day+1)
int go(int day) {
	if (mem[day] != -1) return mem[day];
	if (day > N ) return 0;

	if(day + T[day] <= N +1)
		mem[day] = max(go(T[day] + day) + P[day], go(day + 1));
	else mem[day] = go(day + 1);

	return mem[day];
}
int main()
{
	cin >> N;
	memset(mem, -1, sizeof(mem));
	for (int i = 0; i < N; i++) {
		cin >> T[i+1] >> P[i+1];
	}

	cout << go(1) << endl;

	return 0;
}