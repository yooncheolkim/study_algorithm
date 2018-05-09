#include <iostream>
#include <string.h>
using namespace std;
int paper[3000][3000];
int N;
int result_negative = 0;
int result_zero = 0;
int result_positive = 0;

void search(int left_up_y, int left_up_x, int size)
{
	int start = paper[left_up_y][left_up_x];
	bool issame = true;
	
	for (int i = left_up_y; i < left_up_y+size; i++)
	{
		for (int j = left_up_x; j < left_up_x+size; j++)
		{
			if (paper[i][j] != start)
			{
				issame = false;
				break;
			}
		}
		if (!issame) break;
	}

	if (start == -1 && issame)
	{
		result_negative++;
		return;
	}
	if (start == 0 && issame)
	{
		result_zero++;
		return;
	}
	if (start == 1 && issame)
	{
		result_positive++;
		return;
	}

	if (!issame)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				search(left_up_y + (i*size / 3), left_up_x + (j*size / 3), size / 3);
		}
	}
}

int main()
{
	cin >> N;
	
	memset(paper, 2, sizeof(paper));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];
	}

	//¿ŞÂÊ À§, Å©±â

	search(0, 0, N);

	cout << result_negative << endl;
	cout << result_zero << endl;
	cout << result_positive << endl;
	return 0;
}