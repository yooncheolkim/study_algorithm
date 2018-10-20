#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> nums;
int op[4]; // 0 +, 1 -, 2 *, 3 /
int op_num = 0;
int min_val = 1000000001;
int max_val = -1000000001;
void calcul(vector<int> curr_op) {
	int culnum = nums[0];
	for (int i = 0; i < curr_op.size(); i++) {
		if (curr_op[i] == 0) culnum += nums[i + 1];
		if (curr_op[i] == 1) culnum -= nums[i + 1];
		if (curr_op[i] == 2) culnum *= nums[i + 1];
		if (curr_op[i] == 3) culnum /= nums[i + 1];
	}
	
	min_val = min_val < culnum ? min_val : culnum;
	max_val = max_val < culnum ? culnum : max_val;
}
void go(vector<int> curr_combi, int remain_op[4]) {
	if (curr_combi.size() == op_num) {
		//계산
		calcul(curr_combi);
	}

	//op 조합 구하기
	for (int i = 0; i < 4; i++) {
		if (remain_op[i] > 0) {
			curr_combi.push_back(i);
			int temp_op[4];
			for (int i = 0; i < 4; i++)
				temp_op[i] = remain_op[i];
			temp_op[i]--;
			go(curr_combi, temp_op);
			curr_combi.pop_back();
		}
	}
}
int main(){
	cin >> N;
	nums.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	int remain_op[4];
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
		op_num += op[i];
		remain_op[i] = op[i];
	}

	vector<int> combi;
	
	go(combi, remain_op);

	cout << max_val << endl;
	cout << min_val << endl;
	return 0;
}