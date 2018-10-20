/*#include <iostream>
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
*/

#include <iostream>
#include <string.h>
using namespace std;
int T;
int n;
int student[100001];
int selected_student[100001];
bool visited[100001];
int ans;
void sort_topo(int num) {
	if (selected_student[num] != 0 || visited[num]) return;

	ans++;
	visited[num] = true;
	selected_student[student[num]]--;
	sort_topo(student[num]);
}
int main() {
	cin >> T;
	while (T--) {
		memset(student, -1, sizeof(student));
		memset(visited, false, sizeof(visited));
		memset(selected_student, 0, sizeof(selected_student));
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
			selected_student[student[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			sort_topo(i);
		}
		cout << ans << endl;
	}
	return 0;
}