//Çà·Ä °ö¼À ¼ø¼­
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int mem[501][501];
struct rc {
	int r;
	int c;
};
vector<rc> input;

int dp(int front, int rear)
{
	if (mem[front][rear] != -1)
		return mem[front][rear];
	else
	{
		if (front == rear)
		{
			mem[front][rear] = 0;
			return mem[front][rear];
		}
		if (front + 1 == rear)
		{
			mem[front][rear] = input[front-1].r * input[front-1].c * input[rear-1].c;
			return mem[front][rear];
		}
		for (int i = front ; i <= input.size(); i++)
		{
			int temp = dp(front, i) + dp(i + 1, rear) + input[front-1].r * input[front-1].c * input[rear-1].c;
			
			if (mem[front][rear] == -1)
				mem[front][rear] = temp;
			else
			{
				if (mem[front][rear] > temp)
					mem[front][rear] = temp;
			}	
		}
		return mem[front][rear];
	}
}
int main()
{
	memset(mem, -1, sizeof(mem));
	int n;
	cin >> n;
	int r, c;
	for (int i = 0; i < n; i++)
	{
		cin >> r >> c;
		rc temp;
		temp.r = r;
		temp.c = c;
		input.push_back(temp);
	}
	
	dp(1, input.size());

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << mem[i][j] << " ";
		}
		cout << endl;
	}

	cout << mem[1][n] << endl;

	return 0;
}