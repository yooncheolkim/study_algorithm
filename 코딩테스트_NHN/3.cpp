#include <iostream>
#include <string.h>
using namespace std;
int days;
int price[1001];
int mem[1001];
void go(int days, int coins) {
	if (mem[days] != -1) return mem[days];

}
int main()
{
	cin >> days;
	memset(mem, -1, sizeof(mem));
	for (int i = 1; i <= days; i++) {
		cin >> price[i];
	}
	go();
	return 0;
}