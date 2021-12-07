#include <bits/stdc++.h>

using namespace std;

int N;
int A[52];
int B[52];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mul = 0;

	cin >> N;

	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	
	sort(A, A + N, cmp);
	sort(B, B + N);

	for (int i = 0; i < N; i++) mul += A[i] * B[i];

	cout << mul;
	return 0;
}