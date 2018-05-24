#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct rect {
	int x1, y1, x2, y2;
};
int N;
int result = 0;
vector<rect> rects;
bool ischeck[1001];
//겹치지 않을때를 찾는게 더 빠를것 같다.
bool isoverwrap(rect r1, rect r2)
{
	if (r1.x1 < r2.x1 && r1.y1 < r2.y1
		&& r2.x2 < r1.x2 && r2.y2 < r1.y2) return false;

	if (r1.x2 < r2.x1) return false;
	if (r1.y2 < r2.y1) return false;
	if (r2.x2 < r1.x1) return false;
	if (r2.y2 < r1.y1) return false;

	if (r2.x1 < r1.x1 && r2.y1 < r1.y1
		&& r1.x2 < r2.x2 && r1.y2 < r2.y2) return false;

	return true;
}
void dfs(rect r)
{
	for (int i = 0; i < rects.size(); i++)
	{
		if (!ischeck[i] && isoverwrap(r, rects[i]))
		{
			ischeck[i] = true;
			dfs(rects[i]);
		}
	}
}

int main()
{
	memset(ischeck, true, sizeof(ischeck));
	cin >> N;
	int x1, x2, y1, y2;
	bool starting_point = false;
	for (int i = 0; i < N; i++)
	{
		rect r;
		cin >> x1 >> y1 >> x2 >> y2;
		
		r.x1 = x1;
		r.y1 = y1;
		r.x2 = x2;
		r.y2 = y2;
		
		if (x1 == 0 && y1 <= 0 && 0 <= y2) starting_point = true;
		if (x2 == 0 && y1 <= 0 && 0 <= y2) starting_point = true;
		if (y1 == 0 && x1 <= 0 && 0 <= x2) starting_point = true;
		if (y2 == 0 && x1 <= 0 && 0 <= x2) starting_point = true;
		rects.push_back(r);
	}

	for (int i = 0; i < rects.size(); i++)
		ischeck[i] = false;

	for (int i = 0; i < rects.size(); i++)
	{
		if (!ischeck[i])
		{
			ischeck[i] = true;
			dfs(rects[i]);
			result++;
		}
	}

	if(starting_point)
		cout << --result << endl;
	else cout << result << endl;
	return 0;
}