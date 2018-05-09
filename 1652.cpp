#include <iostream>
#include <string>
using namespace std;

string room[101];
int N;
int garo()
{
	int result = 0;
	int num_con = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (room[i][j] == '.')
			{
				if (num_con == 1)
					result++;

				num_con++;
			}
			else if(room[i][j] == 'X')
			{
				num_con = 0;
			}
		}
		num_con = 0;
	}

	return result;
}

int sero() 
{
	int result = 0;
	int num_con = 0;
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (room[i][j] == '.')
			{
				if (num_con == 1)
					result++;

				num_con++;
			}
			else if (room[i][j] == 'X')
			{
				num_con = 0;
			}
		}
		num_con = 0;
	}

	return result;
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> room[i];

	cout << garo() << endl;
	cout << sero() << endl;
	return 0;
}