//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N;
//string serial[52];
//
//// a가 b보다 앞에 와야될때만 true 반환
//bool cmp(string a, string b) {
//	if (a.length() != b.length()) return a.length() < b.length();
//	else {
//		int cnt1 = 0;
//		int cnt2 = 0;
//		for (int i = 0; i < a.length(); i++) {
//			if ('0' <= a[i] && a[i] <= '9') cnt1 += a[i] - '0';
//		}
//		for (int i = 0; i < b.length(); i++) {
//			if ('0' <= b[i] && b[i] <= '9') cnt2 += b[i] - '0';
//		}
//		if(cnt1 != cnt2) return cnt1 < cnt2;
//		else {
//			for (int i = 0; i < a.length(); i++) {
//				if (a[i] != b[i]) return a[i] < b[i];
//			}
//		}
//	}
//
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie();
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string tmp;
//		cin >> tmp;
//		serial[i] = tmp;
//	}
//	sort(serial, serial + N, cmp);
//	for (int i = 0; i < N; i++) cout << serial[i] << "\n";
//	return 0;
//}