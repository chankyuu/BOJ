#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	char c;

	cin >> N;

	while (N--) {
		list<char> key;
		auto cursor = key.end();
		string a;
		cin >> a;

		for (int i = 0; i < a.length(); i++) {
			c = a[i];

			switch (c) {
			case '<':
				if (cursor != key.begin()) cursor--;
				break;
			case '>':
				if (cursor != key.end()) cursor++;
				break;
			case '-':
				if (cursor != key.begin()) {
					cursor--;
					cursor = key.erase(cursor);
				}
				break;
			default:
				key.insert(cursor, c);
				break;
			}
		}
		for (auto i : key) cout << i;
		cout << "\n";
	}

	return 0;
}