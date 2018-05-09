#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int M, N;
int map[101][101];
int visited[101][101];
//0이면 방문 x, 4비트로 표현, 각 비트가 방향을 나타냄.
//1 동쪽, 2 서쪽, 3 남쪽, 4 북쪽
//1 동쪽, 10 남쪽, 100 서쪽, 1000 북쪽
struct robot {
	int y, x;
	int dir;
	int cnt = 0;

	void turnR()
	{
		dir = dir << 1;
		if (dir >= 16) dir = 1;
	}

	void turnL()
	{
		if (dir == 1)
		{
			dir = 1 << 3;
			return;
		}
		dir = dir >> 1;
	}

	bool goK(int k)
	{
		if (dir == 1)
		{
			if (x + k >= N) return false;
			return true;
		}
		else if (dir == (1 << 1))
		{
			if (y + k >= M) return false;
			return true;
		}
		else if (dir == (1 << 2))
		{
			if (x - k < 0) return false;
			return true;
		}
		else if (dir == (1 << 3))
		{
			if (y - k < 0) return false;
			return true;
		}
	}
};
queue<robot> work;
robot s;
robot e;
int bfs()
{
	while (!work.empty())
	{
		robot temp = work.front();
		work.pop();

		if (temp.y == e.y && temp.x == e.x && temp.dir == e.dir)
		{
			return temp.cnt;
		}
		int move_y = 0;
		int move_x = 0;
		if (temp.dir == 1) move_x = 1;
		if (temp.dir == (1 << 1)) move_y = 1;
		if (temp.dir == (1 << 2)) move_x = -1;
		if (temp.dir == (1 << 3)) move_y = -1;

		//앞으로 이동
		for (int i = 1; i <= 3; i++)
		{
			if (temp.goK(i))
			{
				if (map[temp.y + move_y*i][temp.x + move_x*i] == 0)
				{
					if ((visited[temp.y + move_y*i][temp.x + move_x*i] & temp.dir) == 0)
					{
					visited[temp.y + move_y*i][temp.x + move_x*i] |= temp.dir;
					robot p_temp;
					p_temp.y = temp.y + move_y*i;
					p_temp.x = temp.x + move_x*i;
					p_temp.dir = temp.dir;
					p_temp.cnt = temp.cnt + 1;
					work.push(p_temp);
					}
				}
				else break;
			}
			else break;
		}

		//회전
		//왼쪽
		temp.turnL();
		if ((visited[temp.y][temp.x] & temp.dir) == 0)
		{
			visited[temp.y][temp.x] |= temp.dir;
			temp.cnt++;
			work.push(temp);
		}
		temp.turnR();
		temp.cnt--;
		//오른쪽
		temp.turnR();
		if ((visited[temp.y][temp.x] & temp.dir) == 0)
		{
			visited[temp.y][temp.x] |= temp.dir;
			temp.cnt++;
			work.push(temp);
		}
	}
}
int main()
{
	cin >> M >> N;
	memset(visited, 0, sizeof(visited));
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	int temp;
	cin >> s.y >> s.x >> temp;
	s.y--;
	s.x--;
	if (temp == 1) s.dir = 1;
	if (temp == 3) s.dir = 1 << 1;
	if (temp == 2) s.dir = 1 << 2;
	if (temp == 4) s.dir = 1 << 3;
	cin >> e.y >> e.x >> temp;
	e.y--;
	e.x--;
	if (temp == 1) e.dir = 1;
	if (temp == 3) e.dir = 1 << 1;
	if (temp == 2) e.dir = 1 << 2;
	if (temp == 4) e.dir = 1 << 3;

	work.push(s);
	visited[s.y][s.x] = s.dir;
	
	cout << bfs() << endl;

	return 0;
}