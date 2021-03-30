#include <iostream>
#include <string>

using namespace std;

int main() {
	int A, B, C;
	long long R;
	int arr[10] = { 0 };

	cin >> A >> B >> C;

	R = A * B * C;

	string tmp = to_string(R);

	for (int i = 0; i < tmp.length(); i++) {
		arr[tmp[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) cout << arr[i] << "\n";

	return 0;
}