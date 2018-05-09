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
//�Ѿ ���°� �� ������ �ִ�?
//������ �������� ������ �������� ����, �� �������� ������..
//����°�迭, a��° ������ �̿��ؼ� ������, true �ƴϸ� false
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


		//�پ� �ѱ�
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

		//�׳� ��ĭ �̵�
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