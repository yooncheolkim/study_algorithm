#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int T;
	bool check[100001];
	int want[100001];
	int finish[100001];
	cin >> T;

	while (T--) {
		int ans = 0;
		int n;
		cin >> n;
		memset(check, false,sizeof(check));
		memset(finish, 0, sizeof(finish));
		for (int i = 1; i <= n; i++) {
			cin >> want[i];
			finish[want[i]]++;
		}

		for (int i = 1; i <= n; i++) {
			int now = i;
			while (!check[now] && !finish[now]) {
				ans++;
				check[now] = true;
				finish[want[now]]--;
				now = want[now];
			}
		}
		cout << ans << endl;
	}
	return 0;
}