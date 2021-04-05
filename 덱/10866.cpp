#include <bits/stdc++.h>
using namespace std;

int main(void) {
	deque<int> d;
	int N;
	string a;
	int num;

	cin >> N;

	while (N--) {
		cin >> a;

		if (a == "push_front") {
			cin >> num;
			d.push_front(num);
		}
		else if (a == "push_back") {
			cin >> num;
			d.push_back(num);
		}
		else if (a == "pop_front") {
			if (d.size() != 0) {
				cout << d.front() << "\n";
				d.pop_front();
			}
			else cout << "-1" << "\n";
		}
		else if (a == "pop_back") {
			if (d.size() != 0) {
				cout << d.back() << "\n";
				d.pop_back();
			}
			else cout << "-1" << "\n";
		}
		else if (a == "size") {
			cout << d.size() << "\n";
		}
		else if (a == "empty") {
			if (d.size() == 0) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (a == "front") {
			if (d.size() == 0) cout << "-1" << "\n";
			else cout << d.front() << "\n";
		}
		else {
			if (d.size() == 0) cout << "-1" << "\n";
			else cout << d.back() << "\n";
		}
	}


	return 0;
}