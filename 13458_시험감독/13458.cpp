#include <iostream>
#include <vector>

using namespace std;
int N, B, C;
vector<int> students;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		students.push_back(temp);
	}
	cin >> B >> C;

	long long result = 0;
	for (int i = 0; i < students.size(); i++){
		int temp = students[i] - B; 
		result++;
		if (temp <= 0)
			continue;

		result += temp % C == 0 ? temp / C : temp / C + 1;
	}

	cout << result << endl;
	return 0;
}