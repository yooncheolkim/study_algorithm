#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct meeting {
	int s, e;
};

bool cmp(const meeting & l, const meeting & r)
{
	if (l.e != r.e) return l.e < r.e;
	return l.s < r.s;
}
vector <meeting> m;
int main()
{
	int N;
	cin >> N;
	int result = 0;
	meeting m_t;
	for (int i = 0; i < N; i++)
	{
		cin >> m_t.s >> m_t.e;
		m.push_back(m_t);
	}

	//»¡¸®³¡³ª´Â°Ô Àå¶¯,
	sort(m.begin(), m.end(), cmp);

	
	int finish_t = -1;
	for (int i = 0; i < m.size(); i++)
	{
		if (m[i].s >= finish_t)
		{
			finish_t = m[i].e;
			result++;
		}
	}

	cout << result << endl;

	return 0;
}