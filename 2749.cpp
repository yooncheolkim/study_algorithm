#include <iostream>
using namespace std;

int  modi = 1000000;

struct matrix {
	long long a0, a1, a2, a3;

	matrix operator*(matrix &ref)
	{
		return matrix{ (a0*ref.a0 + a1*ref.a2)%modi , (a0*ref.a1 + a1*ref.a3) % modi, (a2*ref.a0 + a3*ref.a2)%modi, (a2*ref.a1 + a3*ref.a3)%modi };
	}
};

int fib(long long n)
{
	//ans matrix
	matrix ans{ 1,0,0,1 };
	matrix now{ 1,1,1,0 };

	//n--;

	//ans = ans * now;
	while (n > 0)
	{
		if (n % 2)
		{
			ans = ans * now;
		}
		n = n / 2;
		now = now * now;
	}
	

	return ans.a0 * 1 + ans.a1 * 0;
}

int main()
{
	long long n;

	cin >> n;

	if (n <= 1)
	{
		cout << n << endl;
		return 0;
	}
	else
	{
		 cout << fib(n-1);
	}

	return 0;
}