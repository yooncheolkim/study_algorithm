#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;
bool mem_R[11][11];
bool mem_B[11][11];
vector<string> in;

//레드 블루 같이 관리
struct loc
{
	int Ry;
	int Rx;
	int By;
	int Bx;
	int cnt = 0;
	void setR(int a, int b)
	{
		this->Ry = a;
		this->Rx = b;
	}
	void setB(int a, int b)
	{
		this->By = a;
		this->Bx = b;
	}
};

loc location;
//구멍 위치
int exit_y;
int exit_x;

bool ishole(int y, int x)
{
	if (y == exit_y && x == exit_x)
		return true;
	return false;
}

int bfs()
{
	//처음 b,r,o 위치
	for (int i = 0; i < in.size(); i++)
	{
		for (int j = 0; j < in[i].length(); j++)
		{
			if (in[i][j] == 'R') location.setR(i, j);
			if (in[i][j] == 'B') location.setB(i, j);
			if (in[i][j] == 'O') exit_y = i; exit_x = j;
		}
	}
	//처음 정한뒤. in 에서 R,B,O 없애기
	in[location.Ry][location.Rx] = '.';
	in[location.By][location.Bx] = '.';
	in[exit_y][exit_x] = '.';

	queue<loc> q;
	q.push(location);
	mem_B[location.By][location.Bx] = true;
	mem_R[location.Ry][location.Rx] = true;

	//기울이기
	int search_y[4] = { 0,0,-1,1 };
	int search_x[4] = { -1,1,0,0 };
	while (1)
	{
		loc temp = q.front();
		q.pop();
		cout << temp.cnt << endl;
		temp.cnt++;

		if (temp.cnt > 10)
			return -1;
		//기울이는 방향 4가지
		for (int i = 0; i < 4; i++)
		{
			//되돌아오기 위한 변수
			int re_Ry = temp.Ry;
			int re_Rx = temp.Rx;
			int re_By = temp.By;
			int re_Bx = temp.Bx;

			//움직임이 없을때... 멈추기
			int more_not_act_Ry = -1;
			int more_not_act_Rx = -1;
			int more_not_act_By = -1;
			int more_not_act_Bx = -1;

			while (1)
			{
				//이전 루프랑 같다. -> 움직임이 없었다.
				if (more_not_act_Ry == temp.Ry && more_not_act_Rx == temp.Rx && more_not_act_By == temp.By && more_not_act_Bx == temp.Bx)
					break;
				//빨간볼 움직이려고 했는데, #이면 움직이면 안되고, B면 B볼 부터 움직인다.
				if (in[temp.Ry + search_y[i]][temp.Rx + search_x[i]] == '#') {}
				else if (in[temp.Ry + search_y[i]][temp.Rx + search_x[i]] == 'B')
				{
					//B움직이다.
					if (in[temp.By + search_y[i]][temp.Bx + search_x[i]] == '#'
						&& 0 <= temp.By + search_y[i] && temp.By + search_y[i] < in.size()
						&& 0 <= temp.Bx + search_x[i] && temp.Bx + search_x[i] < in[0].size()) {
					}
					else
					{
						while (in[temp.By + search_y[i]][temp.Bx + search_x[i]] != '#'
							&& 0 <= temp.By + search_y[i] && temp.By + search_y[i] < in.size()
							&& 0 <= temp.Bx + search_x[i] && temp.Bx + search_x[i] < in[0].size())
						{
							temp.By += search_y[i];
							temp.Bx += search_x[i];
							if (ishole(temp.By, temp.Bx) == true)
							{
								temp.setR(re_Ry, re_Rx);
								temp.setB(re_By, re_Bx);
								break;
							}
						}
					}
				}
				else //R의 다음이  #도 아니고 B도 아니면 R움직이기.
				{
					if (in[temp.Ry + search_y[i]][temp.Rx + search_x[i]] == '#'
						&& 0 <= temp.Ry + search_y[i] && temp.Ry + search_y[i] < in.size()
						&& 0 <= temp.Rx + search_x[i] && temp.Rx + search_x[i] < in[0].size()) {
					}
					else
					{
						while (in[temp.Ry + search_y[i]][temp.Rx + search_x[i]] != '#'
							&& 0 <= temp.Ry + search_y[i] && temp.Ry + search_y[i] < in.size()
							&& 0 <= temp.Rx + search_x[i] && temp.Rx + search_x[i] < in[0].size())
						{
							temp.Ry += search_y[i];
							temp.Rx += search_x[i];
							if (ishole(temp.Ry, temp.Ry) == true) return temp.cnt;
						}
					}
				}

				more_not_act_Ry = temp.Ry;
				more_not_act_Rx = temp.Rx;
				more_not_act_By = temp.By;
				more_not_act_Bx = temp.Bx;
			}
			//한방향으로 다했는데, 이미 했던거다..q 에 넣지 않음
			if (mem_R[temp.Ry][temp.Rx] == true && mem_B[temp.By][temp.Bx] == true)
				continue;

			mem_R[temp.Ry][temp.Rx] == true;
			mem_B[temp.By][temp.Bx] == true;
			// 한방향으로 다 했는데, 구멍을 못찾음 -> BFS
			q.push(temp);
		}
	}
}


int main()
{
	int n, m;
	string temp;
	cin >> n >>  m;

	memset(mem_R, false, sizeof(mem_R));
	memset(mem_B, false, sizeof(mem_B));

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		in.push_back(temp);
	}

	// # 벽, R 빨간 구슬,B 파란 구슬, O 구멍
	//bfs 간곳은 false
	cout << bfs() << endl;;


	return 0;
}