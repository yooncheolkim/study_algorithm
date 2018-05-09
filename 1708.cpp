#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
//포인트를 기준으로 각도를 만들어서, 정렬을 한다.
//기준을 만족했을때 break 해서 나가기..
//아니면, pop해서 나가기..
using namespace std;

struct point {
	int y, x;
};
vector<point> p;
stack<point> s;
bool cmp1(const point &p1, const point &p2)
{
	if (p1.y != p2.y)
		return p1.y < p2.y;
	return p1.x < p2.x;
}
bool cmp(const point &p1, const point &p2)
{
	double distance1 = sqrt(pow(p1.x - p[0].x, 2) + pow(p1.y - p[0].y, 2));
	double distance2 = sqrt(pow(p2.x - p[0].x, 2) + pow(p2.y - p[0].y, 2));

	return distance1 / abs(p1.x - p[0].x) < distance2 / abs(p2.x - p[0].x);
}
double ccw(point p1 ,point p2,point p3)
{
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int y, x;
		cin >> x >> y;
		p.push_back({ y,x });
	}

	//그래프 상에서 가장 밑에 있는 점을 기준으로 정렬

	//y가 가장 작고, x가 가장 작은 점 찾기.
	sort(p.begin(), p.end(),cmp1);

	//그 외의 점을 p[0]과의 각도를 기준으로 정렬
	sort(p.begin() + 1, p.end(), cmp);
	
	s.push(p[0]);
	s.push(p[1]);

	int idx = 2;

	while (idx < N)
	{
		while (s.size() >= 2)
		{
			point p2, p1;
			p2 = s.top();
			s.pop();
			p1 = s.top();

			// 외적의 값이 음수면, 오른쪽
			// 외적의 값이 양수, 왼쪽
			if (ccw(p1, p2, p[idx]) > 0){
				s.push(p2);
				break;
			}
			//0이면 제거?
		}
		s.push(p[idx]);
		idx++;
	}

	cout << s.size() << endl;

	return 0;
}