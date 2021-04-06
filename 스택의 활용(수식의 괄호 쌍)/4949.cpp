#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string a;
	int check = 1;
	int count = 0;

	while (true) {
		stack<char> tmp;
		getline(cin, a);
		if (a == ".") break;
		else {
			for (int i = 0; i < a.length(); i++) {
				if (a[i] == '(' || a[i] == '[') tmp.push(a[i]);
				if (a[i] == ')') {
					if (tmp.size() != 0 && tmp.top() == '(') tmp.pop();
					else {
						check = -1;
						cout << "no" << "\n";
						count = 1;
						break;
					}
				}
				else if (a[i] == ']') {
					if (tmp.size() != 0 && tmp.top() == '[') tmp.pop();
					else {
						check = -1;
						cout << "no" << "\n";
						count = 1;
						break;
					}
				}
			}
			if (check != -1 && tmp.size() == 0) {
				cout << "yes" << "\n";
				count = 1;
			}
			if (count < 1) cout << "no" << "\n";
			check = 1;
			count = 0;
		}
	}
	return 0;
}