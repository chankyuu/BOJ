#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int num;
	int a;

	int arr[201] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a;
		arr[a + 100]++;
	}

	cin >> num;
	cout << arr[num + 100];

	return 0;
}