#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
/*
struct yx {
	int y, x;
};
*/
struct pos {
	int y, x;
	int cnt = 0;
	int dirty = 0;
	int clear_bits = 0;
	//vector<yx> route;
	string area[21];
};

//비트..
bool visited[21][21][1100];
int w, h;
int answer = 0;
//더러운 장소를 저장
vector<pos> dirty_place;

int bfs(queue<pos> work)
{
	int d_y[4] = { 0,0,-1,1 };
	int d_x[4] = { 1,-1,0,0 };
	bool flag = false;
	while (!work.empty())
	{
		pos curr = work.front();
		work.pop();
		if (curr.area[curr.y][curr.x] == '*')
		{
			curr.dirty--;
			curr.area[curr.y][curr.x] = '.';
			for (int j = 0; j < dirty_place.size(); j++)
			{
				if (dirty_place[j].y == curr.y && dirty_place[j].x == curr.x)
				{
					curr.clear_bits |= 1 << j;
				}
			}
		}

		if(curr.dirty == 0)
		{
			flag = true;
			return curr.cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			int dy = curr.y + d_y[i];
			int dx = curr.x + d_x[i];

			if (!visited[dy][dx][curr.clear_bits]  && 0 <= dy && dy < h
				&& 0 <= dx && dx < w && curr.area[dy][dx] != 'x')
			{
				visited[dy][dx][curr.clear_bits] = true;
				pos temp;
				temp.clear_bits = curr.clear_bits;
				temp.y = dy; temp.x = dx; temp.dirty = curr.dirty;
				temp.cnt = curr.cnt+1;
				//temp.route = curr.route;
				//temp.route.push_back({ dy,dx });
				for (int y = 0; y < h; y++)
				{
					temp.area[y] = curr.area[y];
				}
				work.push(temp);
			}
		}
	}

	if (!flag) return -1;
}
int main()
{
	while(true)
	{
		queue<pos> work;
		pos start;
		memset(visited, false, sizeof(visited));
		dirty_place.clear();
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++)
		{
			cin >> start.area[i];
		}
		
		//시작 위치 구하기
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (start.area[i][j] == 'o')
				{
					start.y = i;
					start.x = j;
				}
				if (start.area[i][j] == '*')
				{
					pos temp;
					temp.y = i;
					temp.x = j;
					dirty_place.push_back(temp);
					start.dirty++;
				}
			}
		}
		start.cnt = 0;
		visited[start.y][start.x][start.dirty] = true;
		//start.route.push_back({ start.y,start.x });
		work.push(start);
		cout << bfs(work) << endl;
	}

	return 0;
}