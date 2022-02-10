#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(long long n) {
	if (n <= 1) return false;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int solution(int n, int k) {
	int answer = 0;
	vector<int> tmp;
	long long curN = 0;

	while (n > 0) {
		tmp.push_back(n % k);
		n /= k;
	}

	for (int i = tmp.size() - 1; i >= 0; i--) {
		if (tmp[i] == 0) {
			// n이 소수인지 검사
			if (isPrime(curN)) answer++;
			curN = 0;
			continue;
		}
		curN = 10 * curN + tmp[i];
	}
	if (isPrime(curN)) answer++;

	return answer;
}
