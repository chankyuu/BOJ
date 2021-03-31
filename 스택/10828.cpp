#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
	dat[pos++] = x;
}

void pop() {
	if (pos != 0) cout << dat[--pos] << "\n";
	else cout << -1 << "\n";
}

int top() {
	if (pos != 0) return dat[pos - 1];
	else return -1;
}

int size() {
	return pos;
}

int empty() {
	if (pos > 0) return 0;
	else return 1;
}

int main(void) {
	int N;
	string tmp;
	int num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == "push") {
			cin >> num;
			push(num);
		}
		else if (tmp == "top") {
			cout << top() << "\n";
		}
		else if (tmp == "size") {
			cout << size() << "\n";
		}
		else if (tmp == "pop") {
			pop();
		}
		else {
			cout << empty() << "\n";
		}
	}
	return 0;
}