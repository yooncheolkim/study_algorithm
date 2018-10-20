#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;
int N;
int area[21][21];
bool ex_man[21];
int min_val = 999999999;
void check(vector<int> curr_A, bool curr_ex[21]) {
	vector<int> curr_B;
	for (int i = 1; i <= 20; i++) {
		if (curr_ex[i]) {
			curr_B.push_back(i);
		}
	}
	int A = 0;
	int B = 0;

	for (int i = 0; i < curr_A.size(); i++) {
		for (int j = i; j < curr_A.size(); j++) {
			if (j != i) {
				A += (area[curr_A[i]][curr_A[j]] + area[curr_A[j]][curr_A[i]]);
			}
		}
	}

	for (int i = 0; i < curr_B.size(); i++) {
		for (int j = i; j < curr_B.size(); j++) {
			if (j != i) {
				B += (area[curr_B[i]][curr_B[j]] + area[curr_B[j]][curr_B[i]]);
			}
		}
	}

	min_val = min_val < abs(A - B) ? min_val : abs(A - B);
}
void go(vector<int> curr_A, bool curr_ex[21], int idx) {
	
	if (curr_A.size() == N / 2) {
		check(curr_A, curr_ex);
	}
	
	if (curr_A.empty() && idx > N / 2) return;

	for (int i = idx; i < 21; i++) {
		if (curr_ex[i]) {
			curr_A.push_back(i);
			bool temp_ex[21];
			for (int j = 1; j < 21; j++) temp_ex[j] = curr_ex[j];
			temp_ex[i] = false;
			go(curr_A, temp_ex, i + 1);
			curr_A.pop_back();
		}
	}
}
int main(){
	cin >> N;
	memset(ex_man, false, sizeof(ex_man));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> area[i][j];
		}
		ex_man[i] = true;
	}
	vector<int> curr_A;
	go(curr_A,ex_man,1);

	cout << min_val << endl;
}