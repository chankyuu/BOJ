#include <bits/stdc++.h>

using namespace std;

int N;
int desk[100002];

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int maxW = 0;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> desk[i];

	sort(desk, desk + N, cmp);
	
	// N개의 로프를 선택할 때, 들 수 있는 최대 중량 sort[N] * N
	for (int i = N - 1; i >= 0; i--) {
		maxW = max(maxW, desk[i] * (i + 1));
	}
	cout << maxW;
	return 0;
}