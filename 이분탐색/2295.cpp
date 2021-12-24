#include <bits/stdc++.h>

using namespace std;

int N;
int num[1002];
vector<int> twoSum;

int threeSum() {
	for(int i = N - 1; i > 0; i--)
		for (int j = 0; j < i; j++) {
			if (binary_search(twoSum.begin(), twoSum.end(), num[i] - num[j]))
				return num[i];
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	
	sort(num, num + N);

	for (int i = 0; i < N; i++) 
		for(int j = i ; j < N; j++) twoSum.push_back(num[i] + num[j]);
	
	sort(twoSum.begin(), twoSum.end());

	cout << threeSum();
	
	return 0;
}