#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

int pop() {
	if (head == tail) return -1;
	else return dat[head++];
}

int front() {
	if (tail == head) return -1;
	else return dat[head];
}

int back() {
	if (tail == head) return -1;
	else return dat[tail - 1];
}

int size() {
	return tail - head;
}

int empty() {
	if (head == tail) return 1;
	else return 0;
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
		else if (tmp == "front") {
			cout << front() << "\n";
		}
		else if (tmp == "back") {
			cout << back() << "\n";
		}
		else if (tmp == "size") {
			cout << size() << "\n";
		}
		else if (tmp == "empty") {
			cout << empty() << "\n";
		}
		else if (tmp == "pop") {
			cout << pop() << "\n";
		}
	}
	return 0;
}