//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N, M;
//int num[20000002];
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int tmp;
//		cin >> tmp;
//		num[tmp + 10000000]++;
//	}
//	
//	cin >> M;
//	while (M--) {
//		int tmp;
//		cin >> tmp;
//		cout << num[tmp + 10000000] << " ";
//	}
//	return 0;
//}

// 이분탐색의 방법
#include <bits/stdc++.h>

using namespace std;

int N, M;
int num[500002];

int check(int tmp) {
	int s = 0;
	int e = N;
	int s_index = 0;
	int e_index = 0;

	while (s < e) {
		int mid = (s + e) / 2;
		if (num[mid] >= tmp) e = mid;
		else s = mid + 1;
	}
	s_index = s;

	s = 0;
	e = N;
	while (s < e) {
		int mid = (s + e) / 2;
		if (num[mid] > tmp) e = mid;
		else s = mid + 1;
	}
	e_index = s;

	return e_index - s_index;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];

	sort(num, num + N);
	cin >> M;
	while (M--) {
		int tmp;
		cin >> tmp;
		cout << check(tmp) << " ";
	}
	return 0;
}