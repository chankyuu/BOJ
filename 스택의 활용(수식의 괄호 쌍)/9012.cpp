#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	string a;
	int result = 1;

	cin >> N;

	while (N--) {
		stack<char> tmp;
		cin >> a;

		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '(') tmp.push(a[i]);
			else {																	// ')' 인 경우
				if (tmp.size() != 0 && tmp.top() == '(') {					// 스택의 top이 '('인 경우 pop
					tmp.pop();
				}
				else {																// 스택의 top이 ')'인 경우 
					result = -1;
					break;
				}
			}
		}
		if (result == -1 || tmp.size() != 0) cout << "NO" << "\n";
		else cout << "YES" << "\n";
		result = 1;
	}

	return 0;
}