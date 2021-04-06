#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string a;
	stack<int> tmp;
	cin >> a;
	int result = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(') tmp.push(1);
		else if (a[i] == ')') {
			if (tmp.empty()) {
				continue;
			}
			else {
				tmp.pop();
				if (a[i - 1] == '(') {
					result += tmp.size();
				}
				else result++;
			}
		}
	}
	cout << result;

	return 0;
}