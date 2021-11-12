//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N;
//int num[2000002];
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie();
//	cin >> N;
//	int a;
//	for (int i = 0; i < N; i++) {
//		cin >> a;
//		if(a >= 0) num[a]++;
//		else num[1000000 + (-1 * a)]++;
//	}
//	int i = 2000000;
//	while (i > 1000000) {
//		while (true) {
//			if (num[i] > 0) {
//				cout << (i - 1000000) * -1 << "\n";
//				num[i] -= 1;
//			}
//			else {
//				i--;
//				break;
//			}
//		}
//	}
//	i = 0;
//	while (i <= 1000000) {
//		while (true) {
//			if (num[i] > 0) {
//				cout << i << "\n";
//				num[i] -= 1;
//			}
//			else {
//				i++;
//				break;
//			}
//		}
//	}
//	return 0;
//}