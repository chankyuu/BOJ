#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	list<int> circle;

	int N;
	int K;
	int count = 0;

	cin >> N;
	cin >> K;

	for (int i = 1; i <= N; i++) {
		circle.push_back(i);
	}
	list<int>::iterator cursor = circle.begin();

	cout << "<";
	while (true) {
		if (circle.size() == 0) break;
		else {
			for (int i = 1; i < K; i++) {
				if (++cursor == circle.end()) cursor = circle.begin();
			}
			if (circle.size() == 1) cout << *cursor;
			else cout << *cursor << ", ";

			cursor = circle.erase(cursor);
			if (cursor == circle.end()) cursor = circle.begin();
		}
	}
	cout << ">";

	return 0;
}