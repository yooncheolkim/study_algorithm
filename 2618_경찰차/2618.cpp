#include <iostream>
#include <vector>
using namespace std;
struct pos {
	int y, x;
};
struct cap {
	pos curr;
	vector<pos> handled;
	
};
int N, W;
int area[1001][1001];

int main()
{
	cin >> N >> W;
	vector<pos> crime;
	for (int i = 0; i < W; i++)
	{
		int y, x;
		cin >> y >> x;
		crime.push_back({ y,x });
	}
	return 0;
}