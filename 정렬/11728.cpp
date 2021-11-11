#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N, M;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> a, b;
	vector<int> s_result;
	int tmp;
	int a_idx = 0;
	int b_idx = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	while (true) {
		if (a_idx >= N) {
			for (int i = b_idx; i < M; i++) s_result.push_back(b[i]);
			break;
		}
		if (b_idx >= M) {
			for (int i = a_idx; i < N; i++) s_result.push_back(a[i]);
			break;
		}

		if (a[a_idx] < b[b_idx]) {
			s_result.push_back(a[a_idx]);
			a_idx++;
		}
		else if (a[a_idx] > b[b_idx]) {
			s_result.push_back(b[b_idx]);
			b_idx++;
		}
		else {
			s_result.push_back(a[a_idx]);
			s_result.push_back(b[b_idx]);
			a_idx++;
			b_idx++;
		}
	}

	for (int i = 0; i < s_result.size(); i++) {
		cout << s_result[i] << " ";
	}

	return 0;
}