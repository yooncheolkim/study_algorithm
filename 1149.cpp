#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int house[1111][3] = { 0 };
int money[1111][3] = { 0 };

int Go(int N, int i);

int main() {
	int N, rs = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[i][j];
		}
	}

	rs = Go(N, 0);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << money[i][j] << " " ;
		cout << endl;
	}
	cout << rs;

	system("pause");

}

int Go(int N, int i) {
	if (N < 1) return 0;
	if (money[N][i] != 0) return money[N][i];

	money[N][0] = house[N][0] + min(Go(N - 1, 1), Go(N - 1, 2));// +min(Go(N + 1, 1), Go(N + 1, 2));

	money[N][1] = house[N][1] + min(Go(N - 1, 0), Go(N - 1, 2));// +min(Go(N + 1, 0), Go(N + 1, 2));

	money[N][2] = house[N][2] + min(Go(N - 1, 0), Go(N - 1, 1));// +min(Go(N + 1, 0), Go(N + 1, 1));

	return min({ money[N][0], money[N][1], money[N][2] });

}