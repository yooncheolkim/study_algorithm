#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct pos {
	int y, x;
};
struct Dragon {
	//점들을 가지고 있음..
	vector<pos> p;
	int ger;
	//현재 점들을 끝점 기준으로 회전
	void rotate()
	{
		pos base_p = p[p.size() - 1];

		for (int i = p.size() - 2; i >= 0; i--)
		{
			p.push_back({p[i].x-base_p.x + base_p.y , -(p[i].y - base_p.y) + base_p.x});
		}
	}
};
int N;
int area[102][102];
int main()
{
	memset(area, 0, sizeof(area));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int y, x ,dir, ger;
		cin >> x >> y >> dir >> ger;
		Dragon d;
		d.ger = ger;
		d.p.push_back({ y,x });

		//처음꺼 넣어놓기.
		if (dir == 0)
			d.p.push_back({ y,x + 1 });
		if(dir == 1)
			d.p.push_back({ y - 1,x });
		if (dir == 2)
			d.p.push_back({ y,x -1});
		if (dir == 3)
			d.p.push_back({ y + 1,x });


		for (int j = 0; j < d.ger; j++)
			d.rotate();
		for (int j = 0; j < d.p.size(); j++)
			area[d.p[j].y][d.p[j].x] = 1;
	}

	int result = 0;
	bool flag = false;
	int dy[] = { 0,1,1,0 };
	int dx[] = { 0,1,0,1 };
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (area[i + dy[k]][j + dx[k]] == 0)
				{
					flag = true;
					break;
				}
			}
			if(flag == false)
				result++;
			flag = false;
		}	
	}

	cout << result << endl;
	return 0;
}