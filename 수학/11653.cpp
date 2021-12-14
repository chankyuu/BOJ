#include <bits/stdc++.h>

using namespace std;

int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i = 2;
	cin >> N;

	while (N != 1) {
		if (N % i == 0) {
			N = N / i;
			cout << i << "\n";
			continue;
		}
		i++;
	}
	return 0;
}