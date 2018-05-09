#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct monki {
	int y, x;
	int k;
	int cnt;
};

int area[201][201];
//넘어서 가는게 더 빠를수 있다?
//점프로 가기전에 원숭이 걸음으로 가면, 더 느릴수도 있으니..
//세번째배열, a번째 쩜프를 이용해서 갔으면, true 아니면 false
bool visited[201][201][31];
int W, H;
int K;
queue<monki> work;

int bfs()
{
	int jump_y[8] = { 2,2,-1,-1,-2,-2,1,1 };
	int jump_x[8] = { 1,-1,2,-2,1,-1,2,-2 };
	int move_y[] = { 1,-1,0,0 };
	int move_x[] = { 0,0,1,-1 };
	while (!work.empty())
	{
		monki temp = work.front();
		work.pop();

		if (temp.y == H - 1 && temp.x == W - 1)
		{
			return temp.cnt;
		}


		//뛰어 넘기
		if (temp.k > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int dy = temp.y + jump_y[i];
				int dx = temp.x + jump_x[i];

				if (dy >= 0 && dy < H && dx >= 0 && dx < W
					&& !visited[dy][dx][temp.k-1] && area[dy][dx] == 0)
				{
					visited[dy][dx][temp.k-1] = true;
					work.push({ dy,dx,temp.k-1,temp.cnt + 1 });
				}
			}
		}

		//그냥 한칸 이동
		for (int i = 0; i < 4; i++)
		{
			int dy = temp.y + move_y[i];
			int dx = temp.x + move_x[i];

			if (dy >= 0 && dy < H && dx >= 0 && dx < W
				&& !visited[dy][dx][temp.k] && area[dy][dx] == 0)
			{
				visited[dy][dx][temp.k] = true;
				work.push({ dy,dx,temp.k,temp.cnt + 1 });
			}
		}
	}

	return -1;
}
int main()
{
	cin >> K;

	cin >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> area[i][j];
		}
	}
	work.push({ 0,0 ,K,0});
	cout << bfs() << endl;


	return 0;
}