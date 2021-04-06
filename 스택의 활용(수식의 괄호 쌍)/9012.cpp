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
			else {																	// ')' �� ���
				if (tmp.size() != 0 && tmp.top() == '(') {					// ������ top�� '('�� ��� pop
					tmp.pop();
				}
				else {																// ������ top�� ')'�� ��� 
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