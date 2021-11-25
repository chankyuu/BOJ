#include <bits/stdc++.h>

using namespace std;

int N, M;
int S, E;
int Num[100002];
int D[100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N >> M;

	for (int i = 1; i <= N; i++) cin >> Num[i];

	// D[i] = 0~i까지의 합
	D[0] = 0;

	for (int i = 1; i <= N; i++) {
		D[i] = D[i - 1] + Num[i];
	}
	for (int cnt = 0; cnt < M; cnt++) {
		cin >> S >> E;

		cout << D[E] - D[S - 1] << "\n";
	}

	return 0;
}