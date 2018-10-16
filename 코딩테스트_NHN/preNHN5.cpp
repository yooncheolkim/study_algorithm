#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
	char sex;//1
	int age;//2
	string spec;//3
};

vector <Person> person;
int N;
int condi1, condi2, condi3;

//우선순위, 1 a가 큰거, 0 같은거, -1 b가 큰거
int cmp_sex(Person a, Person b){
	if (a.sex < b.sex) return 1;
	if (a.sex == b.sex) return 0;
	if (a.sex > b.sex) return -1;
}

int cmp_age(Person a, Person b) {
	if (a.age == b.age) return 0;

	if (a.age <= 7 || b.age <= 7) {
		if (a.age < b.age) return 1;
		if (a.age > b.age) return -1;
	}
	
	if (a.age < b.age) return -1;
	return 1;
}

int cmp_spec(Person a, Person b) {
	if (a.spec.empty() && b.spec.empty()) return 0;
	if (a.spec.empty()) return -1;
	if (b.spec.empty()) return 1;

	if (a.spec.compare(b.spec) == 0) return 0;
	else {
		if (a.spec.compare("PW") == 0 && b.spec.compare("PW") != 0) return 1;
		if (a.spec.compare("PW") != 0 && b.spec.compare("PW") == 0) return -1;

		if (a.spec.compare("DP") == 0 && b.spec.compare("DP") != 0) return 1;
		if (a.spec.compare("DP") != 0 && b.spec.compare("DP") == 0) return -1;
	}
}

bool cmp(const Person &a, const Person &b) {

	if (condi1 == 1) {
		int i = cmp_sex(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}
	if (condi1 == 2) {
		int i = cmp_age(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}
	if (condi1 == 3) {
		int i = cmp_spec(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}


	if (condi2 == 1) {
		int i = cmp_sex(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}
	if (condi2 == 2) {
		int i = cmp_age(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}
	if (condi2 == 3) {
		int i = cmp_spec(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}



	if (condi3 == 1) {
		int i = cmp_sex(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}
	if (condi3 == 2) {
		int i = cmp_age(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}
	if (condi3 == 3) {
		int i = cmp_spec(a, b);
		if (i > 0) return true;
		if (i < 0) return false;
	}
	return true;
}

int main()
{
	
	cin >> condi1 >> condi2 >> condi3;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char sex;
		int age;
		string spec;
		cin >> sex >> age;
		int a = cin.get();
		if (a == '\n') {
			person.push_back({ sex,age,spec });
			continue;
		}
		else {
			cin >> spec;
			person.push_back({ sex,age,spec });
		}
	}

	sort(person.begin(), person.end(), cmp);

	for (int i = 0; i < person.size(); i++) {
		cout << person[i].sex << " " << person[i].age;
		if (!person[i].spec.empty()) cout << " " << person[i].spec << endl;
		else cout << endl;
	}

	return 0;
}