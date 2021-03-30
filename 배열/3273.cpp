#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, x;
	vector<int> tmp;
	int result = 0;
	int n;
	int head = 0;

	cin >> N;

	int end = N - 1;

	while (N--) {
		cin >> n;
		tmp.push_back(n);
	}

	sort(tmp.begin(), tmp.end());
	cin >> x;

	while (head < end) {
		int sum = tmp[head] + tmp[end];
		if (sum > x) end--;
		else if (sum < x) head++;
		else if (sum == x) {
			result++;
			head++;
			end--;
		}
	}
	cout << result;

	return 0;
}