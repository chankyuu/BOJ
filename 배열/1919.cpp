#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	int tmp1[26] = { 0 };
	int tmp2[26] = { 0 };
	int result = 0;

	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		tmp1[a[i] - 'a']++;
	}
	for (int i = 0; i < b.length(); i++) {
		tmp2[b[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		result += abs(tmp1[i] - tmp2[i]);
	}

	cout << result;

	return 0;
}