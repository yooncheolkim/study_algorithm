//왜 안되는지 모르겟다..
//왓더..

#include <iostream>
#include <string.h>
#include <string>
#include <queue>
using namespace std;

//0~3 가로, 4~7 세로
int move_y[8] = { 0,0,-1,1,2,-2,0,0 };
int move_x[8] = { 2,-2,0,0,0,0,1,-1 };
int N;
string map[51];
bool visited[51][51][3]; // 0이면 방문 x, 1이면 가로, 2이면 세로
struct tong
{
	int y, x; // 통나무 가운데 좌표 저장
	bool isgaro; // true면 가로 false 면 세로.
	int cnt;

	bool canRot()
	{
		int move[3] = { -1,0,1 };
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (y + move[i] < 0 || y + move[i] >= N || x + move[j] < 0 || x + move[i] >= N
					|| map[y + move[i]][x + move[j]] == '1')
					return false;
			}
		}
		return true;
	}

	bool canUp()
	{
		if (isgaro)
		{
			int dy = y - 1;
			int dx_1 = x - 1;
			int dx_2 = x;
			int dx_3 = x + 1;
			if (dy >= 0 && dy < N && dx_1 >= 0 && dx_1 < N && dx_2 >= 0 && dx_2 < N && dx_3 < N && dx_3 >= 0
				&& map[dy][dx_1] != '1' && map[dy][dx_2] != '1' && map[dy][dx_3] != '1')
				return true;
		}
		else
		{
			int dy = y - 2;
			int dx = x;
			if (dy >= 0 && dy < N && dx >= 0 && dx < N
				&& map[dy][dx] != '1')
				return true;
		}
		return false;
	}

	bool canDown()
	{
		if (isgaro)
		{
			int dy = y + 1;
			int dx_1 = x - 1;
			int dx_2 = x;
			int dx_3 = x + 1;
			if (dy >= 0 && dy < N && dx_1 >= 0 && dx_1 < N && dx_2 >= 0 && dx_2 < N && dx_3 < N && dx_3 >= 0
				&& map[dy][dx_1] != '1' && map[dy][dx_2] != '1' && map[dy][dx_3] != '1')
				return true;
		}
		else
		{
			int dy = y + 2;
			int dx = x;
			if (dy >= 0 && dy < N && dx >= 0 && dx < N
				&& map[dy][dx] != '1')
				return true;
		}
		return false;
	}

	bool canLeft()
	{
		if (isgaro)
		{
			int dy = y;
			int dx = x - 2;

			if (dy >= 0 && dy < N && dx >= 0 && dx < N
				&& map[dy][dx] != '1')
				return true;
		}
		else
		{
			int dy_1 = y - 1;
			int dy_2 = y;
			int dy_3 = y + 1;
			int dx = x - 1;
			if (dx >= 0 && dx < N && dy_1 >= 0 && dy_1 < N && dy_2 >= 0 && dy_2 < N && dy_3 < N && dy_3 >= 0
				&& map[dy_1][dx] != '1' && map[dy_2][dx] != '1' && map[dy_3][dx] != '1')
				return true;
		}
		return false;
	}
	bool canRight()
	{
		if (isgaro)
		{
			int dy = y;
			int dx = x + 2;

			if (dy >= 0 && dy < N && dx >= 0 && dx < N
				&& map[dy][dx] != '1')
				return true;
		}
		else
		{
			int dy_1 = y - 1;
			int dy_2 = y;
			int dy_3 = y + 1;
			int dx = x + 1;
			if (dx >= 0 && dx < N && dy_1 >= 0 && dy_1 < N && dy_2 >= 0 && dy_2 < N && dy_3 < N && dy_3 >= 0
				&& map[dy_1][dx] != '1' && map[dy_2][dx] != '1' && map[dy_3][dx] != '1')
				return true;
		}
		return false;
	}
};

//시작 tong
tong s_tong;
//끝 tong
tong e_tong;
queue<tong> work;
int bfs()
{
	while (!work.empty())
	{
		tong temp = work.front();
		work.pop();

		if (temp.y == e_tong.y && temp.x == e_tong.x && temp.isgaro == e_tong.isgaro)
			return temp.cnt;

		//가로일때
		if (temp.isgaro)
		{
			for (int i = 0; i < 4; i++)
			{
				int dy = temp.y + move_y[i];
				int dx = temp.x + move_x[i];

				if (i == 0 && !temp.canRight())
					continue;
				if (i == 1 && !temp.canLeft())
					continue;
				if (i == 2 && !temp.canUp())
					continue;
				if (i == 3 && !temp.canDown())
					continue;
				
				if (!visited[dy][temp.x + move_x[i] / 2][1])
				{
					visited[temp.y + move_y[i]][temp.x + move_x[i] / 2][1] = true;
					work.push({ temp.y + move_y[i] ,temp.x + move_x[i] / 2 ,temp.isgaro,temp.cnt + 1 });
				}
			}
		}
		//세로일때
		else
		{
			for (int i = 4; i < 8; i++)
			{
				int dy = temp.y + move_y[i];
				int dx = temp.x + move_x[i];

				if (i == 4 && !temp.canDown())
					continue;
				if (i == 5 && !temp.canUp())
					continue;
				if (i == 6 && !temp.canRight())
					continue;
				if (i == 7 && !temp.canLeft())
					continue;

				if (!visited[temp.y + move_y[i] / 2][dx][2])
				{
					visited[temp.y + move_y[i] / 2][temp.x + move_x[i]][2] = true;
					work.push({ temp.y + move_y[i] / 2 ,temp.x + move_x[i],temp.isgaro,temp.cnt + 1 });
				}
			}
		}
		//회전
		if (temp.canRot())
		{
			if (temp.isgaro)
			{
				if (!visited[temp.y][temp.x][2])
				{
					visited[temp.y][temp.x][2] = true;
					work.push({ temp.y,temp.x,!temp.isgaro,temp.cnt + 1 });
				}
			}
			else
			{
				if (!visited[temp.y][temp.x][1])
				{
					visited[temp.y][temp.x][1] = true;
					work.push({ temp.y,temp.x,!temp.isgaro,temp.cnt + 1 });
				}
			}
		}
	}
	return 0;
}

int main()
{
	cin >> N;
	memset(visited, false, sizeof(visited));
	
	int s = 0;
	int e = 0;

	for (int i = 0; i < N; i++)
		cin >> map[i];


	int temp_B = 0;
	int temp_E = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'B')
			{
				if (s == 0)
					temp_B = j;
				if (s == 1)
				{
					s_tong.y = i;
					s_tong.x = j;
					s_tong.cnt = 0;
					if (j == temp_B + 1)
						s_tong.isgaro = true;
					else
						s_tong.isgaro = false;
				}
				s++;
			}
			if (map[i][j] == 'E')
			{
				if (e == 0)
					temp_E = j;
				if (e == 1)
				{
					e_tong.y = i;
					e_tong.x = j;
					if (j == temp_E + 1)
						e_tong.isgaro = true;
					else
						e_tong.isgaro = false;
				}
				e++;
			}
		}
	}

	work.push(s_tong);

	if (s_tong.isgaro)
		visited[s_tong.y][s_tong.x][1] = true;
	else
		visited[s_tong.y][s_tong.x][2] = true;

	cout << bfs() << endl;

	return 0;
}