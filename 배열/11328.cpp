#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string a;
	string b;
	int n1['z' - 'a' + 1] = { 0 };
	int n2['z' - 'a' + 1] = { 0 };
	int N;
	int check;

	cin >> N;

	while (N--) {
		fill(n1, n1 + ('z' - 'a' + 1), 0);
		fill(n2, n2 + ('z' - 'a' + 1), 0);

		check = 1;

		cin >> a;
		cin >> b;

		if (a.length() != b.length()) cout << "Impossible" << "\n";
		else {
			for (int i = 0; i < a.length(); i++) {
				n1[int(a[i] - 'a')]++;
				n2[int(b[i] - 'a')]++;
			}
			for (int i = 0; i < ('z' - 'a') + 1; i++) {
				if (n1[i] != n2[i]) {
					cout << "Impossible" << "\n";
					check = -1;
					break;
				}
				else continue;
			}
			if (check != -1) cout << "Possible" << "\n";
		}
	}

	return 0;
}
