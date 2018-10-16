#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <deque>
using namespace std;
int C;
int P;
int N[501];
deque<int> deck;

//Ω√¿€ ¿Œµ¶Ω∫, ≥° ¿Œµ¶Ω∫, cnt
void go(int start_idx, int end_idx, int cnt) {
	deque<int> temp;
	//¡ﬂ∞£≤® ≥÷±‚
	for (int i = start_idx; i <= end_idx; i++) {
		temp.push_back(deck[i]);
	}
	//ª©∞Ì
	deck.erase(deck.begin() + start_idx, deck.begin() + end_idx +1);
	
	//¿ßø° Ω◊±‚
	while(!temp.empty()){
		int temp_card = temp.back();
		temp.pop_back();
		deck.push_front(temp_card);
	}

	if (end_idx - start_idx + 1 > 2 * N[cnt]) {
		go(N[cnt], end_idx - start_idx - N[cnt], cnt);
	}
	else {
		cnt++;
		if (cnt == P) return;
		go(N[cnt], deck.size() - 1 - N[cnt], cnt);
	}
}
int main()
{
	cin >> C >> P;

	for (int i = 0; i < P; i++) {
		cin >> N[i];
	}

	for (int i = 1; i <= C; i++) {
		deck.push_back(i);
	}
	
	go(N[0], deck.size() - 1 - N[0], 0);

	for (int i = 0; i < 5; i++) {
		cout << deck[i] << endl;
	}
	return 0;
}