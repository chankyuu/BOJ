#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	int k = 1;

	while (true) {
		stack<char> tmp;
		int op = 0;

		cin >> a;

		if (a.find("-") != string::npos) break;
		else {
			for (int i = 0; i < a.length(); i++) {
				if (a[i] == '{') tmp.push(a[i]);
				else {
					if (tmp.empty() || tmp.top() != '{') tmp.push(a[i]);
					else tmp.pop();
				}
			}
		}

		while (!tmp.empty()) {
			char c = tmp.top();
			tmp.pop();
			if (tmp.top() == c) op++;
			else op += 2;
			tmp.pop();
		}
		cout << k++ << ". " << op << "\n";
	}

	return 0;
}