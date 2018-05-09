#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;
bool mem_R[11][11];
bool mem_B[11][11];
vector<string> in;

//���� ��� ���� ����
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
//���� ��ġ
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
	//ó�� b,r,o ��ġ
	for (int i = 0; i < in.size(); i++)
	{
		for (int j = 0; j < in[i].length(); j++)
		{
			if (in[i][j] == 'R') location.setR(i, j);
			if (in[i][j] == 'B') location.setB(i, j);
			if (in[i][j] == 'O') exit_y = i; exit_x = j;
		}
	}
	//ó�� ���ѵ�. in ���� R,B,O ���ֱ�
	in[location.Ry][location.Rx] = '.';
	in[location.By][location.Bx] = '.';
	in[exit_y][exit_x] = '.';

	queue<loc> q;
	q.push(location);
	mem_B[location.By][location.Bx] = true;
	mem_R[location.Ry][location.Rx] = true;

	//����̱�
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
		//����̴� ���� 4����
		for (int i = 0; i < 4; i++)
		{
			//�ǵ��ƿ��� ���� ����
			int re_Ry = temp.Ry;
			int re_Rx = temp.Rx;
			int re_By = temp.By;
			int re_Bx = temp.Bx;

			//�������� ������... ���߱�
			int more_not_act_Ry = -1;
			int more_not_act_Rx = -1;
			int more_not_act_By = -1;
			int more_not_act_Bx = -1;

			while (1)
			{
				//���� ������ ����. -> �������� ������.
				if (more_not_act_Ry == temp.Ry && more_not_act_Rx == temp.Rx && more_not_act_By == temp.By && more_not_act_Bx == temp.Bx)
					break;
				//������ �����̷��� �ߴµ�, #�̸� �����̸� �ȵǰ�, B�� B�� ���� �����δ�.
				if (in[temp.Ry + search_y[i]][temp.Rx + search_x[i]] == '#') {}
				else if (in[temp.Ry + search_y[i]][temp.Rx + search_x[i]] == 'B')
				{
					//B�����̴�.
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
				else //R�� ������  #�� �ƴϰ� B�� �ƴϸ� R�����̱�.
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
			//�ѹ������� ���ߴµ�, �̹� �ߴ��Ŵ�..q �� ���� ����
			if (mem_R[temp.Ry][temp.Rx] == true && mem_B[temp.By][temp.Bx] == true)
				continue;

			mem_R[temp.Ry][temp.Rx] == true;
			mem_B[temp.By][temp.Bx] == true;
			// �ѹ������� �� �ߴµ�, ������ ��ã�� -> BFS
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

	// # ��, R ���� ����,B �Ķ� ����, O ����
	//bfs ������ false
	cout << bfs() << endl;;


	return 0;
}